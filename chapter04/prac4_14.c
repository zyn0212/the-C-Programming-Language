#include <stdio.h>
#include <string.h>
#define swap(t, x, y) do {	t _swapvar;\
							_swapvar = x;\
							x = y;\
							y = _swapvar;\
						} while( 0 )
int main(void)
{
	struct ss {
		int x;
		char c;
		double d;
		short s;
	} x, y;
	memset(&x, 0, sizeof(struct ss));
	memset(&y, 0, sizeof(struct ss));
	x.d = 123456.789;
	y.d = 987654.321;
	printf("%f\t%f\n", x.d, y.d);
	swap(struct ss, x, y);
	printf("%f\t%f\n", x.d, y.d);
	return 0;
}
