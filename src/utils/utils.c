#include "utils.h"
#include <stdlib.h>

void utils_init() {
	path_init();
	atexit(&utils_exit);
}

void utils_exit() {
	path_exit();
}