#include <stdio.h>
#define TABWIDTH 8
int main(int argc, char *argv[])
{
	int c = 0, bitintab = 0;
	while( EOF != (c = getchar()) )
	{
		if( '\t' == c )
		{
			printf("%s", "        " + bitintab % TABWIDTH);
			bitintab = 0;
		}
		else
		{
			putchar(c);
			bitintab += 1;
		}
		if( '\n' == c )
			bitintab = 0;
	}
	return 0;
}
