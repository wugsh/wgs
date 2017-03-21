/*
 * hritmer高精度定时器的interval由ktime_set(const long secs, const unsigned long nsecs)决定，可做到ns级。此处的例子为5ms interval：
*
* 如果在my_hrtimer_callback()里面直接返回HRTIMER_RESTART会导致立即重新进入my_hrtimer_callback()。这时shell对输入没有任何响应。
*
* 所以为了解决这个问题，创建了一个work queue，由my_hrtimer_callback() enqueue这个工作队列。在work queue的处理函数里面重启hrtimer。
*
但是这样带来的负面影响是进入hrtimer_callback和wq_func被调用之间有Linux系统调度引入的延迟，导致interval出现误差。经过实测，在ZC706缺省配置下，这个延迟大约是17.5us (hrtimer interval为5ms，每20秒计算一次interval误差)。
* */
#include <linux/kernel.h>  
#include <linux/module.h>  
#include <linux/hrtimer.h>  
#include <linux/ktime.h>  
MODULE_LICENSE("GPL");  
static struct hrtimer hr_timer;  
static struct work_struct wq_hrtimer;    
static ktime_t ktime;  
static unsigned int interval=5000; /* unit: us */  
struct timespec uptimeLast;  
static unsigned int count=0;  
#define COUNT_INTERVAL 4000  
unsigned long long diff_tv(struct timespec start, struct timespec end) {  
    return (end.tv_sec-start.tv_sec)*1000000000+(end.tv_nsec-start.tv_nsec);  
}  
enum hrtimer_restart my_hrtimer_callback( struct hrtimer *timer )  
{  
    schedule_work(&wq_hrtimer);   
    return HRTIMER_NORESTART;  
}  
static void wq_func_hrtimer(struct work_struct *work)  
{   
    struct timespec uptime;  
    hr_timer.function = my_hrtimer_callback;   
    ktime = ktime_set( interval/1000000, (interval%1000000)*1000 );  
    hrtimer_start(&hr_timer, ktime, HRTIMER_MODE_REL );  
    /* print time every COUNT_INTERVAL*interval second*/  
    if(count%COUNT_INTERVAL==0)   
    {  
        do_posix_clock_monotonic_gettime(&uptime);    
        printk(KERN_INFO"hrtimer:%9lu sec, %9lu ns, interval_delay=%lu ns\n",   
            (unsigned long) uptime.tv_sec, uptime.tv_nsec,  
            (unsigned long)(diff_tv(uptimeLast, uptime)-interval*1000*COUNT_INTERVAL) / COUNT_INTERVAL);   
        uptimeLast=uptime;  
    }  
    count++;  
}   
static int __init module_hrtimer_init( void )  
{  
    struct timespec uptime;   
    printk(KERN_INFO"HR Timer module installing\n");  
    hrtimer_init( &hr_timer, CLOCK_MONOTONIC, HRTIMER_MODE_REL ); //hrtimer定时器初始化 
    ktime = ktime_set( interval/1000000, (interval%1000000)*1000 );  
    hr_timer.function = my_hrtimer_callback;  
    hrtimer_start( &hr_timer, ktime, HRTIMER_MODE_REL );  
    do_posix_clock_monotonic_gettime(&uptime); //线程建立时间，用于比较看（定时器）此时的时间 
    uptimeLast = uptime;  
    printk(KERN_INFO"hrtimer:%9lu sec, %9lu ns\n", (unsigned long) uptime.tv_sec, uptime.tv_nsec);   
    INIT_WORK(&wq_hrtimer, wq_func_hrtimer); //初始化工作队列 
    return 0;  
}  
static void __exit module_hrtimer_exit( void )  
{  
    int ret;  
    ret = hrtimer_cancel( &hr_timer );  
    if (ret)   
        printk("The timer was still in use...\n");  
    printk("HR Timer module uninstalling\n");  
    return;  
}  
module_init(module_hrtimer_init);  
module_exit(module_hrtimer_exit);  
