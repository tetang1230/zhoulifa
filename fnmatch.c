#include <locale.h>
#include <fnmatch.h>
#include <stdio.h>
#include <sys/types.h>
#include <dirent.h>

main(int argc, char *argv[] )
{
	char    *pattern;
	DIR     *dir;
	struct dirent    *entry;
	int     ret;

	/*setlocale(LC_ALL, "zh_CN.UTF-8");*/

	dir = opendir(argv[2]);

	pattern = argv[1];

	if(dir != NULL){
		while( (entry = readdir(dir)) != NULL){
			ret = fnmatch(pattern, entry->d_name, FNM_PATHNAME|FNM_PERIOD);
			if(ret == 0){
				printf("%s\n", entry->d_name);
			}else if(ret == FNM_NOMATCH){
				continue ;
			}else{
				printf("error file=%s\n", entry->d_name);
			}
		}
		closedir(dir);
	}
}

/*
编译并运行此程序：
gcc -Wall fnmatch.c
./a.out "*.c" /src/mycode/c

此命令将把/src/mycode/c目录下*.c文件显示出来。即匹配文件名为*.c的
*/
