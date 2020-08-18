from apscheduler.schedulers.background import BackgroundScheduler, BlockingScheduler
from apscheduler.jobstores.redis import RedisJobStore
from apscheduler.jobstores.sqlalchemy import SQLAlchemyJobStore
from apscheduler.executors.pool import ThreadPoolExecutor, ProcessPoolExecutor


def print_args(*args):
    """
    要定时执行的函数
    :param args: 参数
    :return: None
    """
    for arg in args:
        print(arg)


# 执行器  常用的就线程池和进程池两种
thread_pool = ThreadPoolExecutor(30)
process_pool = ProcessPoolExecutor(5)
executors = {
    'thread': thread_pool,
    'process': process_pool
}

# 存储器 默认使用内存,对定时任务丢失什么的不敏感,对定时任务执行要求低
redis_store = RedisJobStore(host='172.16.120.120', port='6379')
sqlite_store = SQLAlchemyJobStore(url='sqlite:///jobs.sqlite')
jobstores = {
    'redis': redis_store,
    'default': sqlite_store
}
# 删除被持久化的定时任务 redis_store.remove_all_jobs()


# 调度器
# 调度器配置
job_defaults = {
    'coalesce': False,
    'max_instances': 5,
    'misfire_grace_time': 60
}
# coalesce：当由于某种原因导致某个job积攒了好几次没有实际运行（比如说系统挂了5分钟后恢复，有一个任务是每分钟跑一次的，按道理说这5分钟内本来是“计划”运行5次的，但实际没有执行），如果coalesce为True，下次这个job被submit给executor时，只会执行1次，也就是最后这次，如果为False，那么会执行5次（不一定，因为还有其他条件，看后面misfire_grace_time的解释）
# max_instance: 就是说同一个job同一时间最多有几个实例再跑，比如一个耗时10分钟的job，被指定每分钟运行1次，如果我们max_instance值为5，那么在第6~10分钟上，新的运行实例不会被执行，因为已经有5个实例在跑了
# misfire_grace_time：设想和上述coalesce类似的场景，如果一个job本来14:00有一次执行，但是由于某种原因没有被调度上，现在14:01了，这个14:00的运行实例被提交时，会检查它预订运行的时间和当下时间的差值（这里是1分钟），大于我们设置的30秒限制，那么这个运行实例不会被执行。

# scheduler = BlockingScheduler(jobstores=jobstores, executors=executors, job_defaults=job_defaults, daemonic=False)  # 实例化定时任务调度对象(阻塞方式)
scheduler = BackgroundScheduler(jobstores=jobstores, executors=executors,
                                job_defaults=job_defaults, daemonic=False)  # 实例化定时任务调度对象(非阻塞方式)
scheduler.add_job(id='my_job_id1', jobstore='redis', executor='processpool', func=print_args, args=[
                  "Hello,World!"], trigger='date', run_date='2018-06-18 12:56:00')  # 表示在2018-06-18 12:56:00执行


# 触发器
# 三种执行方式 trigger='date' trigger='interval' trigger='cron'
# 1.date 定时调度 默认 指定时间执行一次
scheduler.add_job(func=print_args, args=[
                  "Hello,World!"], trigger='date', run_date='2018-06-18 12:56:00')  # 表示在2018-06-18 12:56:00执行
# 2.interval 间隔调度 指定时间间隔重复执行
scheduler.add_job(func=print_args, args=['a', 'b', 'c'], trigger='interval',
                  days=3, hours=17, minutes=19, seconds=7)  # 表示每隔3天17时19分07秒执行一次任务
scheduler.add_job(func=print_args, args=[
                  'a', 'b', 'c'], trigger='interval', hours=17, minutes=19, seconds=7)  # 表示每隔17时19分07秒执行一次任务
scheduler.add_job(func=print_args, args=[
                  'a', 'b', 'c'], trigger='interval', minutes=19, seconds=7)  # 表示每隔19分07秒执行一次任务
scheduler.add_job(func=print_args, args=[
                  'a', 'b', 'c'], trigger='interval', minutes=19)  # 表示每隔19分执行一次任务
scheduler.add_job(func=print_args, args=[
                  'a', 'b', 'c'], trigger='interval', seconds=1)  # 表示每秒执行一次任务
scheduler.add_job(func=print_args, args=[
                  'a', 'b', 'c'], trigger='interval', seconds=0.5)  # 表示每500毫秒执行一次任务
# 3. cron 定时调度（指定时刻执行）
# [参数取值范围]
# year (int|str) – 4-digit year -（表示四位数的年份，如2008年）
# month (int|str) – month (1-12) -（表示取值范围为1-12月）
# day  (int|str) – day of the (1-31) -（表示取值范围为1-31日）
# week (int|str) – ISO week (1-53) -（格里历2006年12月31日可以写成2006年-W52-7（扩展形式）或2006W527（紧凑形式））
# day_of_week (int|str) – number or name of weekday (0-6 or mon,tue,wed,thu,fri,sat,sun) - （表示一周中的第几天，既可以用0-6表示也可以用其英语缩写表示）
# hour (int|str) – hour (0-23) - （表示取值范围为0-23时）
# minute (int|str) – minute (0-59) - （表示取值范围为0-59分）
# second (int|str) – second (0-59) - （表示取值范围为0-59秒）
# start_date (datetime|str) – earliest possible date/time to trigger on (inclusive) - （表示开始时间）
# end_date (datetime|str) – latest possible date/time to trigger on (inclusive) - （表示结束时间）
# timezone (datetime.tzinfo|str) – time zone to use for the date/time calculations (defaults to scheduler timezone) -（表示时区取值）
# [参数取值格式]
# *            any    Fire on every value      如: day='*' 即,每天执行
# */a        any    Fire every a values, starting from the minimum  如: hour='*/2' 即,每两小时执行
# a-b        any    Fire on any value within the a-b range (a must be smaller than b)   如: minute='6-8,21-23' 即,6-8点和21-23点执行
# a-b/c        any    Fire every c values within the a-b range 如: minute='9-21/2' 即,9点-21点之间每两小时执行
# xth y        day    Fire on the x -th occurrence of weekday y within the month
# last x    day    Fire on the last occurrence of weekday x within the month
# last        day    Fire on the last day within the month
# x,y,z        any    Fire on any matching expression; can combine any number of any of the above expressions # 表达式之间用逗号进行分隔
scheduler.add_job(func=print_args, args=['a', 'b', 'c'], trigger='cron', year=2018, month=3, day=21, hour=21, minute=19,
                  second=8)  # 表示2018年3月21日21时19分08秒执行
scheduler.add_job(func=print_args, args=['a', 'b', 'c'], trigger='cron', day_of_week='mon-fri', hour=5, minute=30,
                  start_date='2016-06-06', end_date='2018-08-08')  # 表示周一到周五的5点半执行,有效日期是2016-06-06 00:00:00 至 2018-08-08 00:00:00
# 表示每10秒执行该程序一次，相当于interval 间隔调度中seconds = 10
scheduler.add_job(func=print_args, args=['a', 'b', 'c'], trigger='cron', second='*/10')


scheduler.start()  # 开始调度
scheduler.shutdown()  # 停止调度
scheduler.pause_job(job_id='my_job_id')  # 暂停指定JOB调度
scheduler.resume_job(job_id='my_job_id')  # 恢复指定JOB调度
scheduler.pause()  # 暂停调度
scheduler.resume()  # 恢复调度
