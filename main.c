#include "utils.h"

#include <stdio.h>
#include <stdlib.h>
#include<unistd.h>
#include <dlfcn.h>
#include "std.h"

char *get_real_name(char *name);


int main(int argc, char **argv) {
	int res[42] = {1, 0, 0, 1, 1, 0, 1, 0, 0, 1, 0, 1, 0, 1, 1, 0, 0, 0, 0, 1, 1, 0, 0, 0, 0, 0, 1, 0, 1, 1, 0, 1, 0, 0, 1, 1, 0, 1, 1, 0, 1, 1};

	utils_init();
}