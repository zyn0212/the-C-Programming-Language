#include <stdio.h>
#define MAX 30
static void itoa(int n, char *s);
int main(int argc, char *argv[])
{
	char s[MAX];
	int n = 0x7abc7fdd;
	itoa(n, s);
	printf("%d = %s\n", n, s);
	return 0;
}
static void itoa(int n, char *s)
{
	static int loc = 0;
	if( n / 10 > 0 ) {
		itoa(n / 10, s);
		++loc;
	}
	s[loc] = n % 10 + '0';
	s[loc + 1] = '\0';
}
