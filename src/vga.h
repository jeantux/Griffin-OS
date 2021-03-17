/* VGA - Video Graphics Array */
#ifndef ARCH_I386_VGA
#define ARCH_I386_VGA

#include <stdint.h>
    enum vga_color {
        VGA_COLOR_BLACK = 0x0F,
        VGA_COLOR_BLUE = 0x1F,
        VGA_COLOR_GREEN = 0x2F,
        VGA_COLOR_CYAN = 0x3F,
        VGA_COLOR_RED = 0x4F,
        VGA_COLOR_MAGENTA = 0x5F,
        VGA_COLOR_BROWN = 0x6F,
        VGA_COLOR_LIGHT_GREY = 0x7F,
        VGA_COLOR_DARK_GREY = 0x8F,
        VGA_COLOR_LIGHT_BLUE = 0x9F,
        VGA_COLOR_LIGHT_GREEN = 0x10F,
        VGA_COLOR_LIGHT_CYAN = 0x11F,
        VGA_COLOR_LIGHT_RED = 0x12F,
        VGA_COLOR_LIGHT_MAGENTA = 0x13F,
        VGA_COLOR_YELLOW = 0x14F,
        VGA_COLOR_WHITE = 0x15F
    };

    const int VGA_COLS = 80;
    const int VGA_ROWS = 25;

#endif