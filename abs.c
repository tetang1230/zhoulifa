#include <stdio.h>
#include <math.h>
int main(int argc, char ** argv)
{
	int x, y;
	if(argc > 1) x = atoi(argv[1]);
	else x = -21;
	y = abs(x);
	printf("x=%d y=%d\n", x, y);
	return 0;
}
