#include "utils.h"

#include <stdio.h>
#include <stdlib.h>
#include<unistd.h>
#include <dlfcn.h>
#include "std.h"

char *get_real_name(char *name);


int main(int argc, char **argv) {
	int res[42] = {1, 0, 0, 1, 1, 0, 1, 0, 0, 1, 0, 1, 0, 1, 1, 0, 0, 0, 0, 1, 1, 0, 0, 0, 0, 0, 1, 0, 1, 1, 0, 1, 0, 0, 1, 1, 0, 1, 1, 0, 1, 1};

	//tils_init();
	DISABLE_FUNC(STD_FREE);
	if (try_std_funcs() == 0) {
		free(malloc(1));
	}
	else {
		ENABLE_FUNC(STD_FREE);
		printf("malloc disabled %d\n", last_disabled_called);
	}
	return 0;
}