#include <stdio.h>
static int setbits(int x, int p, int n, int y);
int main(void)
{
	int x = 0x0, y = 0xFF;
	printf("%0#x\n", setbits(x, 8, 3, y));
	return 0;
}
static int setbits(int x, int p, int n, int y)
{
	x &= ~(~(~0 << n) << p - n);
	return x |= (~(~0 << n) & y) << p - n;
}
