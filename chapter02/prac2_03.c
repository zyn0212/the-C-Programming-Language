#include <stdio.h>
#define MAX 10
static int htoi(char *s);
int main(void)
{
	int c = 0;
	char s[MAX];
	char *input = s;
	while( ' ' == (c = getchar()) || '\t' == c )
		NULL;
	while( EOF != c && '\n' != c )
	{
		*input++ = c;
		c = getchar();
	}
	*input = '\0';
	printf("%s = %d\n", s, htoi(s));
	return 0;
}
static int htoi(char *s)
{
	int result = 0, length = 0, base = 1;
	while( '\0' != s[length] )
		++length;
	if( '\n' == s[--length] )
		--length;
	while( length >= 0 && 'x' != s[length] && 'X' != s[length] )
	{
		if( s[length] >= '0' && s[length] <= '9' )
			result += (s[length] - '0') * base;
		else if( s[length] >= 'a' && s[length] <= 'f' )
			result += (s[length] - 'a'+ 10) * base;
		else if( s[length] >= 'A' && s[length] <= 'F' )
			result += (s[length] - 'A' + 10) * base;
		else
			return result;
		--length;
		base *= 16;
	}
	return result;
}
