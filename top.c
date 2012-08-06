/************关于本文档********************************************
 * *filename: top.c
 * *purpose: 说明运用ASCII控制字在固定位置显示字符的方法
 * *wrote by: zhoulifa(zhoulifa@163.com) 周立发(http://zhoulifa.bokee.com)
 * Linux爱好者 Linux知识传播者 SOHO族 开发者 最擅长C语言
 * *date time:2008-01-27 19:13 上海大雪天，据说是多年不遇
 * *Note: 任何人可以任意复制代码并运用这些文档，当然包括你的商业用途
 * * 但请遵循GPL
 * *Thanks to:
 * *                Ubuntu 本程序在Ubuntu 7.10系统上测试完全正常
 * *                Google.com 我通常通过google搜索发现许多有用的资料
 * *Hope:希望越来越多的人贡献自己的力量，为科学技术发展出力
 * * 科技站在巨人的肩膀上进步更快！感谢有开源前辈的贡献！
 * *********************************************************************/
#include<stdio.h>
#include<stdlib.h>
int main()
{
	int i=0;
	char *a[]={"hello","i am here","hahah","what do u think?","Great?"};
	system("clear");
	while(i<5)
	{
		printf("\033[10;0H\033[K\033[20;0H%s\n",a[i]);
		i++;
		sleep(1);
	}
}

/*
编译并运行程序：
gcc -Wall top.c
./a.out

关终端上的ASCII控制字符的详细信息，参见“用C语言自己编写一个more程序”  http://zhoulifa.bokee.com/5396159.html
*/
