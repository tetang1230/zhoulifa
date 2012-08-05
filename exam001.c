/************关于本文档********************************************
 * *filename: exam001.c
 * *purpose: 测试应聘者对字符数组的理解
 * *wrote by: zhoulifa(zhoulifa@163.com) 周立发(http://zhoulifa.bokee.com)
 * Linux爱好者 Linux知识传播者 SOHO族 开发者 最擅长C语言
 * *date time:2008-01-27 00:13 上海大雪天，据说是多年不遇
 * *Note: 任何人可以任意复制代码并运用这些文档，当然包括你的商业用途
 * * 但请遵循GPL
 * *Thanks to:
 * *                Ubuntu 本程序在Ubuntu 7.10系统上测试完全正常
 * *                Google.com 我通常通过google搜索发现许多有用的资料
 * *Hope:希望越来越多的人贡献自己的力量，为科学技术发展出力
 * * 科技站在巨人的肩膀上进步更快！感谢有开源前辈的贡献！
 * *********************************************************************/
#include <stdio.h>
#include <string.h>
void func(char * str)
{
	printf("sizeof(str)=%d\n", sizeof(str));
	printf("strlen(str)=%d\n", strlen(str));
}

int main(void)
{
	int b[]={1,2,3,4,5,6};
	char a[]="123456789";
	printf("sizeof(a)=%d\n", sizeof(a));
	printf("sizeof(b)=%d\n", sizeof(b));
	func(a);
	return 0;
}

/*
编译：
gcc -Wall exam001.c
请推断出执行程序时屏幕上的输出内容。
*/
