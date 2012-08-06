/************关于本文档********************************************
 * *filename: union.c
 * *purpose: 说明union结构
 * *wrote by: zhoulifa(zhoulifa@163.com) 周立发(http://zhoulifa.bokee.com)
 * Linux爱好者 Linux知识传播者 SOHO族 开发者 最擅长C语言
 * *date time:2008-01-27 19:43 上海大雪天，据说是多年不遇
 * *Note: 任何人可以任意复制代码并运用这些文档，当然包括你的商业用途
 * * 但请遵循GPL
 * *Thanks to:
 * *                Ubuntu 本程序在Ubuntu 7.10系统上测试完全正常
 * *                Google.com 我通常通过google搜索发现许多有用的资料
 * *Hope:希望越来越多的人贡献自己的力量，为科学技术发展出力
 * * 科技站在巨人的肩膀上进步更快！感谢有开源前辈的贡献！
 * *********************************************************************/
#include <stdio.h>
#include <string.h>

int main(void)
{
	union {
		int x;
		char y[3];
		struct x {
			int x;
			int y;
		}z;
	}xx;
	memset(&xx, 0, sizeof(xx));
	printf("0 %d x:%d y:%s z.x:%d z.y:%d\n", sizeof(xx), xx.x, xx.y, xx.z.x, xx.z.y);
	strcpy(xx.y, "ab");
	printf("1 %d x:%d y:%s z.x:%d z.y:%d\n", sizeof(xx), xx.x, xx.y, xx.z.x, xx.z.y);
	xx.x=100;
	printf("2 %d x:%d y:%s z.x:%d z.y:%d\n", sizeof(xx), xx.x, xx.y, xx.z.x, xx.z.y);
	xx.z.x=1;
	xx.z.y=2;
	printf("3 %d x:%d y:%s z.x:%d z.y:%d\n", sizeof(xx), xx.x, xx.y, xx.z.x, xx.z.y);
	return 0;
}

/*
编译运行此程序：
gcc -Wall union.c
./a.out
得到如下输出结果：

0 8 x:0 y: z.x:0 z.y:0
1 8 x:25185 y:ab z.x:25185 z.y:0
2 8 x:100 y:d z.x:100 z.y:0
3 8 x:1 y: z.x:1 z.y:2

为什么会得到这个结果呢？
因为union结构是对同一块内存区域的内容按照不同数据类型要求来处理的。
比如此程序中：xx这个结构的三个成员中，最大的是z，因为有两个int所以占8个字节，因此整个结构的size取最大的成员的size，得到8。因此有8个字节的内存区域 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00
当开始全置0时，无论如何理解，数值都是0，字符全为空。

当把y的值置为ab时，xx结构理解为y，即内存区域是这样的：0x61 0x62 0x00 0x00 0x00 0x00 0x00 0x00一个字符串， 因为a的ASCII码值为0x61，b的ASCII码值为0x62。因此此时输出xx.y的值就是ab。但如果对同样这块内存区域0x61 0x62 0x00 0x00 0x00 0x00 0x00 0x00理解成一个int时，就取前4位为一个整数，即0x00006261(我这里是little-endiam)，因此此时打印zz.x值为25185，同样如果打印xx.z.x和xx.z.y的值就得到0x00006261和0x00000000，即25185和0

当把xx.x的值置为100时，即0x64，内存区域变成了0x64 0x00 0x00 0x00 0x00 0x00 0x00 0x00，按照同样的理解，如果理解为一个整数则为0x00000064，即100，如果理解为字符串，则只有一个字符d(d的ASCII值为0x64,即100)，所以打印xx.y显示为d，同理zz.x=100而zz.y=0

当最后xx.z.x=1,xx.z.y=2时，内存区域变成了0x01 0x00 0x00 0x00 0x02 0x00 0x00 0x00。同理理解
*/
