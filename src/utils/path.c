#include <linux/limits.h>
#include <string.h>
#include <unistd.h>
#include <stdarg.h>
#include <stdlib.h>

char *doominette_dir = NULL;

char *get_path_dirname(char *path) {
	int i = 0;
	int last_slash = -1;

	while (path[i] != '\0') {
		if (path[i] == '\\' && path[i + 1] != '\0')
			i += 2;
		else if (path[i] == '/') {
			last_slash = i;
			i++;
		}
		else
			i++;
	}
	if (last_slash == -1)
		return strdup(".");

	char *res = malloc(sizeof(char) * (last_slash + 1));

	if (res == NULL)
		return NULL;

	for (int j = 0; j < last_slash; j++)
		res[j] = path[j];

	res[last_slash] = '\0';
	return res;
}

char *path_join(char **paths) {
	int total_len = 0;
	int i = 0;

	while (paths[i] != NULL) {
		total_len += strlen(paths[i]);
		i++;
	}
	total_len += i - 1;

	char *res = malloc(sizeof(char) * (total_len + 1));
	int end = 0;
	if (res == NULL)
		return NULL;

	for (int k = 0; k < i; k++) {
		strcpy(&(res[end]), paths[k]);
		end += strlen(paths[k]);
		if (k < i - 1) {
			res[end] = '/';
			end++;
		}
	}
	res[end] = '\0';

	return realloc(res, sizeof(char) * (end + 1));
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
	char *tmp = get_exe_abspath();
	doominette_dir = get_path_dirname(tmp);
	free(tmp);
}

void path_exit() {
	free(doominette_dir);
}