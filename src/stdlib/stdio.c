#ifndef __STDIO
#define __STDIO

#include "../terminal.c"
#include <stdarg.h>

void printf(const char* str, ...) {
    va_list args;

    va_start(args, str);
	
    for (size_t i = 0; str[i] != '\0'; i ++) {
        if (str[i] == '%') {            
            i++;
            if (str[i] == 'c') {
                char value = (char) va_arg(args, int);
                terminal_put_char(value);
            }
            else if (str[i] == 'd') {
                int int_value = (int) va_arg(args, int);
                char value = '0' + int_value;
                terminal_put_char(value);
            } else if (str[i] == 's') {
                char *value = (char *) va_arg(args, char *);
                terminal_put_string(value);
            }
        } else {
            terminal_put_char(str[i]);
        }
    }
        
    va_end(args);

}

#endif
