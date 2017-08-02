#include <stdio.h>
#define MAX 100
static int strrindex(char *s, char *t);
int main(int argc, char *argv[])
{
	char s[MAX] = "wo ai ni sun li na!", t[MAX] = "na!";
	printf("%d\n", strrindex(s, t));
	return 0;
}
static int strrindex(char *s, char *t)
{
	int slength = 0, tlength = 0;
	while( '\0' != s[slength] )
		++slength;
	while( '\0' != t[tlength] )
		++tlength;
	slength -= tlength;
	while( slength >= 0 )
	{
		int tmp = 0;
		for( tmp = 0; tmp < tlength && s[slength + tmp] == t[tmp]; ++tmp )
			NULL;
		if( tmp == tlength )
			return slength + 1;
		--slength;
	}
	return slength;
}
