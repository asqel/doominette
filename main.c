
#include "utils.h"

#include <stdio.h>
#include <stdlib.h>

int main(int argc, char **argv) {
	utils_init();
	printf("path: %s\n", doominette_dir);
	return 0;
}