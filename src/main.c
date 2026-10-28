#include <stdlib.h>
#include <stdio.h>
#include <stdint.h>
#include <string.h>

void usage(void) {
	printf("usage: jcc <source>.c [--lex] [--parse] [--codegen]\n");
}

int main(int argc, char *argv[]) {
	/**
	 * This is the entry point to the compiler *driver*
	 * The compiler driver is an orchestrator of the compiler pipeline
	 * 1. preprocess: Accept input *.c file, pass it to preprocessor, emit *.i
	 * 2. compile: Pass *.i file to compiler, compile, emit *.s, delete *.i
	 * 3. assemble: Pass *.s to assembler, assemble, emit binary, delete *.s
	 */
	if (argc <= 1) {
		usage();
		exit(1);
	}
	// TODO: Add CLI logic here.. for now assuming just *.c is provided
	char *src = argv[1]; size_t len = strlen(src);
	if (strcmp(&src[len-2], ".c")) {
		fprintf(stderr, "error: %s does not have expected '.c' extension\n", src);
		exit(1);
	}
	char pp[len + 1]; pp[len] = '\0';
	strcpy(pp, src); pp[len - 1] = 'i';
	printf("Going to run: gcc -E -P %s -o %s\n", src, pp);
	return 0;
}