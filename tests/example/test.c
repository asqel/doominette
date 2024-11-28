#include "tests.h"
#include "std.h"

void tester(test_info_t info) {

	void (*ft_putchar)(char c) = dlsym(info.lib_handle, "ft_putchar");

	disable_all_std();
	ENABLE_FUNC(STD_WRITE);
	if (try_std_funcs() == 0) {
		(*ft_putchar)('c');
	}
	else {
		enable_all_std();
		printf("forbidden function called %d\n", last_disabled_called);
	}
}