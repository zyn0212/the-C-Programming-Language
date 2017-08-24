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
	int leap = 0 == (year & 3) && 0 != year % 100 || 0 == year % 400 ? 1 : 0;
	if( month < 1 || month > 12 || day < 1 || day > daytab[leap][month] )
		return -1;
	while( --month > 0 )
		day += daytab[leap][month];
	return day;
}
static int monthofday(int year, int day, char *result)
{
	int leap = 0 == (year & 3) && 0 != year % 100 || 0 == year % 400 ? 1 : 0;
	int month = 0, days = day;
	if( day < 0 || day > 365 + leap )
		return 0;
	for( month = 1; day > daytab[leap][month]; ++month )
		day -= daytab[leap][month];
	sprintf(result, "%dth day is %d/%02d/%02d", days, year, month, day);
	return 1;
}
