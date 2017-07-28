#include <stdio.h>
#include <string.h>
#define MAXCOLUMN 30
#define MAXLEN 300
static void printstr(char *s, int column);
int main(int argc, char *argv[])
{
	if( 2 != argc )
		return 1;
	FILE *fp = fopen(argv[1], "r");
	if( NULL == fp )
		return 2;
	char tmp[MAXLEN + 1], *ret = NULL;
	do {
		ret = fgets(tmp, MAXLEN, fp);
		int length = strlen(tmp);
		int c = 0;
		if( '\n' != tmp[length - 1] )
		{
			while( '\n' != (c = getchar()) && EOF != c )
				NULL;
			tmp[MAXLEN - 1] = '\n';
		}
		printstr(tmp, MAXCOLUMN);
	} while( ret != NULL );
	return 0;
}
static void printstr(char *s, int column)
{
	int i = 0, blankloc = column, length = strlen(s);
	do {
		for( i = (column < length ? column : length) - 1; i >= 0; --i )
			if( '\n' == s[i] || '\t' == s[i] || ' ' == s[i] || ',' == s[i] || '.' == s[i] )
			{
				blankloc = i + 1;
				s += printf("%.*s\n", blankloc, s) - 1;
				break;
			}
	} while( (length -= blankloc) > 0 );
	return;
}
