#include <stdio.h>
#define MAX 50
static int any(char *s1, char *s2);
int main(int argc, char *argv[])
{
	if( 3 != argc )
		return 1;
	printf("%d\n", any(argv[1], argv[2]));
	return 0;
}
static int any(char *s1, char *s2)
{
	int i = 0, j = 0;
	for( i = 0; '\0' != s1[i]; ++i )
	{
		for( j = 0; '\0' != s2[j] && s1[i + j] == s2[j]; ++j )
			NULL;
		if( '\0' == s2[j] )
			return i;
	}
	return -1;
}
