/*
 *fileme: write.c
 *purpose: 说明write函数的用法
 *wrote by: zhoulifa(zhoulifa@163.com) 周立发(http://zhoulifa.bokee.com)
 Linux爱好者 Linux知识传播者 SOHO族 开发者 最擅长C语言
 *date time:2008-01-26 20:13 上海大雪天，据说是多年不遇
 *Note: 任何人可以任意复制代码并运用这些文档，当然包括你的商业用途
 * 但请遵循GPL
 * *Thanks to:
 * * Ubuntu 本程序在Ubuntu 7.10系统上测试完全正常
 * * Google.com 我通常通过google搜索发现许多有用的资料
 * *Hope:希望越来越多的人贡献自己的力量，为科学技术发展出力
 * * 科技站在巨人的肩膀上进步更快！感谢有开源前辈的贡献！
 * *********************************************************************/
#include <unistd.h> /* for write */
#include <string.h> /* for strlen */

/* ssize_t write(int fd, const void *buf, size_t count); */ /* write 函数的申明 */

int main(int argc, char ** argv)
{
	write(1, argv[1], strlen(argv[1]));
	write(1, "\n", 1);
	return 0;
}

/*
编译此程序用命令：
gcc -Wall write.c
执行程序：
./a.out hello

write函数本来是用来向一个文件句柄(file descriptor)输入内容的，通常的用法是：
int fd;
fd = open(filename, MODE);
write(fd, buf, size);
close(fd);

由于Linux系统中有三个默认的句柄，即标准输入、标准输出、标准出错，对应标准C中的文件句柄(FILE)是stdin、stdout、stderr，在Linux系统中是整数值0,1,2
因此，当我们往1句柄write内容时，就是在标准输出设备上显示内容，比如我们的终端上。
*/
