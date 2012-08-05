
/************关于本文档********************************************
 * *filename: strsignal.c
 * *purpose: 列出了所有系统定义的信号及信号意思
 * *wrote by: zhoulifa(zhoulifa@163.com) 周立发(http://zhoulifa.bokee.com)
 * Linux爱好者 Linux知识传播者 SOHO族 开发者 最擅长C语言
 * *date time:2008-01-26 21:13 上海大雪天，据说是多年不遇
 * *Note: 任何人可以任意复制代码并运用这些文档，当然包括你的商业用途
 * * 但请遵循GPL
 * *Thanks to:
 * * Ubuntu 本程序在Ubuntu 7.10系统上测试完全正常
 * * Google.com 我通常通过google搜索发现许多有用的资料
 * *Hope:希望越来越多的人贡献自己的力量，为科学技术发展出力
 * * 科技站在巨人的肩膀上进步更快！感谢有开源前辈的贡献！
 * *********************************************************************/
#define _GNU_SOURCE
#include <string.h>
#include <signal.h>
#include <stdio.h>
int main(int argc, char ** argv)        {
	int i = 0;
	for(i = 0; i < 128; i++)
	  printf("signal.%02d is: %s\n", i, strsignal(i));
	return 0;
}

/*
编译此程序用命令：
gcc -Wall strsignal.c
执行程序：
./a.out
输出如下：

signal.00 is: Unknown signal 0
signal.01 is: Hangup
signal.02 is: Interrupt
signal.03 is: Quit
signal.04 is: Illegal instruction
signal.05 is: Trace/breakpoint trap
signal.06 is: Aborted
signal.07 is: Bus error
signal.08 is: Floating point exception
signal.09 is: Killed
signal.10 is: User defined signal 1
signal.11 is: Segmentation fault
signal.12 is: User defined signal 2
signal.13 is: Broken pipe
signal.14 is: Alarm clock
signal.15 is: Terminated
signal.16 is: Stack fault
signal.17 is: Child exited
signal.18 is: Continued
signal.19 is: Stopped (signal)
signal.20 is: Stopped
signal.21 is: Stopped (tty input)
signal.22 is: Stopped (tty output)
		signal.23 is: Urgent I/O condition
		signal.24 is: CPU time limit exceeded
		signal.25 is: File size limit exceeded
		signal.26 is: Virtual timer expired
		signal.27 is: Profiling timer expired
		signal.28 is: Window changed
		signal.29 is: I/O possible
		signal.30 is: Power failure
		signal.31 is: Bad system call
		signal.32 is: Unknown signal 32
		signal.33 is: Unknown signal 33
		signal.34 is: Real-time signal 0
		signal.35 is: Real-time signal 1
		signal.36 is: Real-time signal 2
		signal.37 is: Real-time signal 3
		signal.38 is: Real-time signal 4
		signal.39 is: Real-time signal 5
		signal.40 is: Real-time signal 6
		signal.41 is: Real-time signal 7
		signal.42 is: Real-time signal 8
		signal.43 is: Real-time signal 9
		signal.44 is: Real-time signal 10
		signal.45 is: Real-time signal 11
		signal.46 is: Real-time signal 12
		signal.47 is: Real-time signal 13
		signal.48 is: Real-time signal 14
		signal.49 is: Real-time signal 15
		signal.50 is: Real-time signal 16
		signal.51 is: Real-time signal 17
		signal.52 is: Real-time signal 18
		signal.53 is: Real-time signal 19
		signal.54 is: Real-time signal 20
		signal.55 is: Real-time signal 21
		signal.56 is: Real-time signal 22
		signal.57 is: Real-time signal 23
		signal.58 is: Real-time signal 24
		signal.59 is: Real-time signal 25
		signal.60 is: Real-time signal 26
		signal.61 is: Real-time signal 27
		signal.62 is: Real-time signal 28
		signal.63 is: Real-time signal 29
		signal.64 is: Real-time signal 30
		signal.65 is: Unknown signal 65
		65-127全是Unknown signal，即信号从1开始到65为止
*/
