#include <stdio.h>
int main(void)
{
	int c = 0, nb = 0, nt = 0, nl = 0;
	while( EOF != (c = getchar()) )
		switch( c )
		{
			case ' ':
				nb += 1;
				break;
			case '\t':
				nt += 1;
				break;
			case '\n':
				nl += 1;
				break;
			default:
				break;
		}
	printf("your input has %2d blank, %2d table, %2d newline\n", nb, nt, nl);
	return 0;
}
