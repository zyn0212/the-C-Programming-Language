#include <stdio.h>
#include <string.h>
#define MAX 20
static void revertstr(char *s, int length);
int main(int argc, char *argv[])
{
	char input[MAX];
	char *tmp = NULL;
	int length = 0;
	do {
		tmp = fgets(input, MAX, stdin);
		int linewidth = strlen(input);
		if( MAX - 1 == linewidth && '\n' != input[MAX - 2] )
		{
			while( '\n' != getchar() )
				NULL;
			input[MAX - 2] = '\n';
			input[MAX - 1] = '\0';
			printf("input overflow %d\n", MAX - 1);
		}
		revertstr(input, linewidth);
	} while( NULL != tmp );
	return 0;
}
static void revert(char *s, int length)
{
	if( length > 0 )
		revert(s + 1, length - 1);
	printf("%c", *s);

}
static void revertstr(char *s, int length)
{

	printf("%d\n", length);

	revert(s, length - 2);
	putchar(s[length - 1]);
}
