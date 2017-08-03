#include <stdio.h>
#include <ctype.h>
#define MAX 100
static char *expand(char *s1, char *s2);
int main(int argc, char *argv[])
{
	char s1[MAX] = "a-d-0-8-z-";
	char s2[MAX << 1] = "fff\0";
	printf("%s\n", expand(s1, s2));
	return 0;
}
static char *expand(char *s1, char *s2)
{
	char *ret = s2;
	int c = 0;
	while( '\0' != (c = *s1++) )
		if( 1 == isalnum(c) && '-' == *s1 && c < *(s1 + 1) )
		{
			++s1;
			while( c < *s1 )
				*s2++ = c++;
		}
		else
			*s2++ = c;
	*s2 = '\0';
	return ret;
}
