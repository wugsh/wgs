/*************************************************************************
	> File Name: printpthread.c
	> Author: 
	> Mail: 
	> Created Time: 2017年11月27日 星期一 21时20分17秒
 ************************************************************************/

#include <linux/kernel.h>
#include <linux/module.h>
#include <linux/init.h>
#include <linux/sched.h>

static struct task_struct *pcurrent;

int print_current_task_info(void);
static int __init print_init(void)
{
    printk(KERN_INFO "print current task info\n");
    print_current_task_info();
    return 0;
}

static void __exit print_exit(void)
{
    printk(KERN_INFO "Finished\n");
}
int print_current_task_info(void)
{
    pcurrent = get_current();
    printk(KERN_INFO "Task state: %ld\n", current->state);
    printk(KERN_INFO "pid: %d\n", current->pid);
    printk(KERN_INFO "tgid: %d\n", current->tgid);
    printk(KERN_INFO "prio: %d\n", current->prio);
    return 0;
}

module_init(print_init);
module_exit(print_exit);
MODULE_LICENSE("GPL");
