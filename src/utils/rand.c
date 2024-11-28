#include <stdlib.h>
#include "types.h"
#include "std.h"

int randint(int a, int b)
{
	return rand() / (double)(RAND_MAX) * (b - a) + a;
}

char *rand_str(void)
{
	char *res;
	u16 size;
	int	i = -1;

	size = randint(1, 65000);
	res = do_malloc(size + 1);	
	while (++i < size)
		res[i] = randint(' ', '~' + 1);
	res[i] = 0;
	return (res);
}