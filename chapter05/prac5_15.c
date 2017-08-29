#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include <ctype.h>
#define MAXLEN 80
int DESCREASE = -1, INCREASE = 1;
int g_ignoreLU = 0;
static int Bubble_sort(void *base, int n, int size, int (*compare)(void *, void *), int sortflag);
static int z_strcmp(void *a, void *b);
static void swap(void *a, void *b, int size);
int main(int argc, char *argv[])
{
	int i = 0, j = 0, length = 0;
	char *unsorted = malloc(MAXLEN * 16 * sizeof(char));
	char *unsortedcp[16];
	int flag = 1;
	if( 2 == argc ) {
		if( 0 == strcmp("-r", argv[1]) )
			flag = DESCREASE;
		else if( 0 == strcmp("-n", argv[1]) )
			flag = INCREASE;
		else if( 0 == strcmp("-f", argv[1]) )
			g_ignoreLU = 1;
		else {
			printf("Wrong parameter!\n");
			return 2;
		}
	}
	else if( 3 == argc ) {
		if( 0 == strcmp("-r", argv[1]) )
			flag = DESCREASE;
		else if( 0 == strcmp("-n", argv[1]) )
			flag = INCREASE;
		else if( 0 == strcmp("-f", argv[1]) )
			g_ignoreLU = 1;
		else {
			printf("Wrong parameter!\n");
			return 2;
		}
		if( 0 == strcmp("-r", argv[2]) )
			flag = DESCREASE;
		else if( 0 == strcmp("-n", argv[2]) )
			flag = INCREASE;
		else if( 0 == strcmp("-f", argv[2]) )
			g_ignoreLU = 1;
		else {
			printf("Wrong parameter!\n");
			return 2;
		}
	}
	if( NULL == unsorted ) {
		printf("malloc meet fatal error!\n");
		return 1;
	}
	putchar('\n');
	srand(time(0));
	for( i = 0; i < 16; ++i ) {
		unsortedcp[i] = unsorted + i * sizeof(char) * MAXLEN;
		length = rand() % 79 + 1;
		for( j = 0; j < length; ++j ) {
			unsortedcp[i][j] = rand() % 26 + (0 == (rand() & 1) ? 65 : 97);
			if( 0xFF == (rand() & 0xFF) )
				break;
		}
		unsortedcp[i][j] = '\0';
	}
	if( Bubble_sort(unsortedcp, 16, sizeof unsortedcp[0], &z_strcmp, flag) < 0 )
		printf("Bubble_sort meet fatal error!\n");
	else
		for( i = 0; i < 16; ++i )
			printf("%s\n", unsortedcp[i]);
	putchar('\n');
	free(unsorted);
	return 0;
}
static int Bubble_sort(void *base, int n, int size, int (*compare)(void *, void *), int sortflag)
{
	if( NULL == base || n < 2 || size < 1 || NULL == compare || DESCREASE != sortflag && INCREASE != sortflag )
		return -1;
	char *p = (char*)base;
	int i = 0, j = 2, change = 0;
	for( i = 0; i < n - 1; ++i ) {
		change = 0;
		for( j = 0; j < n - 1 - i; ++j )
			if( compare(p + size * j, p + size * (j + 1)) * sortflag < 0 ) {
				swap(p + size * j, p + size * (j + 1), size);
				++change;
			}
		if( 0 == change )
			break;
	}
	return 1;
}
static int z_strcmp(void *a, void *b)
{
	char *t_a = *(char**)a;
	char *t_b = *(char**)b;
	if( 0 != g_ignoreLU ) {
		while( tolower(*t_a) == tolower(*t_b) ) {
			if( '\0' == *t_a )
				return 0;
			++t_a;
			++t_b;
		}
		return tolower(*t_a) - tolower(*t_b);
	}
	else
		return strcmp(t_a, t_b);
}
static void swap(void *a, void *b, int size)
{
	char *tmp = malloc(size);
	if( NULL == tmp )
		exit(1);
	memcpy(tmp, a, size);
	memcpy(a, b, size);
	memcpy(b, tmp, size);
	free(tmp);
}
