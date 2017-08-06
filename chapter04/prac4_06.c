#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include <math.h>
#define MAX 100
typedef enum {
	NUMBER, PLUS, MINUS, TIMES, OVER, MOD, EQUAL, OTHER, SHOW, COPY, SWAP,
	CLEAR, SIN, EXP, POW, VAR, MEMORY, ALPHA,
} type;
static type getinput(char *s);
static void push(double x);
static double pop(void);
static void ShowHead(void);
static void cleanstack();
int main(int argc, char *argv[])
{
	if( argc < 2 )
		return 1;
	int i = 0;
	double tmp = 0.0, tmp2 = 0.0, memory[27];
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
			case SHOW:
				ShowHead();
				break;
			case COPY:
				tmp = pop();
				push(tmp);
				push(tmp);
				break;
			case SWAP:
				tmp = pop();
				tmp2 = pop();
				push(tmp);
				push(tmp2);
				break;
			case CLEAR:
				cleanstack();
				break;
			case SIN:
				push(sin(pop()));
				break;
			case EXP:
				tmp = pop();
				if( tmp >= -0.0000000001 && tmp <= 0.0000000001 )
					exit(2);
				push(exp(tmp));
				break;
			case POW:
				tmp = pop();
				push(pow(pop(), tmp));
				break;
			case EQUAL:
				printf("Result = %lf\n", pop());
				return 0;
			break;
			case VAR:
				memory[*++argv[i] - 'A'] = pop();
				push(memory[*argv[i] - 'A']);
				break;
			case ALPHA:
				push(memory[*argv[i] - 'A']);
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
	else if( '?' == *tmp )
		return SHOW;
	else if( 'd' == *tmp )
		return COPY;
	else if( 's' == *tmp )
		return SWAP;
	else if( 'c' == *tmp )
		return CLEAR;
	else if( '@' == *tmp )
		return SIN;
	else if( 'e' == *tmp )
		return EXP;
	else if( 'p' == *tmp )
		return POW;
	else if( '>' == *tmp && *(tmp + 1) >= 'A' && *(tmp + 1) <= 'Z' )
		return VAR;
	else if( *tmp >= 'A' && *tmp <= 'Z' )
		return ALPHA;
	else
		return OTHER;
}
static double numberstack[MAX];
static double *numbersp = numberstack;
static double * const numberstackend = numberstack;
static void push(double x)
{
	*numbersp++ = x;
}
static double pop(void)
{
	if( numbersp > numberstackend )
		return *--numbersp;
	else
		exit(2);
}
static void ShowHead(void)
{
	if( numbersp > numberstackend )
	printf("Now, the head of stack is %lf\n", *(numbersp - 1));
	else
		exit(2);
}
static void cleanstack()
{
	memset(numberstackend, 0, sizeof(double) * MAX);
	numbersp = numberstack;
}
