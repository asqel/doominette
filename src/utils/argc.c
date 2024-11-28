#include "args.h"
#include "utils.h"
#include<string.h>

args_t	parse_args(int argc, char **argv)
{
	args_t	res = {0};
	int		i = 0;

	while (++i < argc)
	{
		if (!strcmp(argv[i], "-g"))
			res.g = 1;
		elif (!strcmp(argv[i], "-h") && i + 1 < argc)
			res.h = argv[++i];
		elif (!strcmp(argv[i], "-nof"))
			res.nof = 1;
		elif (!strcmp(argv[i], "-true"))
			res.True = 1;
		elif (!strcmp(argv[i], "-nod"))
			res.nod = 1;
		elif (!strcmp(argv[i], "-p"))
			res.nod = 1;
		elif (!strcmp(argv[i], "-r"))
			res.nod = 1;
	}

}
