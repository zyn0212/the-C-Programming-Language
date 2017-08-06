#include <stdio.h>
int main(void)
{
	printf("%s\n", "cause convert integer to character will fix the high bit, such as 0xFFFFFFFF to 0xFF; but the high bit may be set to 0 by system, when convert back, such as 0xFF to 0x000000FF.");
	return 0;
}
