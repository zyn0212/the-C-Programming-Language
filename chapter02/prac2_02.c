//for( i = 0 i < lim - 1 && (c = getchar()) != '\n' && c != EOF; ++i )
#include <stdio.h>
#define LIMIT 30
int main(void)
{
	int i = 0, c = 0;
	for( i = 0; i < LIMIT - 1; ++i )
	{
		if( EOF == (c = getchar()) )
			break;
		else if( '\n' == c )
			break;
		else
			putchar(c);
	}
	return 0;
}
