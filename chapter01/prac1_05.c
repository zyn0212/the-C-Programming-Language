/*printf fahr convert to celsius */
#include <stdio.h>
int main(void)
{
	int fahr = 0;
	printf("=================================================\nthe list of fahr converting to celsius\nfahr\tcelsius\n");
	for( fahr = 300; fahr >= 0; fahr -= 20 )
		printf("%03d\t%6.2f\n", fahr, (5.0 / 9) * (fahr - 32));
	printf("=================================================\n");
	return 0;
}
