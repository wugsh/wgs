    /*myirq.c */
#include <linux/module.h>
#include <linux/init.h>
#include <linux/interrupt.h>
#include <linux/jiffies.h>
#include <linux/netdevice.h>
static int irq;
static char *interface;

module_param(interface, charp, 0644);
module_param(irq, int, 0644);

    //static irq_handler_t myinterrupt(int irq, void *dev_id, struct pt_regs *regs)  

static irqreturn_t myinterrupt(int irq, void *dev_id)
{
    static int mycount = 0;
    static long mytime = 0;
    struct net_device *dev = (struct net_device*) dev_id;
    
    if (mycount == 0) {
		mytime = jiffies;
    }
    //count the interval between two irqs  
    if (mycount < 10) {
		mytime = jiffies - mytime;
		printk("Interrupt number %d — intterval(jiffies) %ld  — jiffies:%ld \n",irq, mytime, jiffies);
		mytime = jiffies;
	    printk("Interrupt on %s —–%d \n",dev->name, dev->irq);  

    }
    printk("jiffies = %ld mytime = %ld  mycount = %d\n", jiffies, mytime, mycount);
    mycount++;
    return IRQ_NONE;
}

static int __init myirqtest_init(void)
{
    printk("My module worked!\n");
    //regist irq  
    //if (request_irq(irq, &myinterrupt, SA_SHIRQ, interface, &irq)) {	//early than 2.6.23  
	if (request_irq(irq,myinterrupt,IRQF_SHARED,interface,&irq)) { //later than 2.6.23  
		printk(KERN_ERR "myirqtest: cannot register IRQ %d\n", irq);
		return -EIO;
    }
    printk("%s Request on IRQ %d succeeded\n", interface, irq);

    return 0;
}

static void __exit myirqtest_exit(void)
{
    printk("Unloading my module.\n");
    free_irq(irq, &irq);	//release irq @irq: 硬件中断号 @&irq:驱动身份
    printk("Freeing IRQ %d\n", irq); 

    return;
}

module_init(myirqtest_init);
module_exit(myirqtest_exit);

MODULE_AUTHOR("Gaosheng Wu");
MODULE_LICENSE("GPL");
