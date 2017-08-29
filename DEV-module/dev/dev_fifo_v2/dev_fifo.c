#include <linux/init.h>
#include <linux/module.h>
#include <linux/cdev.h>
#include <linux/fs.h>
#include <linux/device.h>
#include <linux/slab.h>
#include <asm/uaccess.h>

//指定的主设备号
#define MAJOR_NUM  250 

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
struct class  *cls;

//打开设备
static int dev_fifo_open(struct inode *inode, struct file *file)
{	
	printk("dev_fifo_open success!\n");
		
	return 0;
}

//读设备
static ssize_t dev_fifo_read(struct file *file, char __user *ubuf, size_t size, loff_t *ppos)
{
	int n;
	int ret;
	char *kbuf;
	
	printk("read *ppos : %lld\n",*ppos);

	if(*ppos == gcd->len)
		return 0;

	//请求大大小 > buffer剩余的字节数 :读取实际记得字节数
	if(size > gcd->len - *ppos)
		n = gcd->len  - *ppos;
	else 
		n = size;
	
	printk("n = %d\n",n);
	//从上一次文件位置指针的位置开始读取数据
	kbuf = gcd->buffer + *ppos;

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

	printk("write *ppos : %lld\n",*ppos);
	
	//已经到达buffer尾部了
	if(*ppos == sizeof(gcd->buffer))
		return -1;

	//请求大大小 > buffer剩余的字节数(有多少空间就写多少数据)
	if(size > sizeof(gcd->buffer) - *ppos)
		n = sizeof(gcd->buffer) - *ppos;
	else 
		n = size;

	//从上一次文件位置指针的位置开始写入数据
	kbuf = gcd->buffer + *ppos;

	//拷贝数据到内核空间
	ret = copy_from_user(kbuf, ubuf, n);
	if(ret != 0)
		return -EFAULT;

	//更新文件位置指针的值
	*ppos += n;
	
	//更新dev_fifo.len 
	gcd->len += n;

	printk("dev_fifo_write success!\n");
	return n;
}

//设备操作函数接口
static const struct file_operations fifo_operations = {
	.owner = THIS_MODULE,
	.open  = dev_fifo_open,
	.read  = dev_fifo_read,
	.write = dev_fifo_write,
};


//模块入口
int __init dev_fifo_init(void)
{
	int ret;
	struct device *device;
	
	gcd = kzalloc(sizeof(struct mycdev), GFP_KERNEL);
	if(!gcd){
		return -ENOMEM;
	}

	//设备号 : 主设备号(12bit) | 次设备号(20bit)
	dev_num = MKDEV(MAJOR_NUM, 0);

	//静态注册设备号
	ret = register_chrdev_region(dev_num,1,"dev_fifo");
	if(ret < 0){

		//静态注册失败，进行动态注册设备号
		ret = alloc_chrdev_region(&dev_num,0,1,"dev_fifo");
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
	
	
	//初始化字符设备
	cdev_init(&gcd->cdev,&fifo_operations);

	//添加设备到操作系统
	ret = cdev_add(&gcd->cdev,dev_num,1);
	if (ret < 0)
	{
		goto  err_cdev_add;
	}
	//导出设备信息到用户空间(/sys/class/类名/设备名)
	device = device_create(cls,NULL,dev_num,NULL,"dev_fifo%d",0);
	if(IS_ERR(device)){
		ret = PTR_ERR(device);
		printk("Fail to device_create\n");
		goto err_device_create;	
	}
	printk("Register dev_fito to system,ok!\n");

	
	return 0;

err_device_create:
	cdev_del(&gcd->cdev);

err_cdev_add:
	class_destroy(cls);

err_class_create:
	unregister_chrdev_region(dev_num, 1);

err_register_chrdev_region:
	return ret;

}

void __exit dev_fifo_exit(void)
{
	//删除sysfs文件系统中的设备
	device_destroy(cls,dev_num );	

	//删除系统中的设备类
	class_destroy(cls);
 
	//从系统中删除添加的字符设备
	cdev_del(&gcd->cdev);
	
	//释放申请的设备号
	unregister_chrdev_region(dev_num, 1);

	return;
}


module_init(dev_fifo_init);
module_exit(dev_fifo_exit);
