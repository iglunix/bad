#include <stdbool.h>

#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <libgen.h>

#define N "\n"
#define T "\t"
#define USAGE \
"Usage: " N \
T	"%s [options] cmd" N

int main(int argc, char **argv) {
	char **last = argv + argc;
	char const *name = basename(*argv++);
	bool has_cmd;
	char **arg = argv;
	for (;(has_cmd = arg < last)
		&& strlen(*arg) > 1 && !strncmp("--", *arg, 2);
		arg++
	) {
		char str[512];
		snprintf(str, 512, "/usr/bad/bin/%s:%s", *arg + 2, getenv("PATH"));
		setenv("PATH", str, true);
	}

	if (has_cmd) {
		execvp(*arg, arg);
	} else {
		fprintf(stderr, USAGE, name);
	}
}
