#include <linux/init.h>
#include <linux/module.h>
#include <linux/moduleparam.h>
//#include<linux/config.h>

#include <linux/kernel.h>/*printk()*/
#include <linux/sched.h>

MODULE_LICENSE("GPL");

static int __init call_usermodehelper_init(void)
{
	int ret = -1;
	char path[] = "/bin/mkdir";
	char *argv[] = {path, "-p", "/home/tester/new/new_dir", NULL};
	char *envp[] = {NULL};
	ret = call_usermodehelper(path, argv, envp, UMH_WAIT_PROC);
	return 0;	
}	

static void __exit call_usermodehelper_exit(void)
{
	int ret = -1;
	char path[] = "/bin/rm";
	char *argv[] = {path, "-r", "/home/tester/new", NULL};
	char *envp[] = {NULL};

	printk("call_usermodhelper module is starting..!\n");
	ret = call_usermodehelper(path, argv, envp, UMH_WAIT_PROC);	
	printk("ret=%d\n", ret);
}

module_init(call_usermodehelper_init);
module_exit(call_usermodehelper_exit);
