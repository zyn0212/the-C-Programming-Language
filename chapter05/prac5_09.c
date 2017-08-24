#include <stdio.h>
#include <stdlib.h>
static char daytab[2][13] = {
	{0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31,},
	{0, 31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31,},
};
static int dayofyear(int year, int month, int day);
static int monthofday(int year, int day, char *result);
int main(int argc, char *argv[])
{
	if( 4 != argc )
		return 1;
	char result[51];
	printf("%d/%02d/%02d is %dth day\n", atoi(argv[1]), atoi(argv[2]), atoi(argv[3]), dayofyear(atoi(argv[1]), atoi(argv[2]), atoi(argv[3])));
	if( 1 == monthofday(2017, 200, result) )
		printf("%s\n", result);
	return 0;
}
static int dayofyear(int year, int month, int day)
{
	char *p = 0 == (year & 3) && 0 != year % 100 || 0 == year % 400 ? daytab[1] : daytab[0];
	if( month < 1 || month > 12 || day < 1 || day > *(p + month) )
		return -1;
	while( --month > 0 )
		day += *(p + month);
	return day;
}
static int monthofday(int year, int day, char *result)
{
	char *p = 0 == (year & 3) && 0 != year % 100 || 0 == year % 400 ? daytab[1] : daytab[0];
	char *pp = p;
	int days = day;
	if( day < 0 || day > 365 + (daytab[1] == p ? 1 : 0) )
		return 0;
	for( ++p; day > *p; ++p )
		day -= *p;
	sprintf(result, "%dth day is %d/%02d/%02d", days, year, p - pp, day);
	return 1;
}
