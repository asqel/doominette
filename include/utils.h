#ifndef UTILS_H
#define UTILS_H

extern char *doominette_dir;
extern char *tests_dir;

char *get_exe_abspath();
char *get_path_dirname(char *path);
char *path_join(char **paths);
char *path_get_basename(char *path);

void utils_init();
void utils_exit();

void path_init();
void path_exit();

#endif