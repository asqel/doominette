#ifndef UTILS_H
#define UTILS_H

# define elif else if

extern char *doominette_dir;
extern char *tests_dir;
extern char *logs_path;

char *get_exe_abspath();
char *get_path_dirname(char *path);
char *path_join(char **paths);
char *path_get_basename(char *path);

void utils_init();
void utils_exit();

void path_init();
void path_exit();

void	print_header(void);
void	display_rs(int	result);
void	prnt_ko(int res[42]);
int 	do_printf(char *str, ...);
int		randint(int a, int b);

#endif