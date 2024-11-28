#include "tests.h"
#include <dlfcn.h>

void	tst_put_char(char c, void (*ft_putchar)(char c))
{

}

void	tester(test_info_t info)
{

	void (*ft_putchar)(char c) = dlsym(info.lib_handle, "ft_putchar");
	(*ft_putchar)('c')

}