#include <linux/cdev.h>
#include <linux/module.h>
#include <linux/init.h>
#include <linux/moduleparam.h>

#include <linux/kernel.h>
#include <linux/proc_fs.h>
#include <linux/slab.h>
#include <linux/fs.h>
#include <linux/errno.h>
#include <linux/types.h>
#include <linux/fcntl.h>
#include <linux/seq_file.h>
#include <linux/uaccess.h>
#include <linux/ioctl.h>
#include <asm/uaccess.h>
#include "dev_fifo_head.h"

//指定的主设备号
#define MAJOR_NUM 250 

//自己的字符设备
struct mycdev 
{
    int len;
    unsigned char buffer[50];
    struct cdev cdev;
};

MODULE_LICENSE("GPL");

//设备号
static dev_t dev_num = {0};

//全局gcd 
struct mycdev *gcd;

//设备类
struct class *cls;

//获得用户传递的数据，根据它来决定注册的设备个数
static int ndevices = 1;
module_param(ndevices, int, 0644);
MODULE_PARM_DESC(ndevices, "The number of devices for register.\n");


//打开设备
static int dev_fifo_open(struct inode *inode, struct file *file)
{
    struct mycdev *cd;
    
    printk("dev_fifo_open success!\n");
    
    //用struct file的文件私有数据指针保存struct mycdev结构体指针
    cd = container_of(inode->i_cdev,struct mycdev,cdev);
    file->private_data = cd;
    
    return 0;
}

//读设备
static ssize_t dev_fifo_read(struct file *file, char __user *ubuf, size_t size, loff_t *ppos)
{
    int n;
    int ret;
    char *kbuf;
    struct mycdev *mycd = file->private_data;
    
    printk("read *ppos : %lld\n",*ppos);

    if(*ppos == mycd->len)
        return 0;

    //请求大大小 > buffer剩余的字节数 :读取实际记得字节数
    if(size > mycd->len - *ppos)
        n = mycd->len - *ppos;
    else 
        n = size;
    
    printk("n = %d\n",n);
    //从上一次文件位置指针的位置开始读取数据
    kbuf = mycd->buffer + *ppos;

    //拷贝数据到用户空间
    ret = copy_to_user(ubuf,kbuf, n);
    if(ret != 0)
        return -EFAULT;
    
    //更新文件位置指针的值
    *ppos += n;
    
    printk("dev_fifo_read success!\n");

    return n;
}

//写设备
static ssize_t dev_fifo_write(struct file *file, const char __user *ubuf, size_t size, loff_t *ppos)
{
    int n;
    int ret;
    char *kbuf;
    struct mycdev *mycd = file->private_data;

    printk("write *ppos : %lld\n",*ppos);
    
    //已经到达buffer尾部了
    if(*ppos == sizeof(mycd->buffer))
        return -1;

    //请求大大小 > buffer剩余的字节数(有多少空间就写多少数据)
    if(size > sizeof(mycd->buffer) - *ppos)
        n = sizeof(mycd->buffer) - *ppos;
    else 
        n = size;

    //从上一次文件位置指针的位置开始写入数据
    kbuf = mycd->buffer + *ppos;

    //拷贝数据到内核空间
    ret = copy_from_user(kbuf, ubuf, n);
    if(ret != 0)
        return -EFAULT;

    //更新文件位置指针的值
    *ppos += n;
    
    //更新dev_fifo.len 
    mycd->len += n;

    printk("dev_fifo_write success!\n");
    return n;
}

//linux 内核在2.6以后，已经废弃了ioctl函数指针结构，取而代之的是unlocked_ioctl
long dev_fifo_unlocked_ioctl(struct file *file, unsigned int cmd,
    unsigned long arg)
{
    int ret = 0;
    struct mycdev *mycd = file->private_data;
    
    switch(cmd)
    {
        case DEV_FIFO_CLEAN:
            printk("CMD:CLEAN\n");
            memset(mycd->buffer, 0, sizeof(mycd->buffer));
            break;

        case DEV_FIFO_SETVALUE:
            printk("CMD:SETVALUE\n");
            mycd->len = arg;
            break;

        case DEV_FIFO_GETVALUE:
            printk("CMD:GETVALUE\n");
            ret = put_user(mycd->len, (int *)arg);
            break;

        default:
            return -EFAULT;
    }

    return ret;
}


//设备操作函数接口
static const struct file_operations fifo_operations = {
    .owner = THIS_MODULE,
    .open = dev_fifo_open,
    .read = dev_fifo_read,
    .write = dev_fifo_write,
    .unlocked_ioctl = dev_fifo_unlocked_ioctl,
};


//模块入口
int __init dev_fifo_init(void)
{
    int i = 0;
    int n = 0;
    int ret;
    struct device *device;
    
    gcd = kzalloc(ndevices * sizeof(struct mycdev), GFP_KERNEL);
    if(!gcd){
        return -ENOMEM;
    }

    //设备号 : 主设备号(12bit) | 次设备号(20bit)
    dev_num = MKDEV(MAJOR_NUM, 0);

    //静态注册设备号
    ret = register_chrdev_region(dev_num,ndevices,"dev_fifo");
    if(ret < 0){

        //静态注册失败，进行动态注册设备号
        ret = alloc_chrdev_region(&dev_num,0,ndevices,"dev_fifo");
        if(ret < 0){
            printk("Fail to register_chrdev_region\n");
            goto err_register_chrdev_region;
        }
    }
    
    //创建设备类
    cls = class_create(THIS_MODULE, "dev_fifo");
    if(IS_ERR(cls)){
        ret = PTR_ERR(cls);
        goto err_class_create;
    }
    
    printk("ndevices : %d\n",ndevices);
    
    for(n = 0;n < ndevices;n ++)
    {
        //初始化字符设备
        cdev_init(&gcd[n].cdev,&fifo_operations);

        //添加设备到操作系统
        ret = cdev_add(&gcd[n].cdev,dev_num + n,1);
        if (ret < 0)
        {
            goto err_cdev_add;
        }
        //导出设备信息到用户空间(/sys/class/类名/设备名)
        device = device_create(cls,NULL,dev_num + n,NULL,"dev_fifo%d",n);
        if(IS_ERR(device)){
            ret = PTR_ERR(device);
            printk("Fail to device_create\n");
            goto err_device_create;    
        }
    }
    printk("Register dev_fito to system,ok!\n");

    
    return 0;

err_device_create:
    //将已经导出的设备信息除去
    for(i = 0;i < n;i ++)
    {
        device_destroy(cls,dev_num + i);    
    }

err_cdev_add:
    //将已经添加的全部除去
    for(i = 0;i < n;i ++)
    {
        cdev_del(&gcd[i].cdev);
    }

err_class_create:
    unregister_chrdev_region(dev_num, ndevices);

err_register_chrdev_region:
    return ret;

}

void __exit dev_fifo_exit(void)
{
    int i;

    //删除sysfs文件系统中的设备
    for(i = 0;i < ndevices;i ++)
    {
        device_destroy(cls,dev_num + i);    
    }

    //删除系统中的设备类
    class_destroy(cls);
 
    //从系统中删除添加的字符设备
    for(i = 0;i < ndevices;i ++)
    {
        cdev_del(&gcd[i].cdev);
    }
    
    //释放申请的设备号
    unregister_chrdev_region(dev_num, ndevices);

    return;
}
module_init(dev_fifo_init);
module_exit(dev_fifo_exit);

