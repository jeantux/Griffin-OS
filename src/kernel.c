#include "terminal.c"
#include <stdio.c>
 
#if defined(__linux__)
	#error "You are not using a cross-compiler, this can cause several problems"
#elif !defined(__i386__)
	#error "This system must be compiled with a ix86-elf compiler"
#endif

const char *app_name = "Griffin-OS";

void wellcome_griffinOS() {
	printf("Welcome to %s !\n", app_name);
	printf("Version: 0.0.0\n");
}

void kernel_main()
{
    terminal_init();
    wellcome_griffinOS();
}