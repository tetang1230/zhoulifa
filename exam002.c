/************关于本文档********************************************
 * *filename: exam002.c
 * *purpose: 测试应聘者能力
 * *wrote by: zhoulifa(zhoulifa@163.com) 周立发(http://zhoulifa.bokee.com)
 * Linux爱好者 Linux知识传播者 SOHO族 开发者 最擅长C语言
 * *date time:2008-01-27 00:23 上海大雪天，据说是多年不遇
 * *Note: 任何人可以任意复制代码并运用这些文档，当然包括你的商业用途
 * * 但请遵循GPL
 * *Thanks to:
 * *                Ubuntu 本程序在Ubuntu 7.10系统上测试完全正常
 * *                Google.com 我通常通过google搜索发现许多有用的资料
 * *Hope:希望越来越多的人贡献自己的力量，为科学技术发展出力
 * * 科技站在巨人的肩膀上进步更快！感谢有开源前辈的贡献！
 * *********************************************************************/
#include<stdio.h>
int main(int argc, char **argv)
{
	enum color { red, yellow, blue, white, black };
	enum color i, j, k, pri;
	int n = 0, loop;
	for (i = red; i <= black; i++)
	  for (j = red; j <= black; j++)
		if (i != j) {
			for (k = red; k <= black; k++)
			  if ((k != j) && (i != k)) {
				  n = n + 1;
				  printf("%4d ", n);
				  for (loop = 1; loop <= 3; loop++) {
					  switch (loop) {
						  case 1:
							  pri = i;
							  break;
						  case 2:
							  pri = j;
							  break;
						  case 3:
							  pri = k;
							  break;
						  default:
							  break;
							  &160;            }
							  switch (pri) {
								  case red:
									  printf("%-10s", "red");
									  break;
								  case black:
									  printf("%-10s", "black");
									  break;
								  case yellow:
									  printf("%-10s", "yellow");
									  break;
								  case blue:
									  printf("%-10s", "blue");
									  break;
								  case white:
									  printf("%-10s", "white");
									  break;
								  default:
									  break;
							  }
				  }
				  printf("\n");
			  }
		}
	printf("\ntotla:%d\n", n);
	return 0;
}

/*
编译：
gcc -Wall exam002.c
运行：
./a.out
*/
