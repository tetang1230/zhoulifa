/*
 * centos下需要安装readline-devel
 * yum install readline-devel
 *
 * ubuntu下需要安装libreadline5-dev,我没验证过。
 */


#include <stdio.h>
#include <readline/readline.h>
#include <readline/history.h>


/************关于本文档********************************************
 * *filename: readline.c
 * *purpose: 说明调用readline库提供的函数readline进行用户输入
 * *wrote by: zhoulifa(zhoulifa@163.com) 周立发(http://zhoulifa.bokee.com)
 * Linux爱好者 Linux知识传播者 SOHO族 开发者 最擅长C语言
 * *date time:2008-01-26 17:23 上海大雪天，据说是多年不遇
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
	char * p;
	p = readline("请输入:");
	//若尚未读取到字符就遇到EOF，则该函数返回NULL；否则返回由malloc()分配的命令行内存，故调用结束后应通过free()显式地释放内存。
	printf("%s\n", p);
	free(p);
	return 0;
}

/*
编译此程序用命令：
gcc -Wall readline.c -lreadline
执行程序：
./a.out
得到输出:
请输入:hello
hello
*/
