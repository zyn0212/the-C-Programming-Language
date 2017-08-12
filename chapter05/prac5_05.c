#include <stdio.h>
#include <stdlib.h>
#define MAX 100
static char *zstrncpy(char *s, char *t, int n);
static char *zstrncat(char *s, char *t, int n);
static int zstrncmp(char *s, char *t, int n);
int main(int argc, char *argv[])
{
	if( 4 != argc ) {
		printf("Wrong arguments!\n");
		return 1;
	}
	char s[MAX];
	printf("%s\t%s\t%d\n", argv[1], argv[2], zstrncmp(argv[1], argv[2], atoi(argv[3])));
	return 0;
}
static char *zstrncpy(char *s, char *t, int n)
{
	if( NULL == s || NULL == t || n < 1 )
		return s;
	char *ret = s;
	int i = 0;
	while( '\0' != *t ) {
		++t;
		++i;
	}
	t -= i;
	if( t > s || t + n < s ) {
		while( n-- > 0 && (*s++ = *t++) )
			NULL;
		if( n <= 0 )
			*s = '\0';
	}
	else {
		t += n <= i ? n : i;
		s += n <= i ? n : i;
		--t;
		*s-- = '\0';
		while( n-- > 0 )
			*s-- = *t--;
	}
	return ret;
}
static char *zstrncat(char *s, char *t, int n)
{
	if( NULL == s || NULL == t || n < 1 )
		return s;
	char *ret = s;
	while( '\0' != *s )
		++s;
	zstrncpy(s, t, n);
	return ret;
}
static int zstrncmp(char *s, char *t, int n)
{
	if( NULL == s || NULL == t || n < 1 )
		return 0;
	for(; *s == *t; ++s, ++t )
		if( 0 == --n || '\0' == *s )
			return 0;
	if( '\0' == *t )
		return 0;
	return *s - *t;
}
