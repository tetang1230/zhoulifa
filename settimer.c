#include <signal.h>
#include <unistd.h>
#include <stdio.h>
#include <sys/time.h>
/************关于本文档********************************************
 * *filename: setitimer.c
 * *purpose: 显示了设置闹钟的方法
 * *wrote by: zhoulifa(zhoulifa@163.com) 周立发(http://zhoulifa.bokee.com)
 * Linux爱好者 Linux知识传播者 SOHO族 开发者 最擅长C语言
 * *date time:2008-01-26 2333 上海大雪天，据说是多年不遇
 * *Note: 任何人可以任意复制代码并运用这些文档，当然包括你的商业用途
 * * 但请遵循GPL
 * *Thanks to:
 * * Ubuntu 本程序在Ubuntu 7.10系统上测试完全正常
 * * Google.com 我通常通过google搜索发现许多有用的资料
 * *Hope:希望越来越多的人贡献自己的力量，为科学技术发展出力
 * * 科技站在巨人的肩膀上进步更快！感谢有开源前辈的贡献！
 * *********************************************************************/
void sigroutine(int signo) {
	switch (signo) {
		case SIGALRM:
			printf("Catch a signal -- SIGALRM\n");
			break;
		case SIGVTALRM:
			printf("Catch a signal -- SIGVTALRM\n");
			break;
	}
}

int main(int argc, char ** argv) {
	struct itimerval value,ovalue,value2;

	printf("process id is %d\n",getpid());
	signal(SIGALRM, sigroutine);
	signal(SIGVTALRM, sigroutine);

	value.it_value.tv_sec = 1;
	value.it_value.tv_usec = 0;
	value.it_interval.tv_sec = 1;
	value.it_interval.tv_usec = 0;
	setitimer(ITIMER_REAL, &value, &ovalue); /* 这将每隔1秒钟后产生 SIGALRM 信号 */

	value2.it_value.tv_sec = 0;
	value2.it_value.tv_usec = 500000;
	value2.it_interval.tv_sec = 0;
	value2.it_interval.tv_usec = 500000;
	setitimer(ITIMER_VIRTUAL, &value2, &ovalue);/* 对于在运行的程序，这将每隔0.5秒钟后产生 SIGVTALRM 信号。在sleep时间内是不产生闹钟的 */

	for (;;) ;
} 

/*
编译此程序：
gcc -Wall setitimer.c
运行程序：
./a.out

man setitimer 得到如下内容：
SYNOPSIS
#include <sys/time.h>

int getitimer(int which, struct itimerval *value);
int setitimer(int which, const struct itimerval *value,
			struct itimerval *ovalue);

DESCRIPTION
The system provides each process with three interval timers, each decrementing in a distinct time domain.  When any timer expires, a
signal is sent to the process, and the timer (potentially) restarts.

ITIMER_REAL    decrements in real time, and delivers SIGALRM upon expiration.

ITIMER_VIRTUAL decrements only when the process is executing, and delivers SIGVTALRM upo expiration.

ITIMER_PROF    decrements both when the process executes and when the system is executing on behalf of the  process.   Coupled  with
ITIMER_VIRTUAL,  this  timer  is  usually used to profile the time spent by the application in user and kernel space.
SIGPROF is delivered upon expiration.

Timer values are defined by the following structures:

struct itimerval {
	struct timeval it_interval; // next value 
	struct timeval it_value;    // current value 
};
struct timeval {
	long tv_sec;                // seconds 
	long tv_usec;               // microseconds 
};

The function getitimer() fills the structure indicated by value with the current setting for the timer indicated by  which  (one  of
			ITIMER_REAL,  ITIMER_VIRTUAL, or ITIMER_PROF).  The element it_value is set to the amount of time remaining on the timer, or zero if
the timer is disabled.  Similarly, it_interval is set to the reset value.  The function setitimer() sets the indicated timer to  the
value in value.  If ovalue is non-zero, the old value of the timer is stored there.

显然，我们首先设置it_value时间，这个时间就会自动减少，当减少到0时就会产生ITIMER信号，然后it_value将设置为it_interval的值重复上述闹钟计时过程。因此可以每隔一定时间“闹钟”一次。
而闹钟信号分为三种，ITIMER_REAL、ITIMER_VIRTUAL、ITIMER_PROF分别代表了当系统运行时产生闹钟、当进程在运行时产生闹钟、两种情况下都会产生。通常情况下，只要我们启动了程序闹钟，ITIMER_REAL计时就一定会持续进行；如果是ITIMER_VIRTUAL则只有在程序在运行时计时，如果你程序里有sleep之类的调用，则在sleep的时候是不会产生SIGVTALRM闹钟的。
比如下面这个代码将只会产生SIGALRM闹钟：

#include <signal.h>
#include <unistd.h>
#include <stdio.h>
#include <sys/time.h>

void sigroutine(int signo) {
	switch (signo) {
		case SIGALRM:
			printf("Catch a signal -- SIGALRM\n");
			break;
		case SIGVTALRM:
			printf("Catch a signal -- SIGVTALRM\n");
			break;
	}
}

int main(int argc, char ** argv) {
	struct itimerval value,ovalue,value2;
	int i = 0;

	printf("process id is %d\n",getpid());
	signal(SIGALRM, sigroutine);
	signal(SIGVTALRM, sigroutine);

	value.it_value.tv_sec = 1;
	value.it_value.tv_usec = 0;
	value.it_interval.tv_sec = 1;
	value.it_interval.tv_usec = 0;
	setitimer(ITIMER_REAL, &value, &ovalue);

	value2.it_value.tv_sec = 0;
	value2.it_value.tv_usec = 500000;
	value2.it_interval.tv_sec = 0;
	value2.it_interval.tv_usec = 500000;
	setitimer(ITIMER_VIRTUAL, &value2, &ovalue);

	for (i = 0; i < 50; i++) {
		usleep(100000);
	}
	return 0;
} 
*/
