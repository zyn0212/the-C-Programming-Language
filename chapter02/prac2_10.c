#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define MAX 16
static int lower(int c);
int main(void)
{
	int i = 0;
	char s[MAX];
	srand(time(0));
	for( i = 0; i < MAX - 1; ++i )
		printf("%c\t", lower(s[i] = rand() % 43 + '0'));
	putchar('\n');
	return 0;
}
static int lower(int c)
{
	return c >= 'A' && c <= 'Z' ? c ^ 0x20 : c;
}
