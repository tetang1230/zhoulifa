#include <stdio.h> /* for printf */
#include <string.h> /* for strcpy*/
/************关于本文档********************************************
 * *filename: coredump.c
 * *purpose: 说明引起segment fault错误的原因
 * *wrote by: zhoulifa(zhoulifa@163.com) 周立发(http://zhoulifa.bokee.com)
 * Linux爱好者 Linux知识传播者 SOHO族 开发者 最擅长C语言
 * *date time:2008-01-26 16:53 上海大雪天，据说是多年不遇
 * *Note: 任何人可以任意复制代码并运用这些文档，当然包括你的商业用途
 * * 但请遵循GPL
 * *Thanks to:
 * * Ubuntu 本程序在Ubuntu 7.10系统上测试完全正常
 * * Google.com 我通常通过google搜索发现许多有用的资料
 * *Hope:希望越来越多的人贡献自己的力量，为科学技术发展出力
 * * 科技站在巨人的肩膀上进步更快！感谢有开源前辈的贡献！
 * *********************************************************************/

int main(int argc, char ** argv)
{
	char * s ;
	strcpy(s, "hello");
	printf("%s\n", s);
	return 0;
}
编译此程序用命令：
gcc -Wall coredump.c
执行程序：
./a.out
得到输出:
Segment fault (或者中文环境下的：段错误)

		正确的代码可以是这样的：
#include <stdio.h> /* for printf */
#include <string.h> /* for strcpy*/

int main(int argc, char ** argv)
{
	char s[6] = "";
	strcpy(s, "hello");
	printf("%s\n", s);
	return 0;
}

或者
#include <stdio.h> /* for printf */
#include <string.h> /* for strcpy*/
#include <stdlib.h>  /* for malloc and free*/
#include <strings.h> /* for bzero */

int main(int argc, char ** argv)
{
	char * s = 0;
	s = (char *)malloc(6);
	bzero(s, 6);
	strcpy(s, "hello");
	printf("%s\n", s);
	free(s);
	return 0;
}
