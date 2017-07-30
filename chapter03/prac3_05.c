#include <stdio.h>
#include <stdlib.h>
static char *itob(int n, char *s, int b);
int main(int argc, char *argv[])
{
	if( 3 != argc )
		return 1;
	char s[100];
	printf("result = %s\n", itob(atoi(argv[1]), s, atoi(argv[2])));
	return 0;
}
static char *itob(int n, char *s, int b)
{
	if( b < 2 || b > 36 )
		return *s = '\0';
	char base[37] = "0123456789abcdefghijklmnopqrstuvwxyz", *ret = s, *head = s, *tail = s;
	while( n > 0 )
	{
		*s++ = base[n % b];
		n /= b;
	}
	*s = '\0';
	tail = --s;
	while( head < tail )
	{
		*head ^= *tail ^= *head ^= *tail;
		++head;
		--tail;
	}
	return ret;
}
