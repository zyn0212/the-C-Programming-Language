#include <stdio.h>
static int rightrot(int x, int n);
int main(void)
{
	printf("%0#x\n", rightrot(15, 3));
	return 0;
}
static int rightrot(int x, int n)
{
	int tmp = (~(~0 << n) & x) << (sizeof(int) << 3) - n;
	return x >> n | tmp;
}
