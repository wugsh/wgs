/*************************************************************************
	> File Name: myirq.c
	> Author: 
	> Mail: 
	> Created Time: 2017年03月16日 星期四 15时23分01秒
 ************************************************************************/

#include <linux/module.h>
#include <linux/init.h>
#include <linux/interrupt.h>

static int irq;
static char *interface;

module_param(interface, char, 0644);
module_param(irq, int, 0644);


static irqreturn_t myinterrupt(int irq, void *dev_i)
{
    static int mycount = 0;
    static long mytime = 0;
    struct net_device *dev = (struct net_device *) dev_id;
    
    if (mycount == 0)
        mytime = jiffies;
    if (mycount < 10){
        printk("interrupt number %d --- intterval(jiffies) %ld ---jiffies: %ld\n", irq, mytime, jiffies);
        mytime = jiffies;
        
    }   
    mycount++;
    return IRQ_NONE;
}

static int __init myirqtest_init(void)
{
    printk("My module worked!\n");
    
    if (request_irq(irq, &myinterrupt, SA_SHIRQ, interface, &irq)){
        printk(KERN_ERR"myirqtest:cannot register IRQ %d\n", irq);
        return -EIO;
    } 
    printk("%s Request on IRQ %d succeeded\n", interface, irq);

    return 0;
}

static void __exit myirqtest_exit(void)
{
    printk("Unloading my module\n");
    free_irq(irq, &irq);
    printk("Freeing IRQ %d\n",irq);
    return;
}

module_init(myirqtest_init);
module_exit(myirqtest_exit);

MODULE_AUTHOR("Helight.Xu");
MODULE_LICENSE("GPL");

