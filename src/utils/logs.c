#include "logs.h"
#include <stdlib.h>
#include <stdarg.h>
#include <stdio.h>

char *logs = NULL;

void write_log(char *log) {
	logs = realloc(logs, strlen(logs) + strlen(log) + 1);
	strcat(logs, log);
}

void log_printf(char *str, ...)	{
	va_list args;
	va_list args2;
	va_start(args, str);
	va_copy(args2, args);
	int len = vsprintf(NULL, str, args);

	logs = realloc(logs, strlen(logs) + len + 1);
	vsprintf(&(logs[strlen(logs)]), str, args2);

	va_end(args);
	va_end(args2);
}