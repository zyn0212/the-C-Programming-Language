#include <stdio.h>
#define MAX 200
static char *escape(char *s, char *t);
static char *unescape(char *s, char *t);
int main(int argc, char *argv[])
{
	char s[MAX] = "wo ai ni sun li na.";
	char t[MAX] = "until forever!\n\t\t without change!";
	printf("s = %s\nt = %s\n", s, t);
	printf("result = %s\n", escape(s, t));
	printf("result = %s\n", unescape(s, t));
	return 0;
}
static char *escape(char *s, char *t)
{
	char *ret = s;
	while( '\0' != *s )
		++s;
	while( '\0' != *t )
	{
		switch( *t )
		{
			case '\n':
				*s++ = '\\';
				*s++ = 'n';
				break;
			case '\t':
				*s++ = '\\';
				*s++ = 't';
				break;
			case '\"':
				*s++ = '\\';
				*s++ = '\"';
				break;
			case '\'':
				*s++ = '\\';
				*s++ = '\'';
			default:
				*s++ = *t;
				break;
		}
		++t;
	}
	*s = '\0';
	return ret;
}
static char *unescape(char *s, char *t)
{
	char *ret = s;
	while( '\0' != *s )
		++s;
	while( '\0' != *t )
	{
		switch( *t )
		{
			case '\\':
				if( 'n' == *(t + 1) )
					*s++ = '\n';
				else if( 't' == *(t + 1) )
					*s++ = '\t';
				else if( '\"' == *(t + 1) )
					*s++ = '\"';
				else if( '\'' == *(t + 1) )
					*s++ = '\'';
				else
				{
					*s++ = '\\';
					*s++ = *(t + 1);
				}
				++t;
				break;
			default:
				*s++ = *t;
				break;
		}
		++t;
	}
	*s = '\0';
	return ret;
}
