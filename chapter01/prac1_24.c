#include <stdio.h>
#include <stdlib.h>
void rcomment(int c, FILE *fp);
void incomment(FILE *fp);
void echoquote(int c, FILE *fp);
void doublecomment(FILE *fp);
void match(int c);
int getresult(void);
int main(int argc, char *argv[])
{
	if( argc < 2 )
		return 1;
	FILE *fp = NULL;
	int c = 0;
	while( --argc > 0 )
	{
		fp = fopen(argv[argc], "r");
		if( NULL == fp )
			continue;
		while( EOF != (c = getc(fp)) )
			rcomment(c, fp);
		fclose(fp);
	}
	if( 0 == getresult() )
		printf("no error!\n");
	else
		printf("find error!\n");
	return 0;
}
void rcomment(int c, FILE *fp)
{
	int next = 0;
	if( '/' == c )
		if( '*' == (next = getc(fp)) )
			incomment(fp);
		else if( '/' == next )
			doublecomment(fp);
		else
		{
			match(c);
			match(next);
		}
	else if( '"' == c || '\'' == c )
		echoquote(c, fp);
	else
		match(c);
}
void incomment(FILE *fp)
{
	int last = 0, c = 0;
	last = getc(fp);
	if( EOF == last )
		exit(1);
	c = getc(fp);
	if( EOF == c )
		exit(1);
	while( last != '*' || '/' != c )
	{
		last = c;
		c = getc(fp);
	}
}
void echoquote(int c, FILE *fp)
{
	int next = 0;
	match(c);
	while( c != (next = getc(fp)) )
	{
		if( EOF == next )
			exit(1);
		else if( '\\' == next )
			match(getc(fp));
	}
	match(c);
}
void doublecomment(FILE *fp)
{
	int last = 0, c = getc(fp);
	while( '\n' != c || '\\' == last )
	{
		last = c;
		c = getc(fp);
	}
}
static int brace = 0, brack = 0, paren = 0;
void match(int c)
{
	switch( c )
	{
		case '{':
			++brace;
			break;
		case '}':
			--brace;
			break;
		case '[':
			++brack;
			break;
		case ']':
			--brack;
			break;
		case '(':
			++paren;
			break;
		case ')':
			--paren;
			break;
		default:
			break;
	}
	return;
}
int getresult(void)
{
	return brace + brack + paren;
}
