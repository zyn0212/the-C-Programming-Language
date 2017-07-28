#include <stdio.h>
#include <string.h>
#define MAX 100
static int GetStreamLine(FILE *file, char *result, int max);
int main(int argc, char *argv[])
{
	char result[MAX] ={'\0'};
	if( argc < 2 )
	{
		int c = 0, len = 0;
		while( (len = GetStreamLine(NULL, result, MAX)) > 0 )
			printf("%d: %s\n", len, result);
		return 0;
	}
	else
	{
		FILE *file = NULL;
		int len = 0;
		while( --argc > 0 )
		{
			if( NULL == (file = fopen(argv[argc], "r")) )
				return 1;
			while( (len = GetStreamLine(file, result, MAX)) > 0 )
				printf("%d: %s\n", len, result);
			fclose(file);
		}
		return 0;
	}
}
int GetStreamLine(FILE *file, char *result, int max)
{
	static int eofflag = 1;
	if( 0 == eofflag )
		return 0;
	int i = 0, c = 0;
	if( NULL == file )
		while( i < max && EOF != (c = getchar()) && '\n' != c )
			result[i++] = c;
	else
		while( i < max && EOF != (c = getc(file)) && '\n' != c )
			result[i++] = c;
	result[i] = '\0';
	if( EOF == c && 0 != i )
		eofflag = 0;
	return i;
}
