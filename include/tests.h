#ifndef TESTS_H
#define TESTS_H

#include  <dlfcn.h>
#include "types.h"

typedef struct {
	char *dir_path;
	char *dir_name;
	char *ex_name; // standardized (ex C00 -> c00)
	void *lib_handle;
	char **stdout;
	char **stderr;
	u32 stdout_len;
	u32 stderr_len;
} test_info_t;

#endif