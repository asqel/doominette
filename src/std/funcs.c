#include <stdint.h>
#include <stdlib.h>
#include <dlfcn.h>
#include "std.h"

void *malloc(size_t size) {
	if (!IS_FUNC_ENABLED(STD_MALLOC))
		catch_std_funcs(STD_MALLOC);

	static void *(*real_malloc)(size_t size) = NULL;

	if (real_malloc == NULL)
		real_malloc = dlsym(RTLD_NEXT, "malloc");
	if (do_malloc_fail)
		return NULL;
	return real_malloc(size);
}

void free(void *ptr) {
	if (!IS_FUNC_ENABLED(STD_FREE))
		catch_std_funcs(STD_FREE);

	static void (*real_free)(void *ptr) = NULL;

	if (real_free == NULL)
		real_free = dlsym(RTLD_NEXT, "free");
	real_free(ptr);
}

ssize_t write(int fd, const void *buf, size_t count) {
	if (!IS_FUNC_ENABLED(STD_WRITE))
		catch_std_funcs(STD_WRITE);

	static ssize_t (*real_write)(int fd, const void *buf, size_t count) = NULL;
	if (real_write == NULL)
		real_write = dlsym(RTLD_NEXT, "write");
	if (fd == 1 && do_redirect_stdout) {
		std_state_t state = {0};
		save_std_func_state(state);
		enable_all_std();
		write_fake_stdout(buf, count);
		load_std_func_state(state);
		return count;

	}
	else if (fd == 2 && do_redirect_stderr) {
		std_state_t state = {0};
		save_std_func_state(state);
		enable_all_std();
		write_fake_stderr(buf, count);
		load_std_func_state(state);
		return count;
	}
	return real_write(fd, buf, count);
}

ssize_t read(int fd, void *buf, size_t count) {
	if (!IS_FUNC_ENABLED(STD_READ))
		catch_std_funcs(STD_READ);

	static ssize_t (*real_read)(int fd, void *buf, size_t count) = NULL;
	if (real_read == NULL)
		real_read = dlsym(RTLD_NEXT, "read");
	if (fd == 0 && fake_stdin != NULL)
		return fake_stdin(buf, count);
	return real_read(fd, buf, count);
}