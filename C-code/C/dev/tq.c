/*************************************************************************
	> File Name: tq.c
	> Author: Wu GaoSHeng
	> Mail: wugsh15@lzu.edu.cn 
	> Created Time: 2016年09月18日 星期日 21时20分58秒
 ************************************************************************/

 #include <linux/init.h>
 #include <linux/module.h>
 #include <linux/cdev.h>
 #include <linux/fs.h>
 #include <linux/types.h>
 #include <linux/uaccess.h>
 #include <linux/device.h>
 #include <plat/gpio-cfg.h>
 #include <asm/gpio.h>

static int major;
/* 分配cdev */
struct cdev btn_cdev;

/* 记录按键值 */
static unsigned char key_value;

/* 2. 实现设备操作 */
/* 2.1 read*/
static ssize_t button_read(struct file *file, char __user *buf, size_t count, loff_t *offp)
{
    int status = 0;
    
    //1. 获取GPIO的状态
    status = gpio_get_value(S5PV210_GPH0(0));
    if (status == 1)
        key_value = 0X50;
    else
        key_value = 0x51;

    //2. 上报GPIO的状态
    copy_to_user(buf, &key_value,sizeof(key_value));

    return count;
}

/* 2.2 设备操作集合*/
static struct file_operations btn_fops = {
    .owner = THIS_MODULE;
    .read = button_read;
};

//设备类
static struct class *btn_cls;

/* 1.驱动初始化*/
static int __init button_init(void){
    dev_t dev_id;
/* 1.1 申请设备号*/
    if (major){
        //静态
        dev_id = MKDEV(major, 0);
        register_chrdev_region(dev_id, 1, "button");
    }else{
        //动态
        alloc_chardev_region(&dev_id, 0, 1, "button");
        major = MAJOR(dev_id);
    }
/* 1.2 初始化cdev*/
    cdev_init(&btn_cdev, &btn_fops);

/* 1.3 注册cdev*/
    cdev_add(&btn_cdev, dev_id, 1);

/* 1.4 自动创建设备节点*/
/* 1.4.1 创建设备类*/
    //sys/class/button
    btn_cls = class_create(THIS_MODULE, "button");
/* 1.4.2 创建设备节点*/
    device_create(btn_cls, NUL, dev_id, NUL, "button");

/*1.4 硬件初始化*/
    //申请GPIO资源
    gpio_request(S5PV210_GPH0(0), "GPH0_0");
    //配置输入
    gpio_direction_input(S5PV210_GPH0(0));

    return 0；
}

/*3. 驱动注销*/
static void __exit button_exit(void){
/*3.1 释放GPIO资源*/
    gpio_free(S5PV210_GPH0(0));

/*3.2 删除设备节点*/
    device_destory(btn_cls, MKDEV(major, 0));
    class_destory(btn_cls);

/*3.3 删除cdev*/
    cdev_del(&btn_cdev);

/*3.4 释放设备号*/
    unregister_chrdev_region(MKDEV(major, 0), 1);
}

module_init(button_init);
module_exit(button_exit);
MODULE_LICENSE("GPL v2");
