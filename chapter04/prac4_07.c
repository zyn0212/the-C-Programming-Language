#include <stdio.h>
#define MAX 100
static void zungets(char *s);
static int zgetchar(void);
int main(int argc, char *argv[])
{
	char s[MAX];
	int c = 0;
	zgetchar();
	zungets("hello!");
	while( '\0' != (c = zgetchar()) )
		putchar(c);
	putchar('\n');
	return 0;
}
int inputbuf[MAX];
static int length = 0;
static int zgetchar(void)
{
	if( length > 0 )
		return inputbuf[--length];
	else
		return getchar();
}
static void zungets(char *s)
{
	if( '\0' != *s )
		zungets(s + 1);
	inputbuf[length++] = *s;
}
