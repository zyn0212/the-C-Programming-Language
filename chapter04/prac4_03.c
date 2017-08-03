#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <math.h>
#define MAX 100
typedef enum {
	NUMBER, PLUS, MINUS, TIMES, OVER, MOD, EQUAL, OTHER,
} type;
static type getinput(char *s);
static void push(double x);
static double pop(void);
int main(int argc, char *argv[])
{
	if( argc < 2 )
		return 1;
	int i = 0;
	double tmp = 0.0;
	for( i = 1; i < argc; ++i )
		switch( getinput(argv[i]) )
		{
			case NUMBER:
				push(atof(argv[i]));
				break;
			case PLUS:
				push(pop() + pop());
				break;
			case MINUS:
				tmp = pop();
				push(pop() - tmp);
				break;
			case TIMES:
				push(pop() * pop());
				break;
			case OVER:
				tmp = pop();
				if( tmp >= -0.0000000001 && tmp <= 0.0000000001 )
					exit(1);
				push(pop() / tmp);
				break;
			case MOD:
				tmp = pop();
				if( tmp >= -0.0000000001 && tmp <= 0.0000000001 )
					exit(1);
				push(fmod(pop(), tmp));
				break;
			case EQUAL:
				printf("Result = %lf\n", pop());
				return 0;
			break;
			default:
				break;
		}
	return 0;
}
static type getinput(char *s)
{
	while( ' ' == *s || '\t' == *s )
		NULL;
	char *tmp = s;
	if( 1 == isdigit(*tmp) )
		return NUMBER;
	else if( '+' == *tmp )
		return PLUS;
	else if( '-' == *tmp  && '\0' == *(tmp + 1) )
		return MINUS;
	else if( '-' == *tmp )
		return NUMBER;
	else if( '*' == *tmp )
		return TIMES;
	else if( '/' == *tmp )
		return OVER;
	else if( '%' == *tmp )
		return MOD;
	else if( '=' == *tmp )
		return EQUAL;
	else
		return OTHER;
}
static double numberstack[MAX];
static double *numbersp = numberstack;
static void push(double x)
{
	*numbersp++ = x;
}
static double pop(void)
{
	return *--numbersp;
}
