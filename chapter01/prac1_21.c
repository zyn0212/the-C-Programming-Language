#include <stdio.h>
#define TABWIDTH 8
int entab(int c);
int main(int argc, char *argv[])
{
	if( argc < 2 )
	{
		int c = 0;
		while( EOF != (c = getchar()) )
		{
			entab(c);
		}
	}
	return 0;
}
int entab(int c)
{
	static int lastc = 'a', column = 0, countblank = 0;
	column += 1;
	if( ' ' != c )
	{
		if( 0 == countblank )
			putchar(c);
		else
		{
			printf("%s%c", "        " + TABWIDTH - countblank, c);
			countblank = 0;
		}
		if( '\n' == c )
			column = 0;
	}
	else
	{
		if( ' ' != lastc )
			countblank = 1;
		else
			countblank += 1;
		if( countblank > 0 && 0 == column % TABWIDTH )
		{
			putchar('\t');
			column = 0;
			countblank = 0;
		}
	}
	lastc = c;
	return 0;
}
