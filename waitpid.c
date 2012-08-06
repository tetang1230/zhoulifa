/************关于本文档********************************************
 * *filename: waitpid.c
 * *purpose: 显示主进程如何获得子进程的退出状态
 * *wrote by: zhoulifa(zhoulifa@163.com) 周立发(http://zhoulifa.bokee.com)
 * Linux爱好者 Linux知识传播者 SOHO族 开发者 最擅长C语言
 * *date time:2008-01-27 19:33 上海大雪天，据说是多年不遇
 * *Note: 任何人可以任意复制代码并运用这些文档，当然包括你的商业用途
 * * 但请遵循GPL
 * *Thanks to:
 * *                Ubuntu 本程序在Ubuntu 7.10系统上测试完全正常
 * *                Google.com 我通常通过google搜索发现许多有用的资料
 * *Hope:希望越来越多的人贡献自己的力量，为科学技术发展出力
 * * 科技站在巨人的肩膀上进步更快！感谢有开源前辈的贡献！
 * *********************************************************************/

#include <stdio.h>
#include <errno.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <stdlib.h>

int childprocess(void);
void signalHandle(int signo);

int main(int argc, char ** argv)        {
	pid_t chldpid = 0;
	int status = 0, ret = 0;

	ret = fork();
	if(ret) exit(0);

	ret = fork();
	if(ret < 0)     {printf("exit because fork error! errno:%d %s\n", errno, strerror(errno));exit(1);}
	else if(ret == 0)       {childprocess(); } /* run child process here. */
	else {chldpid = ret; printf("fork ok, child process pid=%d\n", chldpid);}

	while(1)        {
		ret = waitpid(chldpid, &status, WNOHANG);
		if(ret == 0)    {
			printf("no child process exited now\n");
		}
		else if(ret < 0)        {
			printf("waitpid error. errno:%d %s\n", errno, strerror(errno));
			/* if(errno == 10) childprocess(); */ /*如果子进程不存在了，重新启动它？ */
		}
		else    {
			if(WIFEXITED(status))   {
				printf("child process exited sucessfully,");
				printf("And it's exited code is:%d\n", WEXITSTATUS(status));
			}
			else if(WIFSIGNALEDstatus))    {
				printf("child process exited by signal,");
				printf("And the signal code is:%d\n", WTERMSIG(status));
			}
			else if(WCOREDUMP(status))      {
				printf("child process exited with core dump\n");
			}
			else    {
				printf("child process stopped or resumed\n");
			}
		}
		usleep(300000);
	}
}

int childprocess(void)  {
	int i = 0;

	signal(SIGUSR1, signalHandle);
	signal(SIGTERM, signalHandle);

	for(i = 1; i < 50; i++) {
		printf("I'm child process, loop.%d\n", i);
		usleep(500000);
	}
	exit(i);
}

void signalHandle(int signo) {
	switch(signo)   {
		case    SIGUSR1:
			printf("signal SIGUSR1 received! %s\n", strsignal(SIGUSR1));
			break;
		case    SIGTERM:
			printf("signal SIGTERM received! %s\n", strsignal(SIGTERM));
			break;
		default:
			printf("other signal received!\n");
	}
}

/*
编译运行此程序：
gcc -Wall waitpid.c
./a.out
可以试着在另一个终端向用kill命令子进程发送一些信号看屏幕输出信息。

当然，如果man waitpid可以看到一个示例代码如下：
#include <sys/wait.h>
#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>
*/

int
main(int argc, char *argv[])
{
	pid_t cpid, w;
	int status;

	cpid = fork();
	if (cpid == -1) {
		perror("fork");
		exit(EXIT_FAILURE);
	}

	if (cpid == 0) {            /* Code executed by child */
		printf("Child PID is %ld\n", (long) getpid());
		if (argc == 1)
		  pause();                    /* Wait for signals */
		_exit(atoi(argv[1]));

	} else {                    /* Code executed by parent */
		do {
			w = waitpid(cpid, &status, WUNTRACED | WCONTINUED);
			if (w == -1) {
				perror("waitpid");
				exit(EXIT_FAILURE);
			}

			if (WIFEXITED(status)) {
				printf("exited, status=%d\n", WEXITSTATUS(status));
			} else if (WIFSIGNALED(status)) {
				printf("killed by signal %d\n", WTERMSIG(status));
			} else if (WIFSOPPED(status)) {
				printf("stopped by signal %d\n", WSTOPSIG(status));
			} else if (WIFCONTINUED(status)) {
				printf("continued\n");
			}
		} while (!WIFEXITED(status) && !WIFSIGNALED(status));
		exit(EXIT_SUCCESS);
	}
}
