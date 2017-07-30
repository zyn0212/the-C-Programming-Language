#include <stdio.h>
#define MAX 100
static char *expand(char *s1, char *s2);
int main(int argc, char *argv[])
{
	char s1[MAX] = "a-r-cz-";
	char s2[MAX << 1] = "fff\0";
	printf("%s\n", expand(s1, s2));
	return 0;
}
static char *expand(char *s1, char *s2)
{
	char *ret = s2, *loc = s1;
	int i = 0;
	while( '\0' != *s1 )
	{
		switch( *s1 )
		{
			case '-':
				if( loc == s1 || '\0' == *(s1 + 1) )
				{
					*s2++ = '-';
					break;
				}
				for( i = *(s1 - 1) + 1; i < *(s1 + 1); ++i )
					*s2++ = i;
				break;
			default:
				*s2++ = *s1;
				break;
		}
		++s1;
	}
	*s2 = '\0';
	return ret;
}
