#ifndef __PRINTF
#define __PRINTF

void printf(const char* str) {
    terminal_write(str);
}

#endif