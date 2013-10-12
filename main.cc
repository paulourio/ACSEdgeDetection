/* Copyright © 2013 Paulo Roberto Urio <paulourio@gmail.com> */
#include <cstdlib>
#include <cstdio>

#include "./core.h"

int main(int argc, const char** argv) {
	if (argc < 2) {
		fprintf(stderr, "Syntax: %s input.jpg output.jpg\n", argv[0]);
		exit(EXIT_FAILURE);
	}
	const char* out = (argc == 3) ? argv[2]: NULL;

	acs::Core core(argv[1], out);
	core.Main();
	return 0;
}
