#include <stdio.h>
#define MAX 100
static char *itoa(long x, char *s);
int main(void)
{
	char s[MAX];
	printf("cause of overflow!\n");
	printf("%ld\n", -0x8000000000000000);
	printf("%s\n", itoa(-0x8000000000000000, s));
	return 0;
}
static char *itoa(long x, char *s)
{
	char *ret = s;
	if( x < 0 )
		*s++ = '-';
	else
		x = -x;
	while( x < 0 )
	{
		*s++ = '0' - x % 10;
		x /= 10;
	}
	*s = '\0';
	char *head = ret + 1, *tail = --s;
	while( head < tail )
	{
		*head ^= *tail ^= *head ^= *tail;
		++head;
		--tail;
	}
	return ret;
}
