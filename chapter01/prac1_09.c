#include <stdio.h>
#define BLANK 0x2020
int main(void)
{
	int c = 0, last = 'a';
	while( EOF != (c = getchar()) )
	{
		if( ' ' != c || ' ' != last )
			putchar(c);
		last = c;
	}
	printf("\n");
	return 0;
}
