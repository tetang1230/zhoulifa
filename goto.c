#include <stdio.h>
#include <string.h>
#include <stdlib.h>
char * p1, * p2, * p3;
/*
 *  * return value:0 successful, -1 failed
 *  */
int init(void)
{
	p1 = (char *)malloc(100);
	if(p1)  memset(p1, 0, 100);
	else goto real_exit;

	p2 = (char *)malloc(100);
	if(p2)  memset(p2, 0, 100);
	else goto free_p1;

	p3 = (char *)malloc(100);
	if(p3)  memset(p3, 0, 100);
	else goto free_p2;

	return 0;
free_p2:
	free(p2);
free_p1:
	free(p1);
real_exit:
	return -1;
}

int main(void)
{
	int ret = 0;
	ret = init();
	while(!ret) {
		scanf("%s %s %s", p1, p2, p3);
		printf("%s %s %s\n", p1, p2, p3);
		if(!strcmp(p1, "quit")) break;
	}
	free(p3);
	free(p2);
	free(p1);
	return 0;
}
