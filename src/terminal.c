#ifndef __TERMINAL_C
#define __TERMINAL_C

#include <stddef.h>
#include <stdint.h>
#include "vga.h"

volatile uint16_t* VGA_ADDRESS = (uint16_t*)0xB8000;

int term_column = 0;
int term_row = 0;
static uint8_t terminal_color_default;

void terminal_init()
{
	terminal_color_default = vga_out_color(VGA_COLOR_WHITE , VGA_COLOR_BLACK);
	for (int col = 0; col < VGA_COLS; col ++)
	{
		for (int row = 0; row < VGA_ROWS; row ++)
		{
			const size_t index = (VGA_COLS * row) + col;
			VGA_ADDRESS[index] = ((uint16_t)terminal_color_default << 8) | ' ';
		}
	}
}

void break_line() 
{
	term_column = 0;
	term_row ++;
}

void set_position_screen()
{
	if (term_column >= VGA_COLS)
		break_line();

	if (term_row >= VGA_ROWS)
	{
		term_column = 0;
		term_row = 0;
	}
}

void write_char_screen(char c)
{
	if (c != '\n') {
		const size_t index = (VGA_COLS * term_row) + term_column;
		VGA_ADDRESS[index] = ((uint16_t)terminal_color_default << 8) | c;
		term_column ++;
	} else {
		break_line();
	}
}

void terminal_put_char(char c)
{
	write_char_screen(c);
	set_position_screen();
}

void terminal_put_string(const char* str)
{
	for (size_t i = 0; str[i] != '\0'; i ++)
		terminal_put_char(str[i]);
}

#endif
