#include "utils.h"

#include <stdio.h>
#include <stdlib.h>
#include<unistd.h>
#include <dlfcn.h>
#include "std.h"
#include "args.h"


int main(int argc, char **argv) {
	utils_init();
	args_t args = parse_args(argc, argv);

	return 0;
}