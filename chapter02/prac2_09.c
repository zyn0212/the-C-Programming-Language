#include <stdio.h>
#include <stdlib.h>
static int bitcount(int n);
int main(int argc, char *argv[])
{
	if( 2 != argc )
		return 1;
	printf("program matched %d one int %s!\n", bitcount(atoi(argv[1])), argv[1]);
	return 0;
}
static int bitcount(int n)
{
	int i = 0;
	for( i = 0; n > 0; ++i )
		n &= n - 1;
	return i;
}
