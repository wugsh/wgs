import time
from apscheduler.schedulers.blocking import BlockingScheduler


def my_job():
    print (time.strftime('%Y-%m-%d %H:%M:%S', time.localtime(time.time())))
    time.sleep(10)
    


sched = BlockingScheduler()
sched.add_job(my_job, 'interval', seconds=11, id='my_job_id')
print(sched.get_jobs())
print(sched.get_job(job_id='my_job_id'))
#sched.remove_job('my_job_id')
print(sched.get_jobs())
sched.start()
time.sleep(10)
sched.shutdown(wait=False)
