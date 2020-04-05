import time


def unix_time(dt):
    """
    日期转时间戳
    """
    # 日期转成时间数组
    timeArray = time.strptime(str(dt), "%Y-%m-%d %H:%M:%S")
    # 时间数组转成时间戳
    timestamp = int(time.mktime(timeArray))
    return timestamp


def custom_time(timestamp):
    """
    时间戳转日期
    """
    # 时间戳转成loclatime
    time_local = time.localtime(int(timestamp))
    # localtime转成时间格式(2020-04-05 16:45:30)
    dt = time.strftime("%Y-%m-%d %H:%M:%S", time_local)
    return dt


if __name__ == '__main__':
    T1 = "1586046776"
    T2 = "2020-04-05 08:32:56"
    print(unix_time(T2))
    print(T1)
    print("*************")
    print(custom_time(T1))
    print(T2)    
