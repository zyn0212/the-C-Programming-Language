/*printf celsiut convert to fahr */
#include <stdio.h>
int main(void)
{
	int celsius = 0;
	printf("=================================================\n\
		the list of celsius converting to fahr\ncelsius\t\tfahr\n");
	for( celsius = 0; celsius <= 300; celsius += 20 )
		printf("%03d\t\t%6.2f\n", celsius, 9.0 / 5 * celsius + 32);
	printf("=================================================\n");
	return 0;
}
