#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>		// for exit
#include <signal.h>		// for sigaction
#include <syslog.h>		// for syslog
#include <sys/stat.h>	// for umask
#include <sys/resource.h>

void daemonize (const char *cmd)
{
	int					i, fd0, fd1, fd2;
	pid_t				pid;
	struct rlimit		rl;
	struct sigaction	sa;

	// 更改文件权限屏蔽字 => 不屏蔽
	umask(0);

	if (getrlimit(RLIMIT_NOFILE, &rl) < 0)
	{
		perror("getrlimit");
		exit(-1);
	}

	if ((pid = fork()) < 0)
	{
		perror("fork");
		exit(-1);
	}
	else if (pid != 0)
	{
		// 父进程退出
		exit(0);
	}

	// 1. 脱离控制终端
	// 2. 成为组长进程
	// 3. 成为会话组首个进程
	setsid();

	// 忽略 SIGHUP 信号
	// 当终端退出，会发送该信号给会话组长进程，默认处理方式为退出
	sa.sa_handler = SIG_IGN;
	sigemptyset(&sa.sa_mask);
	sa.sa_flags = 0;

	if (sigaction(SIGHUP, &sa, NULL) < 0)
	{
		perror("sigaction");
		exit(-1);
	}

	// 再次 fork 让守护进程不再担当会话组长，防止他重新打开终端
	if ((pid = fork()) < 0)
	{
		perror("fork");
		exit(-1);
	}
	if (pid != 0)
	{
		// 父进程退出
		printf("%d\n", pid);
		exit(0);
	}

	if (chdir("/") < 0)
	{
		perror("chdir");
		exit(-1);
	}
	
	// 关闭所有文件描述符
	if (rl.rlim_max == RLIM_INFINITY)
		rl.rlim_max = 1024;
	for (i=0; i<rl.rlim_max; ++i)
		close(i);

	// 重定向标准输入、标准输出、错误输出到 /dev/null
	fd0 = open("/dev/null", O_RDWR);
	fd1 = dup(0);
	fd2 = dup(0);

	openlog(cmd, LOG_CONS, LOG_DAEMON);
	if (fd0 != 0 || fd1 != 1 || fd2 != 2)
	{
		syslog(LOG_ERR, "unexpected file descriptors %d %d %d",
				fd0, fd1, fd2);
		exit(-1);
	}
	while (1)
	{
		// TODO
	}
}

int main (int argc, char *argv[])
{
	daemonize(argv[0]);
	return 0;
}
