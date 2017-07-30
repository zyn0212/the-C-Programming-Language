#include <stdio.h>
#include <stdlib.h>
#define MAX 30
static int zbinsearch(int x, int *v, int n);
int main(int argc, char *argv[])
{
	if( 2 != argc )
		return 1;
	int match = 0, i = 0, array[30];
	for( i = 0; i < MAX; ++i )
		array[i] = i << 1;
	match = atoi(argv[1]);
	if( (i = zbinsearch(match, array, MAX)) > 0 )
		printf("matched %d int array's %dth element!\n", match, i);
	else
		printf("matched missed!\n");
	return 0;
}
static int zbinsearch(int x, int *v, int n)
{
	int *head = v, *tail = v + n - 1, *mid = v;
	while( head <= tail && *(mid = head + (tail - head >> 1)) != x )
	{
		if( x < *mid )
			tail = mid - 1;
		else
			head = mid + 1;
	}
	return head <= tail ? mid - v + 1: -1;
}
