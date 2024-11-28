#include <stdio.h>
#include "std.h"
#include <stdarg.h>
#include "utils.h"
#include <stdarg.h>


void print_header(void)
{
	do_printf("\e[91m%s\e[0m", \
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
		do_printf("\e[31m✗\e[0m");
	if (result)
		do_printf("\e[32m✓\e[0m");
}

void	prnt_ko(int res[42])
{
	u8 is_error = 0;
	do_printf("\n\e[31m");
	for (int i = 0; i < 42; i++)
	{
		if (!res[i]){
			is_error = 1;
			do_printf("|%i", i + 1);
		}
	}
	if (is_error)
		do_printf("|");
	else
		do_printf("\e[32m|OK|");
	do_printf("\e[0m\n");
}

int do_printf(char *str, ...) {
	u8 was_redirected = do_redirect_stdout;
	std_state_t func_states = {0};
	save_std_func_state(func_states);
	enable_all_std();

	va_list args;
	va_start(args, str);
	int res = vprintf(str, args);
	va_end(args);

	load_std_func_state(func_states);
	do_redirect_stdout = was_redirected;
	return res;
}