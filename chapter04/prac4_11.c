#include <stdio.h>
#define MAX 100
static void zungetch(char c);
static int zgetchar(void);
int main(int argc, char *argv[])
{
	char s[MAX];
	int c = 0;
	zgetchar();
	zungetch('h');
	while( EOF != (c = zgetchar()) )
		putchar(c);
	putchar('\n');
	return 0;
}
static int length = 0;
static int zgetchar(void)
{
	int ret = length;
	if( ret > 0 )
	{
		length = 0;
		return ret;
	}
	return getchar();
}
static void zungetch(char c)
{
	length = c;
}
