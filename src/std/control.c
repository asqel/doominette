#include "types.h"
#include "std.h"
#include <setjmp.h>
#include <stdlib.h>
#include <string.h>


u8 std_func_disabled[STD____MAX] = {0}; // 0 = enabled, 1 = disabled
jmp_buf std_func_disable_jmp = {0};

u32 last_disabled_called = STD____MAX;

u8 do_redirect_stderr = 0;
u8 do_redirect_stdout = 0;

char *c_stdout = NULL;
char *c_stderr = NULL;
u32 stdout_len = 0;
u32 stderr_len = 0;
ssize_t (*fake_stdin)(void *buf, size_t count) = NULL;

u8 do_malloc_fail = 0;



void catch_std_funcs(u32 func) {
	last_disabled_called = func;
	longjmp(std_func_disable_jmp, 1);
}


void disable_all_std() {
	for (u32 i = 0; i < STD____MAX; i++)
		std_func_disabled[i] = 1;
}

void enable_all_std() {
	for (u32 i = 0; i < STD____MAX; i++)
		std_func_disabled[i] = 0;
}

const char *get_std_name(u32 func) {

	switch (func) {
		case STD_MALLOC:
			return "malloc";
		case STD_FREE:
			return "free";
		case STD_WRITE:
			return "write";
		case STD____MAX:
			return "NONE";
		default:
			return "unknown";
	}
}

ssize_t write_fake_stdout(void *buf, ssize_t count) {
	c_stdout = realloc(c_stdout, stdout_len + count);
	memcpy(&(c_stdout[stdout_len]), buf, count);
	stdout_len += count;
	return count;
}


ssize_t write_fake_stderr(void *buf, ssize_t count) {
	c_stderr = realloc(c_stderr, stderr_len + count);
	memcpy(&(c_stderr[stderr_len]), buf, count);
	stderr_len += count;
	return count;
}

void save_std_func_state(u8 func_states[STD____MAX]) {
	for (u32 i = 0; i < STD____MAX; i++)
		func_states[i] = std_func_disabled[i];
}

void load_std_func_state(u8 func_states[STD____MAX]) {
	for (u32 i = 0; i < STD____MAX; i++)
		std_func_disabled[i] = func_states[i];
}