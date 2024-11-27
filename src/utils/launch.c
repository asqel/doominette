#include <dlfcn.h>
#include <stdlib.h>

int launch_test_at(char *path) {
	if (path == NULL)
		return 0;

	char *name = path_get_basename(path);

	return 0;
}