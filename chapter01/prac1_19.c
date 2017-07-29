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
		printf("%s\n", input);
	} while( NULL != tmp );
	return 0;
}
static void revertstr(char *s, int length)
{

	char *head = s, *tail = s;
	while( '\0' != *tail && '\n' != *tail )
		++tail;
	--tail;
	while( head < tail )
	{
		*head ^= *tail ^= *head ^= *tail;
		++head;
		--tail;
	}
}
