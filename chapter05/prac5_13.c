#include <stdio.h>
#include <stdlib.h>
#define MAX 1024
int OUTPUTLINE = 8;
typedef struct lineinput {
	char *line;
	struct lineinput *next;
} s_input;
static void tail(FILE *fp);
int main(int argc, char *argv[])
{
	FILE *inputfp = NULL;
	char *outputstart = NULL;
	int i = 0;
	s_input *head = NULL, *current = NULL, *prev = NULL;
	if( 2 == argc )
		inputfp = fopen(argv[1], "r");
	else if( 3 == argc ) {
		if( '-' == argv[1][0]  && (OUTPUTLINE = atoi(argv[1] + 1)) < 1 )
			OUTPUTLINE = 10;
		inputfp = fopen(argv[2], "r");
	}
	else {
		printf("Wrong argumenst!\n");
		return 1;
	}
	if( NULL == (outputstart = (char*)calloc(OUTPUTLINE * MAX, sizeof(char))) ) {
		printf("malloc failed!\n");
		fclose(inputfp);
		return 2;
	}
	if( NULL == (head = (s_input*)malloc(OUTPUTLINE * sizeof(s_input))) ) {
		printf("malloc struct failed!\n");
		free(outputstart);
		fclose(inputfp);
		return 3;
	}
	for( i = 0; i < OUTPUTLINE - 1; ++i ) {
		head[i].line = outputstart + MAX * i;
		head[i].next = head + i + 1;
	}
	head[i].line = outputstart + MAX * i;
	head[i].next = head;
	current = head;
	while( NULL != fgets(current->line, MAX, inputfp) ) {
		prev = current;
		current = current->next;
	}
	prev->next = NULL;

	if( 0 == feof(inputfp) )
		printf("Program got fatal error!\n");
	else
		do {
			if( NULL != current->line )
				printf("%s", current->line);
			current = current->next;
		} while( NULL != current );
	free(head);
	free(outputstart);
	fclose(inputfp);
	return 0;
}
