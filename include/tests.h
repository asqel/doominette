#ifndef TESTS_H
#define TESTS_H

#include  <dlfcn.h>

typedef struct {
	char *dir_path;
	char *dir_name;
	char *ex_name; // standardized (ex C00 -> c00)
	void *lib_handle;
} test_info_t;

#endif