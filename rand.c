/************关于本文档********************************************
 * *filename: rand.c
 * *purpose: 展示了一种产生随机数的方法
 * *wrote by: zhoulifa(zhoulifa@163.com) 周立发(http://zhoulifa.bokee.com)
 * Linux爱好者 Linux知识传播者 SOHO族 开发者 最擅长C语言
 * *date time:2008-01-26 20:37 上海大雪天，据说是多年不遇
 * *Note: 任何人可以任意复制代码并运用这些文档，当然包括你的商业用途
 * * 但请遵循GPL
 * *Thanks to:
 * *                Ubuntu 本程序在Ubuntu 7.10系统上测试完全正常
 * *                Google.com 我通常通过google搜索发现许多有用的资料
 * *Hope:希望越来越多的人贡献自己的力量，为科学技术发展出力
 * * 科技站在巨人的肩膀上进步更快！感谢有开源前辈的贡献！
 * *********************************************************************/
#include <stdlib.h> /* for rand and atoi */
#include <stdio.h>  /* for fprintf */
#include <time.h>   /* for time */

int main(int argc, char ** argv) {
	time_t t;
	t=time(0);
	srand(t);
	fprintf(stdout, "%d", rand()%atoi(argv[1]));
	return 0;
}

/*
编译此程序用命令：
gcc -Wall rand.c
执行程序：
./a.out 65535

需要说明的是：计算机里面产生的总是假的随机数，称之为伪随机数。即在条件相同的情况下，这个随机数一定可以被重现。

还有其它一些产生随机数的方法，比如调用srandom函数之后再调用random函数等。
*/
