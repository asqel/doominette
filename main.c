
#include "utils.h"

#include <stdio.h>
#include <stdlib.h>

char *get_real_name(char *name);

int main(int argc, char **argv) {
	utils_init();
	printf("path: %s\n", doominette_dir);
	get_real_name("");
	return 0;
}