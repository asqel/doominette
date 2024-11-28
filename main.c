#include "utils.h"

#include <stdio.h>
#include <stdlib.h>
#include<unistd.h>
#include <dlfcn.h>
#include "std.h"
#include "args.h"
#include "tests.h"


int main(int argc, char **argv) {
	utils_init();
	//args_t args = parse_argc(argc, argv);
	void *p = dlopen("./put_char.so", RTLD_LAZY | RTLD_GLOBAL);
	void *tester = dlopen("./tests/c00/tester.so", RTLD_LAZY | RTLD_GLOBAL);
					test_info_t info = {0};
	void (*tester_f)(test_info_t info) = dlsym(tester, "tester");

	info.lib_handle = p;
	tester_f(info);

	return 0;
}