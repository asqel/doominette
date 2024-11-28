#include <stdio.h>
#include "std.h"

void print_header(void)
{
	printf("\e[91m%s\e[0m", \
	"██████╗  ██████╗  ██████╗ ███╗   ███╗██╗███╗   ██╗███████╗████████╗███████╗ \n"\
	"██╔══██╗██╔═══██╗██╔═══██╗████╗ ████║██║████╗  ██║██╔════╝╚══██╔══╝██╔════╝ \n"\
	"██║  ██║██║   ██║██║   ██║██╔████╔██║██║██╔██╗ ██║█████╗     ██║   █████╗   \n"\
	"██║  ██║██║   ██║██║   ██║██║╚██╔╝██║██║██║╚██╗██║██╔══╝     ██║   ██╔══╝   \n"\
	"██████╔╝╚██████╔╝╚██████╔╝██║ ╚═╝ ██║██║██║ ╚████║███████╗   ██║   ███████╗ \n"\
	"╚═════╝  ╚═════╝  ╚═════╝ ╚═╝     ╚═╝╚═╝╚═╝  ╚═══╝╚══════╝   ╚═╝   ╚══════╝ \n"\
	);
}

void	display_rs(int	result)
{
	if (!result)
		printf("\e[31m✗\e[0m");
	if (result)
		printf("\e[32m✓\e[0m");
}

void	prnt_ko(int res[42])
{
	printf("\e[31m");
	for (int i = 0; i < 42; i++)
	{
		if (!res[i])
			printf("|%i", i + 1);
	}
	printf("|");
	printf("\e[0m");
}

int do_printf(char *str, ...) {
	std_state_t func_states = {0};
	save_std_func_state(func_states);
	enable_all_std();

	va_list args;
	va_start(args, str);
	int res = vprintf(str, args);
	va_end(args);

	load_std_func_state(func_states);
	return res;
}