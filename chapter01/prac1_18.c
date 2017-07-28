#include <stdio.h>
#include <string.h>
#define MAX 20
static int trimtail(char *s, int length);
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
		if( trimtail(input, linewidth) > 0 )
			printf("%s\n", input);
	} while( NULL != tmp );
	return 0;
}
static int trimtail(char *s, int length)
{
	int countblank = length - 1;
	length -= 2;
	while( '\t' == s[length] || ' ' == s[length] )
	{
		if( ' ' == s[length] )
			--countblank;
		--length;
	}
	if( 0 == countblank )
		return 0;
	s[length + 1] = '\0';
	return length + 1;
}
