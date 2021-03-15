#include <stddef.h>
#include <stdint.h>

volatile uint16_t* vga_buffer = (uint16_t*)0xB8000;

const int VGA_COLS = 80;
const int VGA_ROWS = 25;

int term_column = 0;
int term_row = 0;
uint8_t term_color = 0x0F;

void terminal_init()
{
	for (int col = 0; col < VGA_COLS; col ++)
	{
		for (int row = 0; row < VGA_ROWS; row ++)
		{
			const size_t index = (VGA_COLS * row) + col;
			vga_buffer[index] = ((uint16_t)term_color << 8) | ' ';
		}
	}
}

void terminal_putc(char c)
{
	switch (c)
	{
	case '\n':
		{
			term_column = 0;
			term_row ++;
			break;
		}
	default:
		{
			const size_t index = (VGA_COLS * term_row) + term_column;
			vga_buffer[index] = ((uint16_t)term_color << 8) | c;
			term_column ++;
			break;
		}
	}

	if (term_column >= VGA_COLS)
	{
		term_column = 0;
		term_row ++;
	}

	if (term_row >= VGA_ROWS)
	{
		term_column = 0;
		term_row = 0;
	}
}

void printf(const char* str)
{
	for (size_t i = 0; str[i] != '\0'; i ++)
		terminal_putc(str[i]);
}