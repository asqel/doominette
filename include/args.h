#ifndef ARGS_H
# define ARGS_H

# include"types.h"

typedef struct
{
	u8	g;
	char *h;
	u8	nof;
	u8	True;
	u8	nod;
	u8	p;
	u8	r;
}args_t;

args_t	parse_args(int argc, char **argv);

#endif