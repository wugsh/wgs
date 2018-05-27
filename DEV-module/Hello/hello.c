/*************************************************************************
	> File Name: hello.c
	> Author: 
	> Mail: 
	> Created Time: 2017年11月27日 星期一 20时55分00秒
 ************************************************************************/

#include <linux/init.h>
#include <linux/module.h>

MODULE_LICENSE("Dual BSD/GPL");

static char *name = "tomorrow";
static void __init name_init(void)
{
    printk("Hello world~\n");
    printk("Hello %s\n", name);
}

static void __exit name_exit(void)
{
    printk(KERN_INFO"Name module exit\n");
}

module_init(name_init);
module_exit(name_exit);
module_param(name, charp, S_IRUGO);
