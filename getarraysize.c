
/************关于本文档********************************************
 * *filename: getarraysize.c
 * *purpose: 说明如果求出数组元素个数
 * *wrote by: zhoulifa(zhoulifa@163.com) 周立发(http://zhoulifa.bokee.com)
 * Linux爱好者 Linux知识传播者 SOHO族 开发者 最擅长C语言
 * *date time:2008-01-26 16:25 上海大雪天，据说是多年不遇
 * *Note: 任何人可以任意复制代码并运用这些文档，当然包括你的商业用途
 * * 但请遵循GPL
 * *Thanks to:
 * *                Ubuntu 本程序在Ubuntu 7.10系统上测试完全正常
 * *                Google.com 我通常通过google搜索发现许多有用的资料
 * *Hope:希望越来越多的人贡献自己的力量，为科学技术发展出力
 * * 科技站在巨人的肩膀上进步更快！感谢有开源前辈的贡献！
 * *********************************************************************/
#include <stdio.h> /* for printf */
int main(void)
{
	int a[3];
	printf("n=%d\n", sizeof(a)/sizeof(int)); /*用数组变量总的size除以数组元素的size，就是元素个数*/
	return 0;
}

/*
   编译此程序用命令：
   gcc -Wall getarraysize.c
   执行程序：
   ./a.out
   得到输出:
   n=3
*/
