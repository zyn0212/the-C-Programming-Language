#include <stdio.h>
#define MAX 100000
#define MIN -100000
static void PrintTem(int from, int to, int step);
int main(void)
{
	int max = 0, min = 0, step = 0;
	printf("input from, to, step:");
	scanf("%d,%d,%d", &min, &max, &step);
	PrintTem(min, max, step);
	return 0;
}
static void PrintTem(int from, int to, int step)
{
	int end = 0;
	if( from < to && (from < MIN || to > MAX) || from > to && (to < MIN || from > MAX) )
		return;
	if( from < to )
		step = step > 0 ? step : -step;
	else
		step = step > 0 ? -step : step;
	int i = 0;
	printf("the list of converting fahr to celsius:\nfahr\t  celsius\n");
	for( i = from; from < to && i < to || from > to && i > to; i += step )
		printf("%4d\t% 9.3f\n", i, 5.0 * (i - 32) / 9.0);
	return;
}
