/*************************************************************************
	> File Name: fifodev.c
	> Author: ma6174
	> Mail: ma6174@163.com 
	> Created Time: 2016年04月22日 星期五 21时04分54秒
 ************************************************************************/

#include <linux/init.h>
#include <linux/module.h>
#include <linux/cdev.h>
#include <linux/fs.h>

#define MAJOR_NUM 168

struct mycdev
{
	unsigned char buffer[50];
	struct cdev cdev;
}dev_fifo;

MODULE_LICENSE("GPL");

static int dev_fifo_open(struct inode *inode, struct file *file)
{
	printk("dev_fifo_open success!\n");
	return 0;
}

static ssize_t dev_fifo_read(struct file *file, char __user *buf, size_t size, loff_t *ppos)
{
	printk("dev_fifo_read success!\n");
	return 0;
}

static ssize_t dev_fifo_write(struct file *file, const char __user *buf, size_t size, loff_t *ppos)
{
	printk("dev_fifo_write success!\n");
	return size;
}

static const struct file_operations fifo_operations = {
	.owner = THIS_MODULE,
	.open = dev_fifo_open,
	.read = dev_fifo_read,
	.write = dev_fifo_write,
};

int __init dev_fifo_init(void)
{
	int ret;
	dev_t dev_num;

	cdev_init(&dev_fifo.cdev, &fifo_operations);
	
	dev_num = MKDEV(MAJOR_NUM, 0);

	if((ret = register_chrdev_region(dev_num, 2, "dev_fifo") < 0))
	{
		ret = alloc_chrdev_region(&dev_num, 0, 2, "dev_fifo");
		if(ret < 0)
		{
			printk("Fail to register_chrdev_region\n");
		    return -EIO;
		}
	}
	
	ret = cdev_add(&dev_fifo.cdev, dev_num, 1);

	if (ret < 0)
	{
			printk("Fall to cdev_add\n");
//			goto unregister_chrdev_region;
			return 0;
	}
	printk("Register dev_fifo to system ok!\n");
	return -1;
}

void __exit dev_fifo_exit(void)
{
	cdev_del(&dev_fifo.cdev);
	unregister_chrdev_region(MKDEV(MAJOR_NUM, 0), 1);
}

module_init(dev_fifo_init);
module_exit(dev_fifo_exit);



