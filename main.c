
#include "utils.h"

#include <stdio.h>
#include <stdlib.h>
#include<unistd.h>

int main(int argc, char **argv) {
	int res[42] = {1, 0, 0, 1, 1, 0, 1, 0, 0, 1, 0, 1, 0, 1, 1, 0, 0, 0, 0, 1, 1, 0, 0, 0, 0, 0, 1, 0, 1, 1, 0, 1, 0, 0, 1, 1, 0, 1, 1, 0, 1, 1};

	utils_init();
	print_header();
	display_rs(1);
	display_rs(0);
	printf("\n");
	prnt_ko(res);
	return 0;
}