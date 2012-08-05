#include <stdio.h> /* for printf*/
/************关于本文档********************************************
 * *filename: comma.c
 * *purpose: 说明逗号运算表达式的执行顺序
 * *wrote by: zhoulifa(zhoulifa@163.com) 周立发(http://zhoulifa.bokee.com)
 * Linux爱好者 Linux知识传播者 SOHO族 开发者 最擅长C语言
 * *date time:2008-01-26 16:35 上海大雪天，据说是多年不遇
 * *Note: 任何人可以任意复制代码并运用这些文档，当然包括你的商业用途
 * * 但请遵循GPL
 * *Thanks to:
 * *                Ubuntu 本程序在Ubuntu 7.10系统上测试完全正常
 * *                Google.com 我通常通过google搜索发现许多有用的资料
 * *Hope:希望越来越多的人贡献自己的力量，为科学技术发展出力
 * * 科技站在巨人的肩膀上进步更快！感谢有开源前辈的贡献！
 * *********************************************************************/

int main(int argc, char ** argv)
{
	int x = 0, y = 0;
	x = ( x = y + 1, y++, y + 3);
	printf("x=%d y=%d\n", x, y);
	return 0;
}

/*
 *
编译此程序用命令：
gcc -Wall comma.c
执行程序：
./a.out
得到输出:
x=4 y=1

对于这一句“x = ( x = y + 1, y++, y + 3);”执行顺序的理解是：
首先运行x=y+1，此时各值为x=1,y=0
然后运行y++，此时各值为x=1,y=1
再才执行y+3，此时各值为x=1,y=1，但此时运算的返回值为4，即y+1的结果。
最后执行赋值语句，即上述“( x = y + 1, y++, y + 3)”运算的返回值4赋给x，所以此时x=4,y=1
*/
