#ifndef __STDIO
#define __STDIO

void printf(const char* str) {
    terminal_write(str);
}

#endif