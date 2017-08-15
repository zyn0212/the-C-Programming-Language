#include <stdio.h>
#define MAX 100
static int zgetline(char *s, int max);
static int zatoi(char *s, int max);
static int reverse(char *s);
int main(int argc, char *argv[])
{
	char s[MAX];
	printf("%d\n", zgetline(s, MAX));
	printf("%d\n", reverse(s));
	printf("%s\n", s);
	printf("%d\n", zatoi(s, MAX));
	return 0;
}
static int zgetline(char *s, int max)
{
	if( NULL == s || max < 1 )
		return -1;
	int i = 0, c = getchar();
	for( i = 0; i < max && EOF != c && '\n' != c; ++i, c = getchar() )
		*s++ = c;
	*s = '\0';
	return i;
}
static int zatoi(char *s, int max)
{
	if( NULL == s || max < 1 )
		return -1;
	int sum = 0, i = 0;
	for( ; i < max && *s >= '0' && *s <= '9'; ++i, ++s )
		sum = 10 * sum + *s - '0';
	return sum;
}
static int reverse(char *s)
{
	if( NULL == s )
		return -1;
	int i = 0;
	char *head = s, *tail = NULL;
	while( '\0' != *s )
		++s;
	tail = --s;
	while( head < tail ) {
		++i;
		*head ^= *tail ^= *head ^= *tail;
		++head;
		--tail;
	}
	return i;
}
