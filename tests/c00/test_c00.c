#include "tests.h"
#include <dlfcn.h>
#include "std.h"
#include "utils.h"
#include <stdio.h>
#include <string.h>


void	tst_put_char(void (*ft_putchar)(char c))
{
	char c;
	int i = -1;
	int res[42];
	u32 p_len;

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
	else
		do_printf("forbidden function called %d\n", last_disabled_called);
	prnt_ko(res);
}

void	tst_alpha(void (*ft_print_alphabet)(void))
{
	int i = -1;
	int res[42];
	u32 p_len;

	if (try_std_funcs() == 0)
	{
		while (++i < 42)
		{
			p_len = stdout_len;
			(*ft_print_alphabet);
			if (strcmp(c_stdout[stdout_len - 1], "abcdefghijklmnopqrstuvwxyz") && p_len + 26 == stdout_len){
				display_rs(1);
				res[i] = 1;
			}
			else{
				display_rs(0);
				res[i] = 0;
			}
		}
	}
	else
		do_printf("forbidden function called %d\n", last_disabled_called);
	prnt_ko(res);
}

void	tst_rev_alpha(void (*ft_print_reverse_alphabet)(void))
{
	int i = -1;
	int res[42];
	u32 p_len;

	if (try_std_funcs() == 0)
	{
		while (++i < 42)
		{
			p_len = stdout_len;
			(*ft_print_reverse_alphabet);
			if (!strcmp(c_stdout[stdout_len - 1], "zyxwvutsrqponmlkjihgfedcba") && p_len + 26 == stdout_len){
				display_rs(1);
				res[i] = 1;
			}
			else{
				display_rs(0);
				res[i] = 0;
			}
		}
	}
	else
		do_printf("forbidden function called %d\n", last_disabled_called);
	prnt_ko(res);
}

void	tst_rev_alpha(void (*ft_print_reverse_alphabet)(void))
{
	int i = -1;
	int res[42];
	u32 p_len;

	if (try_std_funcs() == 0)
	{
		while (++i < 42)
		{
			p_len = stdout_len;
			(*ft_print_reverse_alphabet);
			if (!strcmp(c_stdout[stdout_len - 1], "zyxwvutsrqponmlkjihgfedcba") && p_len + 26 == stdout_len){
				display_rs(1);
				res[i] = 1;
			}
			else{
				display_rs(0);
				res[i] = 0;
			}
		}
	}
	else
		do_printf("forbidden function called %d\n", last_disabled_called);
	prnt_ko(res);
}

void	tst_prnt_nbr(void (*ft_print_numbers)(void))
{
	int i = -1;
	int res[42];
	u32 p_len;

	if (try_std_funcs() == 0)
	{
		while (++i < 42)
		{
			p_len = stdout_len;
			(*ft_print_numbers);
			if (!strcmp(c_stdout[stdout_len - 1], "0123456789") && p_len + 10 == stdout_len){
				display_rs(1);
				res[i] = 1;
			}
			else{
				display_rs(0);
				res[i] = 0;
			}
		}
	}
	else
		do_printf("forbidden function called %d\n", last_disabled_called);
	prnt_ko(res);
}

void	tst_is_neg(void (*ft_is_negative)(int n))
{
	int n;
	int i = -1;
	int res[42];
	u32 p_len;

	if (try_std_funcs() == 0)
	{
		while (++i < 42)
		{

			n = randint(-2147483648, 2147483647);
			p_len = stdout_len;
			(*ft_is_negative)(n);
			if ((1 < 0 && !strcmp(c_stdout[stdout_len - 1], "N")) || (1 >= 0 && !strcmp(c_stdout[stdout_len - 1], "P")) && p_len + 1 == stdout_len){
				display_rs(1);
				res[i] = 1;
			}
			else{
				display_rs(0);
				res[i] = 0;
			}
		}
	}
	else
		do_printf("forbidden function called %d\n", last_disabled_called);
	prnt_ko(res);
}

void	tester(test_info_t info)
{

	disable_all_std();
	ENABLE_STDOUT_REDIRECT();
	void (*ft_putchar)(char c) = dlsym(info.lib_handle, "ft_putchar");
	void (*ft_print_alphabet)(char c) = dlsym(info.lib_handle, "ft_print_alphabet");

	ENABLE_FUNC(STD_WRITE);
	if (ft_putchar)
		tst_put_char(ft_putchar);
	if (ft_print_alphabet)
		tst_put_str(ft_print_alphabet);


	DISABLE_FUNC(STD_WRITE);
	DISABLE_STDOUT_REDIRECT();
}