#include <stdlib.h>


int randint(int a, int b)
{
	return rand() / (double)(RAND_MAX) * (b - a) + a;
}

char *rand_str(void)
{
	char *res;

	
}