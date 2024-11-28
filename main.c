#include "utils.h"

#include <stdio.h>
#include <stdlib.h>
#include<unistd.h>
#include <dlfcn.h>
#include "std.h"
#include "args.h"


int main(int argc, char **argv) {
	utils_init();
	//args_t args = parse_argc(argc, argv);
	void *p = dlopen("./put_char.so", RTLD_LAZY);
	void *tester = dlopen("./tests/c00/tester.so", RTLD_LAZY);
	
	return 0;
}