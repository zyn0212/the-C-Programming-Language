#include <stdio.h>
static int rightrot(int x, int n);
int main(void)
{
	printf("%0#x\n", rightrot(15, 2));
	return 0;
}
static int rightrot(int x, int n)
{
	if( n < 1 || n > (sizeof(int) << 3) - 1 )
		return x;
	int tmp = (~(~0 << n) & x) << (sizeof(int) << 3) - n;
	return x >> n | tmp;
}
