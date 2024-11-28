#include "logs.h"
#include <stdlib.h>

char *logs = NULL;

void write_log(char *log) {
	logs = realloc(logs, strlen(logs) + strlen(log) + 1);
	strcat(logs, log);
}