#include <linux/limits.h>
#include <string.h>
#include <unistd.h>


char *get_path_dirname(char *path) {
	int i = 0;
	int last_slash = -1;

	while (path[i] != '\0') {
		if (path[i] == '\\' && path[i + 1] != '\0')
			i += 2;
		else if (path[i] == '/')
			last_slash = i;
		else
			i++;
	}
}

char *get_exe_abspath() {
	char *path = NULL;
	char buf[PATH_MAX] = {0};

	ssize_t len = readlink("/proc/self/exe", buf, sizeof(buf) - 1);

	if (len > 0) {
		buf[len] = '\0';
		path = strdup(buf);
	}

	return path;
}

void path_init() {

}

void path_exit() {
}