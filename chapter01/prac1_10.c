#include <stdio.h>
int main(void)
{
	int c = 0;
	while( EOF != (c = getchar()) )
	{
		switch( c )
		{
			case '\t':
				printf("\\t");
				break;
			case '\b':
				printf("\\b");
				break;
			case '\\':
				printf("\\\\");
				break;
			default:
				putchar(c);
				break;
		}
	}
	return 0;
}
