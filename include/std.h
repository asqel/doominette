#ifndef STD_H
#define STD_H

#include "types.h"
#include <setjmp.h>

enum {
	STD_MALLOC,
	STD_FREE,
	STD_WRITE,

	STD____MAX
};

extern u8 std_func_disabled[STD____MAX]; // 0 = enabled, 1 = disabled
extern jmp_buf std_func_disable_jmp;

extern u32 last_disabled_called; //  STD____MAX = no func called

extern u8 do_redirect_stdout;
extern u8 do_redirect_stderr;


extern char *stdout;
extern char *stderr;
extern u32 stdout_len;
extern u32 stderr_len;

#define IS_FUNC_ENABLED(X) (std_func_disabled[X] == 0)
#define ENABLE_FUNC(X) (std_func_disabled[X] = 0)
#define DISABLE_FUNC(X) (std_func_disabled[X] = 1)

#define ENABLE_STDOUT_REDIRECT() do_redirect_stdout = 1
#define DISABLE_STDOUT_REDIRECT() do_redirect_stdout = 0

#define ENABLE_STDERR_REDIRECT() do_redirect_stderr = 1
#define DISABLE_STDERR_REDIRECT() do_redirect_stderr = 0

void disable_all_std();
void enable_all_std();


// return twice 0 first time then 1 if a function disabled was called
#define try_std_funcs() (setjmp(std_func_disable_jmp))

void catch_std_funcs(u32 func);



size_t write_fake_stdout(void *buf, size_t count);
size_t write_fake_stderr(void *buf, size_t count);

typedef  u8 std_state_t[STD____MAX];

void load_std_func_state(std_state_t func_states);
void save_std_func_state(std_state_t func_states);

#endif