/* Copyright © 2013 Paulo Roberto Urio <paulourio@gmail.com> */
#include <cstdlib>
#include <cstdio>

#include "./core.h"

int main(int argc, const char** argv) {
	if (argc != 3) {
		fprintf(stderr, "Syntax: %s input.jpg output.jpg\n", argv[0]);
		exit(EXIT_FAILURE);
	}

	acs::Core core(argv[1], argv[2]);
	core.Main();
	return 0;
}
