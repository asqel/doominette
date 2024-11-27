#ifndef UTILS_H
#define UTILS_H

# define elif else if

extern char *doominette_dir;

char *get_exe_abspath();
char *get_path_dirname(char *path);
char *path_join(char **paths);

void utils_init();
void utils_exit();

void path_init();
void path_exit();

void print_header(void);
void	display_rs(int	result);
void	prnt_ko(int res[42]);

#endif