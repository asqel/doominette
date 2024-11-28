#include "tests.h"
#include <dlfcn.h>
#include "std.h"
#include "utils.h"

test_info_t g_info;

void	tst_put_char(void (*ft_putchar)(char c))
{
	char c;
	int i = -1;
	int res[42];

	disable_all_std();
	ENABLE_FUNC(STD_WRITE);

	if (try_std_funcs() == 0) 
	{
		while (++i < 42)
		{
			c = randint(' ', '~' + 1);
			(*ft_putchar)(c);
			if (g_info.stdout[g_info.stdout_len - 1] == c){
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
		printf("forbidden function called %d\n", last_disabled_called);
	}
	prnt_ko(res);
}

void	tester(test_info_t info)
{
	char c;;
	g_info = info;

	disable_all_std();
	void (*ft_putchar)(char c) = dlsym(info.lib_handle, "ft_putchar");
	c = randint(' ', '~' + 1);
	tst_put_char(c, ft_putchar);
}