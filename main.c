#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/mman.h>
#include <unistd.h>

void* make_funny() {
	void* addr = mmap(
		0,
		sysconf(_SC_PAGE_SIZE),
		PROT_READ | PROT_WRITE,
		MAP_PRIVATE | MAP_ANONYMOUS | MAP_FIXED,
		-1,
		0
	);
	if (addr == (void*)-1) {
		perror("mmap at 0");
		fputs("Run as root", stderr);
		exit(EXIT_FAILURE);
	}

	return addr;
}

int main() {
	char* funny = make_funny();

	strcpy(funny, "Hello, World!");
	// This doesn't work very well
	printf("%p, %s\n", funny, funny);
	// Stupid bypass, lol
	printf("%p, %s\n", funny + 1, funny + 1);

	if (funny == NULL) {
		puts("The optimizer sees we already touched funny, therefore it "
			 "*surely* isn't null!");
	} else {
		puts("funny != NULL according to the compiler");
	}
}
