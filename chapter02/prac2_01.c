#include <stdio.h>
int main(void)
{
	printf("signed char is %d to %d\n", (signed char)(1 << 7), (signed char)(~0 & ~(1 << 7)));
	printf("unsigned char is 0 to %d\n", (unsigned char)(~1 | 1));
	printf("signed short is %d to %d\n", (signed short)(1 << 15), (signed short)((~0) & ~(1 << 15)));
	printf("unsigned short is 0 to %d\n", (unsigned short)(~1 | 1));
	printf("signed int is %d to %d\n", (signed int)(1 << 31), (signed int)((~0) & ~(1 << 31)));
	printf("unsigned int is 0 to %u\n", (unsigned int)(~1 | 1));
	printf("signed long is %ld to %ld\n", (signed long)1 << 63, (signed long)~0 & ~((signed long)1 << 63));
	printf("unsigned long is 0 to %lu\n", ~(unsigned long)0);
	return 0;
}
