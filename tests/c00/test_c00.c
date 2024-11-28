#include "tests.h"
#include <dlfcn.h>
#include "std.h"
#include "utils.h"
#include <stdio.h>



void	tst_put_char(void (*ft_putchar)(char c))
{
	char c;
	int i = -1;
	int res[42];
	u32 p_len;

	ENABLE_FUNC(STD_WRITE);

	if (try_std_funcs() == 0)
	{
		while (++i < 42)
		{

			c = randint(' ', '~' + 1);
			p_len = stdout_len;
			(*ft_putchar)(c);
			if (c_stdout[stdout_len - 1] == c && p_len + 1 == stdout_len){
				display_rs(1);
				res[i] = 1;
			}
			else{
				display_rs(0);
				res[i] = 0;
			}
		}
	}
	else{
		enable_all_std();
		do_printf("forbidden function called %d\n", last_disabled_called);
	}
	prnt_ko(res);
}

void	tst_put_str(void (*ft_putchar)(char c))
{
	char *str;
	int i = -1;
	int res[42];

	ENABLE_FUNC(STD_WRITE);

	if (try_std_funcs() == 0)
	{
		while (++i < 42)
		{
			str = rand_str();
			(*ft_putchar)(str);
			if (c_stdout[stdout_len - 1] == c){
				display_rs(1);
				res[i] = 1;
			}
			else{
				display_rs(0);
				res[i] = 0;
			}
		}
	}
	else{
		enable_all_std();
		do_printf("forbidden function called %d\n", last_disabled_called);
	}
	prnt_ko(res);
}


void	tester(test_info_t info)
{

	disable_all_std();
	ENABLE_STDOUT_REDIRECT();
	void (*ft_putchar)(char c) = dlsym(info.lib_handle, "ft_putchar");
	tst_put_char(ft_putchar);
	DISABLE_FUNC(STD_WRITE);
	DISABLE_STDOUT_REDIRECT();
}