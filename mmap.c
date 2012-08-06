
/************关于本文档********************************************
 * *filename: mmap.c
 * *purpose: 说明调用mmap把文件映射到内存的方法
 * *wrote by: zhoulifa(zhoulifa@163.com) 周立发(http://zhoulifa.bokee.com)
 * Linux爱好者 Linux知识传播者 SOHO族 开发者 最擅长C语言
 * *date time:2008-01-27 18:59 上海大雪天，据说是多年不遇
 * *Note: 任何人可以任意复制代码并运用这些文档，当然包括你的商业用途
 * * 但请遵循GPL
 * *Thanks to:
 * *                Ubuntu 本程序在Ubuntu 7.10系统上测试完全正常
 * *                Google.com 我通常通过google搜索发现许多有用的资料
 * *Hope:希望越来越多的人贡献自己的力量，为科学技术发展出力
 * * 科技站在巨人的肩膀上进步更快！感谢有开源前辈的贡献！
 * *********************************************************************/
#include <sys/mman.h>  /* for mmap and munmap */
#include <sys/types.h> /* for open */
#include <sys/stat.h>  /* for open */
#include <fcntl.h>     /* for open */
#include <unistd.h>    /* for lseek and write */
#include <stdio.h>

int main(int argc, char **argv)
{
	int fd;
	char *mapped_mem, * p;
	int flength = 1024;
	void * start_addr = 0;

	fd = open(argv[1], O_RDWR | O_CREAT, S_IRUSR | S_IWUSR);
	flength = lseek(fd, 1, SEEK_END);
	write(fd, "\0", 1); /* 在文件最后添加一个空字符，以便下面printf正常工作 */
	lseek(fd, 0, SEEK_SET);
	mapped_mem = mmap(start_addr, flength, PROT_READ,        //允许读
				MAP_PRIVATE,       //不允许其它进程访问此内存区域
				fd, 0);
	/* 使用映射区域. */
	printf("%s\n", mapped_mem); /* 为了保证这里工作正常，参数传递的文件名最好是一个文本文件 */
	close(fd);
	munmap(mapped_mem, flength);
	return 0;
}

/*
编译运行此程序：
gcc -Wall mmap.c
./a.out text_filename

上面的方法因为用了PROT_READ，所以只能读取文件里的内容，不能修改，如果换成PROT_WRITE就可以修改文件的内容了。又由于 用了MAAP_PRIVATE所以只能此进程使用此内存区域，如果换成MAP_SHARED，则可以被其它进程访问，比如下面的：
*/
#include <sys/mman.h>  /* for mmap and munmap */
#include <sys/types.h> /* for open */
#include <sys/stat.h>  /* for open */
#include <fcntl.h>     /* for open */
#include <unistd.h>    /* for lseek and write */
#include <stdio.h>
#include <string.h> /* for memcpy */

int main(int argc, char **argv)
{
	int fd;
	char *mapped_mem, * p;
	int flength = 1024;
	void * start_addr = 0;

	fd = open(argv[1], O_RDWR | O_CREAT, S_IRUSR | S_IWUSR);
	flength = lseek(fd, 1, SEEK_END);
	write(fd, "\0", 1); /* 在文件最后添加一个空字符，以便下面printf正常工作 */
	lseek(fd, 0, SEEK_SET);
	start_addr = 0x80000;
	mapped_mem = mmap(start_addr, flength, PROT_READ|PROT_WRITE,        //允许写入
				MAP_SHARED,       //允许其它进程访问此内存区域
				fd, 0);
	/* 使用映射区域. */
	printf("%s\n", mapped_mem); /* 为了保证这里工作正常，参数传递的文件名最好是一个文本文 */
	while((p = strstr(mapped_mem, "Hello"))) { /* 此处来修改文件 内容 */
		memcpy(p, "Linux", 5);
		p += 5;
	}
	close(fd);
	munmap(mapped_mem, flength);
	return 0;
}
/*
man -a mmap 看更详细的信息
之前的一个例子：用 C 语言编写一个网络蜘蛛来搜索网上出现的电子邮件地址 ，地址是： http://zhoulifa.bokee.com/5603465.html
*/
