#include <stdio.h>
static int getfloat(double *fp);
int main(void)
{
	double s = 0.0;
	if( 1 == getfloat(&s) )
		printf("%lf\n", s);
	else
		printf("getfloat wrong!\n");
	return 0;
}
static int getfloat(double *fp)
{
	int c = 0, countpoint = 0, sign = 0, last = 0;

	while( ' ' == (c = getchar()) || '\t' == c )
		NULL;
	if( '-' != c && '+' != c && '.' != c && !(c >= '0' && c <= '9') ) {
		ungetc(c, stdin);
		return 0;
	}
	sign = '-' == c ? -1 : 1;
	if( '-' == c || '+' == c ) {
		last = c;
		c = getchar();
	}
	if( c < '0' || c > '9' ) {
		ungetc(c, stdin);
		ungetc(last, stdin);
		return 0;
	}
	for( *fp = 0.0; c >= '0' && c <= '9' || '.' == c; c = getchar() ) {
		countpoint *= 10;
		if( '.' != c )
			*fp = *fp * 10 + c - '0';
		else if( 0 == countpoint )
			countpoint = 1;
		else
			return 0;
	}
	if( 0 != countpoint )
		*fp /= countpoint;
	if( 'e' != c && 'E' != c )
		return 1;
	sign = '-' == (c = getchar()) ? -1 : 1;
	if( '-' == c )
		getchar();
	for( countpoint = 0; c >= '0' && c <= '9'; c = getchar() )
		countpoint = countpoint * 10 + c - '0';
	while( countpoint-- > 0 )
		if( -1 == sign )
			*fp /= 10;
		else
			*fp *= 10;
	return 1;
}
