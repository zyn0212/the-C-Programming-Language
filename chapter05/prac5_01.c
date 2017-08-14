#include <stdio.h>
#include <ctype.h>
static int getint(int *pn);
int main(void)
{
	int i = 0;
	printf("%d\n", getint(&i));
	putchar(getchar());
	putchar(getchar());
	putchar(getchar());
	putchar('\n');
	return 0;
}
static int getint(int *pn)
{
	int c = 0, sign = 0, last = 0;
	
	while( isspace(c = getchar()) )
		NULL;
	if( !isdigit(c) && EOF != c && '+' != c && '-' != c ) {
		ungetc(c, stdin);
		return 0;
	}
	sign = '-' == c ? -1 : 1;
	if( '+' == c || '-' == c ) {
		last = c;
		c = getchar();
	}
	if( !isdigit(c) ) {
		ungetc(c, stdin);
		ungetc(last, stdin);
		return 0;
	}

	for( *pn = 0; isdigit(c); c = getchar() )
		*pn = *pn * 10 + c - '0';
	*pn *= sign;
	if( EOF != c )
		ungetc(c, stdin);
	return c;
}
