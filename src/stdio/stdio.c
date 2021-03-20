#include "../terminal.c"

void printf(const char* str) {
    terminal_write(str);
}