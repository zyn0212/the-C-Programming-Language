#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
static void detab(int c);
static void entab(int c);
int TABWIDTH = 8, TABSTART = 0;
char g_blanks[20];
typedef enum {
	IN, OUT
} e_blankstatus;
int main(int argc, char *argv[])
{
	FILE *inputfp = NULL;
	int c = 0;
	if( 2 == argc )
		inputfp = fopen(argv[1], "r");
	else if( 3 == argc ) {
		TABWIDTH = atoi(argv[1]);
		inputfp = fopen(argv[2], "r");
	}
	else if( 4 == argc ) {
		if( '-' == argv[1][0] )
			TABSTART = atoi(argv[1] + 1);
		if( '+' == argv[2][0] )
			TABWIDTH = atoi(argv[2] + 1);
		inputfp = fopen(argv[3], "r");
	}
	else {
		printf("Wrong arguments!\n");
		return 1;
	}

	for( c = 0; c < TABWIDTH; ++c )
		g_blanks[c] = ' ';
	g_blanks[c] = '\0';

	if( NULL == inputfp ) {
		printf("open %s failed!\n", argv[2]);
		return 2;
	}
	while( EOF != (c = getc(inputfp)) )
		entab(c);
	fclose(inputfp);
	return 0;
}
static void detab(int c)
{
	static int column = 0;
	int i = 0;
	if( '\t' != c ) {
		++column;
		putchar(c);
	}
	else {
		++column;
		for( i = column % TABWIDTH; column >= TABSTART && i < TABWIDTH; ++i )
			putchar(' ');
	}
	if( '\n' == c )
		column = 0;
	return;
}
static void entab(int c)
{
	static int column = 0, count = 0;
	int i = 0;
	e_blankstatus status = OUT;
	if( ' ' == c ) {
		++column;
		++count;
	}
	else {
		if( column >= TABSTART ) {
			for( i = 0; i < count / TABWIDTH; ++i )
				putchar('\t');
			printf("%s", g_blanks + TABWIDTH - count % TABWIDTH);
		}
		++column;
		putchar(c);
		status = OUT;
		count = 0;
	}
	if( '\n' == c )
		column = 0;
	return;
}
