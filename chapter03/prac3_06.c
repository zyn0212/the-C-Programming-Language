#include <stdio.h>
static char *itoa(int n, char *s, int width);
int main(int argc, char *argv[])
{
	int n = -123456;
	char s[100] = "543";
	printf("%d = %s\n", n, itoa(n, s, 17));
	return 0;
}
static char *itoa(int n, char *s, int width)
{
	char base[11] = "0123456789", sign = '+';
	char *head = s, *tail = s, *ret = s;
	if( n < 0 )
	{
		n = -n;
		sign = '-';
	}
	while( n > 0 )
	{
		*s++ = base[n % 10];
		n /= 10;
	}
	if( '-' == sign )
		*s++ = '-';
	int i = 0;
	for( i = s - ret; i < width; ++i )
		*s++ = ' ';
	*s-- = '\0';
	tail = s;
	while( head < tail )
	{
		*head ^= *tail ^= *head ^= *tail;
		++head;
		--tail;
	}
	return ret;
}
