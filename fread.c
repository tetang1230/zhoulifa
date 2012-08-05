/************关于本文档********************************************
 * *filename: fread.c
 * *purpose: 显示了一种接收用户数据输入的方法
 * *wrote by: zhoulifa(zhoulifa@163.com) 周立发(http://zhoulifa.bokee.com)
 * Linux爱好者 Linux知识传播者 SOHO族 开发者 最擅长C语言
 * *date time:2008-01-26 21:45 上海大雪天，据说是多年不遇
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
	char buf[5] = "";
	fread(buf, sizeof(buf) - 1, 1, stdin);
	/* fgets(buf, 5, stdin); */
	printf("%s\n", buf);
	return 0;
}

/*
编译此程序用命令：
gcc -Wall fread.c
执行程序：
./a.out

输入的数据将会被程序接收并回显。
程序中的fread和fgets实现同样的功能。

因为系统中有stdin、stdout、stderr本个已经定义好的句柄用作标准输入、标准输出、标准出错，因此我们可以直接利用stdin来进行输入，同样可以用stdout和stderr来作输出。这是用stdio时的情况，即标准C定义的。
如果是用unistd，即UNIX下常用的一套IO库，那么标准输入、标准输出、标准出错分别是0、1、2本个句柄，可以用read函数来实现输入、write函数来实现输出。比如：
read(0, buf, sizeof(buf) -1); //可以用来接收用户输入 
write(1, buf, strlen(buf));   // 可以用来输出buf的内容到标准输出
*/
