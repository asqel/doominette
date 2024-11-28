#include "utils.h"
#include <time.h>
#include <stdlib.h>
#include <std.h>
#include <logs.h>
#include <stdio.h>

void utils_init() {
	path_init();
	srand(time(NULL));
	atexit(&utils_exit);
	logs_path = path_join((char **){doominette_dir, "logs", NULL});
}

void utils_exit() {
	path_exit();
	if (c_stderr != NULL)
		free(c_stderr);
	if (c_stdout != NULL)
		free(c_stdout);
	if (logs != NULL)
		free(logs);
	FILE *f = fopen("/dev/null", "w");

}

char **str_split(char *str, char delim) {
	if (str == NULL)
		return NULL;

	int i = 0;
	int count = 0;


	while (str[i] != '\0') {
		if (str[i] == delim)
			count++;
		i++;
	}

	char **res = malloc(sizeof(char *) * (count + 1));
	int res_end = 0;
	if (res == NULL)
		return NULL;

	res[count] = NULL;

	i = 0;
	while (str[i] != '\0') {
		if (str[i] == delim)
			i++;
		else if ((i == 0 && str[i] != delim) || (i > 0 && str[i - 1] == delim)) {
			int len = 0;
			while (str[i + len] != '\0' && str[i + len] != delim)
				len++;
			res[res_end] = malloc(sizeof(char) * (len + 1));
			int k = 0;
			while (k < len)
				res[res_end][k++] = str[i + k];
			res[res_end][k] = '\0';
			res_end++;
			i += len;
		}
		else
			i++;
	}

	return res;
}

int uti_str_contain_line(char *big, char small) {
	char **lines = str_split(big, '\n');

	for (int i = 0; lines[i] != NULL; i++) {
		if (!strcmp(lines[i], small))
			return 1;
	}
	for (int i = 0; lines[i] != NULL; i++)
		free(lines[i]);
	free(lines);
	return 0;
}