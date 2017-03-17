#include <linux/module.h> //needed by all modules
#include <linux/kernel.h> //needed for KERN_INFO
#include <linux/sched.h> //defined struct task_struct
#include <linux/proc_fs.h> //create proc file
#include <linux/seq_file.h> //use seq_file

#define FILENAME "osexp" //defile proc file name

int myshow(struct seq_file *,void *); 
int myopen(struct inode *,struct file *);

/* custom the operations to the seq_file */
static const struct file_operations myops = {
        .owner = THIS_MODULE,
        .open = myopen,
        .read = seq_read,
        .release = single_release
};
/* do when open the seq file */
int myopen(struct inode *inode,struct file *file){
    single_open(file,myshow,NULL);//bind seq_file with myshow function
    return 0;
}
/* create proc file */
int init_proc(void){
    struct proc_dir_entry * myfile;
    myfile = proc_create(FILENAME,0444,NULL,&myops);//create proc file
    if(myfile == NULL) //deal with error
        return -ENOMEM;
    return 0;
}
/* remove proc file */
void remove_proc(void){
    remove_proc_entry(FILENAME,NULL);//remove proc file
    printk(KERN_INFO "[m] proc file:%s removed\n",FILENAME);//print debug message
}

/*description: output process's info to log */
int myshow(struct seq_file *file,void *v){
    int num_running = 0; //the number of process whose status is running
    int num_interruptible = 0; //the number of process whose status is interruptible
    int num_uninterruptible = 0; //the ... status is uninterruptible
    int num_zombie = 0; //the process exited with status zombie
    int num_stopped = 0; //the ... status is stopped
    int num_traced = 0; //the ... status is traced
    int num_dead = 0; //the process has deaded;
    int num_unknown = 0; //the process whose status is unknown

    int num_total = 0; //the total number of process

    int t_exit_state; //temp var to store task_struct.exit_state
    int t_state; //temp var to store task_struct.state
    struct task_struct *p; //pointer to task_struct
   
    //printk("[m] All processes' info:\n");//print boot info
    seq_printf(file,"[m] All processes' info:\n");
    for(p=&init_task;(p=next_task(p))!=&init_task;){ //go througn the linklist
        //printk(KERN_INFO "[m] Name:%s Pid:%d State:%ld ParName:%s\n",p->comm,p->pid,p->state,p->real_parent->comm); //print the process's info to log
        seq_printf(file,"[m] Name:%s Pid:%d State:%ld ParName:%s\n",p->comm,p->pid,p->state,p->real_parent->comm);
        num_total++; //total number of process plus one

        t_state = p->state; //put p->state to variable t_state
        t_exit_state = p->exit_state;//similar to above

        if(t_exit_state!=0){ //if the process has exited
            switch(t_exit_state){
                case EXIT_ZOMBIE://if the exit state is zombie
                    num_zombie++;//variable plus one
                    break; //break switch 
                case EXIT_DEAD://if the exit state is dead
                    num_dead++;//variable plus one
                    break;//break switch
                default: //other case
                    break;//break switch
            }
        }else{ // if the proess hasn't exited
            switch(t_state){
                case TASK_RUNNING://if the state is running
                    num_running++;//variable plus one
                    break;//break switch
                case TASK_INTERRUPTIBLE://state is interruptible
                    num_interruptible++;//variable plus one
                    break;//break switch
                case TASK_UNINTERRUPTIBLE://state is uninterruptible
                    num_uninterruptible++;//var + 1
                    break;//break switch
                case TASK_STOPPED://state is stopped
                    num_stopped++;//var +1
                    break;//break switch
                case TASK_TRACED://state is traced
                    num_traced++;//var +1
                    break;//break switch
                default://other case
                    num_unknown++;
                    break;
            }
        }
    }
    //below instruction is to print the statistics result in above code
    // printk(KERN_INFO "[m] total tasks: %10d\n",num_total);
    // printk(KERN_INFO "[m] TASK_RUNNING: %10d\n",num_running);
    // printk(KERN_INFO "[m] TASK_INTERRUPTIBLE: %10d\n",num_interruptible);
    // printk(KERN_INFO "[m] TASK_UNINTERRUPTIBLE: %10d\n",num_uninterruptible);
    // printk(KERN_INFO "[m] TASK_TRACED: %10d\n",num_stopped);
    // printk(KERN_INFO "[m] TASK_TRACED: %10d\n",num_stopped);
    // printk(KERN_INFO "[m] EXIT_ZOMBIE: %10d\n",num_zombie);
    // printk(KERN_INFO "[m] EXIT_DEAD: %10d\n",num_dead);
    // printk(KERN_INFO "[m] UNKNOWN: %10d\n",num_unknown);
    seq_printf(file,"[m] total tasks: %10d\n",num_total);
    seq_printf(file,"[m] TASK_RUNNING: %10d\n",num_running);
    seq_printf(file,"[m] TASK_INTERRUPTIBLE: %10d\n",num_interruptible);
    seq_printf(file,"[m] TASK_UNINTERRUPTIBLE: %10d\n",num_uninterruptible);
    seq_printf(file,"[m] TASK_TRACED: %10d\n",num_stopped);
    seq_printf(file,"[m] TASK_TRACED: %10d\n",num_stopped);
    seq_printf(file,"[m] EXIT_ZOMBIE: %10d\n",num_zombie);
    seq_printf(file,"[m] EXIT_DEAD: %10d\n",num_dead);
    seq_printf(file,"[m] UNKNOWN: %10d\n",num_unknown);

    return 0;
} 

int init_module(void){// init the kernel module
    printk(KERN_INFO "[m] exp_process started\n");//print start message
    return init_proc();//create proc file
}

void cleanup_module(void){ //clean up the resources when module finished
    remove_proc();//remove proc file
    printk(KERN_INFO "[m] exp_process finished\n");//print finish message
}

MODULE_LICENSE("GPL");//show that this code follow GUN General Public License