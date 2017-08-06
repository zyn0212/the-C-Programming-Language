#include <stdio.h>
#include <string.h>
#define MAX 200
static void reverse(char *s);
int main(int argc, char *argv[])
{
	if( 2 != argc ) {
		printf("wrong argument!\n");
		return 1;
	}
	char s[MAX];
	strncpy(s, argv[1], MAX - 1);
	printf("%s\n", s);
	reverse(s);
	printf("%s\n", s);
	return 0;
}
static void reverse(char *s)
{
	if( NULL == s || '\0' == *s )
		return;
	static int loc = 0, n = 0;
	char c = s[loc];
	if( '\0' != s[loc + 1] ) {
		++loc;
		reverse(s);
	}
	s[n] = c;
	s[++n] = '\0';
}
