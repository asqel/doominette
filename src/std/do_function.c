#include "types.h"
#include <stdarg.h>
#include "std.h"
#include <stdlib.h>

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


void *do_malloc(size_t size) {
	u8 was_redirected = do_redirect_stdout;
	std_state_t func_states = {0};
	save_std_func_state(func_states);
	enable_all_std();

	void *res = malloc(size);

	load_std_func_state(func_states);
	do_redirect_stdout = was_redirected;
	return res;
}

void do_free(void *ptr) {
	u8 was_redirected = do_redirect_stdout;
	std_state_t func_states = {0};
	save_std_func_state(func_states);
	enable_all_std();

	free(ptr);

	load_std_func_state(func_states);
	do_redirect_stdout = was_redirected;
}
