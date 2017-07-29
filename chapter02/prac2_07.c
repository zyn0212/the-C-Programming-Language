#include <stdio.h>
static int invert(int x, int p, int n);
int main(void)
{
	int x = 0x30;
	printf("%0#x\n", invert(x, 8, 4));
	return 0;
}
static int invert(int x, int p, int n)
{
	return x ^ ~(~0 << n) << p - n;
}
