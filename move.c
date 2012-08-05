/*
 *fileme: move.c
 *purpose: 显示了移位操作结果
 *wrote by: zhoulifa(zhoulifa@163.com) 周立发(http://zhoulifa.bokee.com)
 Linux爱好者 Linux知识传播者 SOHO族 开发者 最擅长C语言
 *date time:2008-01-26 21:33 上海大雪天，据说是多年不遇
 *Note: 任何人可以任意复制代码并运用这些文档，当然包括你的商业用途
 * 但请遵循GPL
 * *Thanks to:
 * *                Ubuntu 本程序在Ubuntu 7.10系统上测试完全正常
 * *                Google.com 我通常通过google搜索发现许多有用的资料
 * *Hope:希望越来越多的人贡献自己的力量，为科学技术发展出力
 * * 科技站在巨人的肩膀上进步更快！感谢有开源前辈的贡献！
 * *********************************************************************/
#include <stdio.h>

int main(int argc, char ** argv)
{
	unsigned char x = 0x1;
	unsigned int y = 0;
	int i = 0;
	for(i = 0; i < 40; i++) {
		y = x<<i;
		printf("%03d左移.%02d位为 %u\n", x, i, y);
	}
	x = 255;
	for(i = 0; i < 40; i++) {
		y = x>>i;
		printf("%03d右移.%02d位为 %u\n", x, i, y);
	}
	return 0;
}

/*
编译此程序用命令：
gcc -Wall move.c
执行程序：
./a.out
输出如下：
001左移.00位为 1
001左移.01位为 2
001左移.02位为 4
001左移.03位为 8
001左移.04位为 16
001左移.05位为 32
001左移.06位为 64
001左移.07位为 128
001左移.08位为 256
001左移.09位为 512
001左移.10位为 1024
001左移.11位为 2048
001左移.12位为 4096
001左移.13位为 8192
001左移.14位为 16384
001左移.15位为 32768
001左移.16位为 65536
001左移.17位为 131072
001左移.18位为 262144
001左移.19位为 524288
001左移.20位为 1048576
001左移.21位为 2097152
001左移.22位为 4194304
001左移.23位为 8388608
001左移.24位为 16777216
001左移.25位为 33554432
001左移.26位为 67108864
001左移.27位为 134217728
001左移.28位为 268435456
001左移.29位为 536870912
001左移.30位为 1073741824
001左移.31位为 2147483648
001左移.32位为 1
001左移.33位为 2
001左移.34位为 4
001左移.35位为 8
001左移.36位为 16
001左移.37位为 32
001左移.38位为 64
001左移.39位为 128
255右移.00位为 255
255右移.01位为 127
255右移.02位为 63
255右移.03位为 31
255右移.04位为 15
255右移.05位为 7
255右移.06位为 3
255右移.07位为 1
255右移.08位为 0
255右移.09位为 0
255右移.10位为 0
255右移.11位为 0
255右移.12位为 0
255右移.13位为 0
255右移.14位为 0
255右移.15位为 0
255右移.16位为 0
255右移.17位为 0
255右移.18位为 0
255右移.19位为 0
255右移.20位为 0
255右移.21位为 0
255右移.22位为 0
255右移.23位为 0
255右移.24位为 0
255右移.25位为 0
255右移.26位为 0
255右移.27位为 0
255右移.28位为 0
255右移.29位为 0
255右移.30位为 0
255右移.31位为 0
255右移.32位为 255
255右移.33位为 127
255右移.34位为 63
255右移.35位为 31
255右移.36位为 15
255右移.37位为 7
255右移.38位为 3
255右移.39位为 1
*/