#ifndef LOGS_H
#define LOGS_H

extern char *logs;

void write_log(char *log);
void log_printf(char *str, ...);

#endif