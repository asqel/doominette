#include "utils.h"
#include <stdlib.h>
#include <dirent.h>


char *get_real_name(char *name) {
	char **dirs = NULL;

	// get contents of directory
	DIR *dir = opendir(tests_dir);
	if (dir == NULL)
		return NULL;

	struct dirent *entry;
	while ((entry = readdir(dir)) != NULL) {
		if (entry->d_type == DT_DIR) {
			do_printf("dir: %s\n", entry->d_name);
		}
	}
	return NULL;
}