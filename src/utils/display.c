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
