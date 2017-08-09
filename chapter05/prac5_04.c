#include <stdio.h>
#define MAX 100
static int zstrend(char *s, char *t);
int main(int argc, char *argv[])
{
	if( 3 != argc )
		return 1;
	printf("%s and %s is %d\n", argv[1], argv[2], zstrend(argv[1], argv[2]));
	return 0;
}

static int zstrend(char *s, char *t)
{
	char * const sp = s, * const tp = t;
	while( '\0' != *s )
		++s;
	while( '\0' != *t )
		++t;
	while( s >= sp && t >= tp )
		if( *s-- != *t-- )
			return 0;
	if( t < tp )
		return 1;
	return 0;
}
