#include <stdio.h>
#include <string.h>
#define MAX 400
static void squeeze(char *res, char *match);
int main(int argc, char *argv[])
{
	if( 3 != argc )
		return 1;
	FILE *fp = fopen(argv[1], "r");
	if( NULL == fp )
		return 2;
	int c = 0;
	char s[MAX];
	while( NULL != fgets(s, MAX, fp) )
	{
		squeeze(s, argv[2]);
		printf("%s\n", s);
	}
	return 0;
}
static void squeeze(char *res, char *match)
{
	int reslen = strlen(res), matchlen = strlen(match), i = 0, j = 0;
	for( i = 0; i < reslen; )
	{
		j = 0;
		while( res[j] == match[j] )
		{
			if( '\0' == match[j] )
				break;
			++j;
		}
		if( matchlen == j )
		{
			sprintf(res, "%s", res + matchlen);
			continue;
		}
		++i;
		++res;
	}
}
