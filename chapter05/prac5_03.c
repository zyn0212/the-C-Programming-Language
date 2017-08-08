#include <stdio.h>
static char *zstrcat(char *des, char *res);
int main(int argc, char *argv[])
{
	if( 3 != argc )
		return 1;
	printf("%s\n", zstrcat(argv[1], argv[2]));
	return 0;
}
static char *zstrcat(char *des, char *res)
{
	char *ret = des;
	while( '\0' != *des )
		++des;
	while( '\0' != (*des++ = *res++) )
		NULL;
	return ret;
}
