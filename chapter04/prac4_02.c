#include <stdio.h>
#include <math.h>
#define MAX 100
static double zatof(char *s);
int main(int argc, char *argv[])
{
	char s[MAX] = "1.2345673e9";
	printf("%f\n", zatof(s));
	return 0;
}
static double zatof(char *s)
{
	double result = 0.0;
	int sign = 0, countpoint = -1;
	while( ' ' == *s || '\t' == *s )
		++s;
	if( '-' == *s )
	{
		sign = 1;
		++s;
	}
	while( 'e' != *s && 'E' != *s && '\0' != *s && (*s >= '0' && *s <= '9'  || '.' == *s) )
	{
		if( countpoint > -1 )
			++countpoint;
		if( '.' == *s )
			if( -1 == countpoint )
				countpoint = 0;
			else
				return 0.0;
		else
			result = 10 * result + *s - '0';
		++s;
	}
	result = 1 == sign ? -result : result;
	while( countpoint-- > 0 )
		result /= 10;
	if( 'e' == *s || 'E' == *s )
	{
		++s;
		if( '-' == *s )
		{
			sign = 1;
			s++;
		}
		countpoint = 0;
		while( '\0' != *s && *s >= '0' && *s <= '9' )
			countpoint = countpoint * 10 + *s++ - '0';
		countpoint = 1 == sign ? -countpoint : countpoint;
		return result * pow(10, countpoint);
	}
		NULL;
	return result;
}
