/************关于本文档********************************************
 * *filename: addr.c
 * *purpose: 查看函数及变量在内存中的地址
 * *wrote by: zhoulifa(zhoulifa@163.com) 周立发(http://zhoulifa.bokee.com)
 * Linux爱好者 Linux知识传播者 SOHO族 开发者 最擅长C语言
 * *date time:2008-01-26 17:43 上海大雪天，据说是多年不遇
 * *Note: 任何人可以任意复制代码并运用这些文档，当然包括你的商业用途
 * * 但请遵循GPL
 * *Thanks to:
 * * Ubuntu 本程序在Ubuntu 7.10系统上测试完全正常
 * * Google.com 我通常通过google搜索发现许多有用的资料
 * *Hope:希望越来越多的人贡献自己的力量，为科学技术发展出力
 * * 科技站在巨人的肩膀上进步更快！感谢有开源前辈的贡献！
 * *********************************************************************/

#include <stdio.h>

int main(int argc, char ** argv)
{
	int x = 0;
	float y = 0.0;
	printf("main=%u argv=%u &argc=%u &x=%u &y=%u\n", main, argv, &argc, &x, &y);
	return 0;
}
