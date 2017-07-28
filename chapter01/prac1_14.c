#include <stdio.h>
#include <string.h>
#include <ctype.h>
#define MAXLEN 27
#define MAXVALUE 30
typedef enum histogramtype {
	HOR, VER,
} histype;
static void PrintHistogram(int input[], int n, int maxvalue, histype type);
int main(int argc, char *argv[])
{
	int result[MAXLEN] = {0};
	int c = 0, len = 0;
	if( argc < 2 )
	{
		while( EOF != (c = getchar()) )
			if( isalpha(c) )
				++result[tolower(c) - 'a'];
	PrintHistogram(result, MAXLEN, MAXVALUE, VER);
	}
	else if( 3 == argc )
	{
		histype type;
		if( 0 == strcmp("-h", argv[2]) || 0 == strcmp("-H", argv[2]) )
			type = HOR;
		else if( 0 == strcmp("-v", argv[2]) || 0 == strcmp("-V", argv[2]) )
			type = VER;
		else
		{
			printf("Wrong argument!\n");
			return 1;
		}
		FILE *fp = fopen(argv[1], "r");
		if( NULL == fp )
		{
			printf("fopen failed!\n");
			return 2;
		}
		while( EOF != (c = getc(fp)) )
			if( isalpha(c) )
				++result[tolower(c) - 'a'];
		PrintHistogram(result, MAXLEN, MAXVALUE, type);
		fclose(fp);
	}
	else
		printf("unsupported argument!\n");
	return 0;
}
static void PrintHistogram(int input[], int n, int maxvalue, histype type)
{
	int i = 0, max = 0, j = 0;
	int tmp[MAXLEN];
	for( i = 0; i < n; ++i )
		max = input[i] > max ? input[i] : max;
	for( i = 0; i < n; ++i )
		tmp[i] = (input[i] * maxvalue) / max;
	if( VER == type )
	{
		for( i = maxvalue; i > 0; --i )
		{
			for( j = 1; j < n; ++j )
				printf(" %s ", input[j] >= i ? "=" : " ");
			putchar('\n');
		}
		for( j = 1; j < n; ++j )
			printf(" %c ", j + 'a');
		putchar('\n');
	}
	else
		for( i = 1; i < n; ++i )
		{
			printf("%c:", i + 'a');
			for( j = 0; j < tmp[i]; ++j )
				putchar('|');
			putchar('\n');
		}
	return;
}
