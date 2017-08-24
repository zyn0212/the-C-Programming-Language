#include <stdio.h>
#define MAX 200
static int readlines(char *des, char *src, int n);
int main(int argc, char *argv[])
{
	char s[MAX];
	if( 2 != argc )
		return 1;
	readlines(s, argv[1], MAX);
	printf("%s\n", s);
	return 0;
}
static int readlines(char *des, char *src, int n)
{
	while( n-- > 0 && '\0' != (*des++ = *src++) )
		NULL;
	return n;
}
