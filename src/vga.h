/* VGA - Video Graphics Array */
#ifndef __ARCH_I386_VGA
#define __ARCH_I386_VGA

#include <stdint.h>
    enum vga_color {
        VGA_COLOR_BLACK = 0,
        VGA_COLOR_BLUE = 1,
        VGA_COLOR_GREEN = 2,
        VGA_COLOR_CYAN = 3,
        VGA_COLOR_RED = 4,
        VGA_COLOR_MAGENTA = 5,
        VGA_COLOR_BROWN = 6,
        VGA_COLOR_LIGHT_GREY = 7,
        VGA_COLOR_DARK_GREY = 8,
        VGA_COLOR_LIGHT_BLUE = 9,
        VGA_COLOR_LIGHT_GREEN = 10,
        VGA_COLOR_LIGHT_CYAN = 11,
        VGA_COLOR_LIGHT_RED = 12,
        VGA_COLOR_LIGHT_MAGENTA = 13,
        VGA_COLOR_YELLOW = 14,
        VGA_COLOR_WHITE = 15
    };

    const int VGA_COLS = 80;
    const int VGA_ROWS = 25;

    inline uint8_t vga_out_color(enum vga_color foreground, enum vga_color background) {
        return foreground | background << 4;
    }

#endif