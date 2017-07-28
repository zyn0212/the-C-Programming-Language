#include <stdio.h>
typedef enum Wordstatus { IN, OUT, } status;
int main(int argc, char *argv[])
{
		int c = 0;
		status isinword = OUT;
		while( EOF != (c = getchar()) )
		{
			if( '\t' == c || ' ' == c || '\n' == c || ',' == c || '.' == c )
			{
				if( IN == isinword )
				{
					putchar('\n');
					isinword = OUT;
				}
			}
			else
			{
				if( OUT == isinword )
					isinword = IN;
				putchar(c);
			}
		}
		printf("\n");
		return 0;
}
