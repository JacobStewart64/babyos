#include "safeint.h"
#include "string.h"
#include "vgacolors.h"
/* Check if the compiler thinks we are targeting the wrong operating system. */
//#if defined(__linux__)
//#error "You are not using a cross-compiler, you will most certainly run into trouble"
//#endif

/* This tutorial will only work for the 32-bit ix86 targets. */
//#if !defined(__i386__)
//#error "This tutorial needs to be compiled with a ix86-elf compiler"
//#endif
 
static inline uint8 vga_entry_color(enum VGACOLOR fg, enum VGACOLOR bg) 
{
	return fg | (uint16) bg << 4;
}
 
static inline uint16 vga_entry(unsigned char uc, uint16 color) 
{
	return (uint16) uc | color << 8;
}
 
static const uint32 VGA_WIDTH = 80;
static const uint32 VGA_HEIGHT = 25;
static const uint32 VGA_DISP_HEIGHT = VGA_HEIGHT - 1;
 
uint32 terminal_row;
uint32 terminal_column;
uint8 terminal_color;
uint16* terminal_buffer;
 
void terminal_initialize(void) 
{
	terminal_row = 0;
	terminal_column = 0;
	//terminal_color = vga_entry_color(VGA_COLOR_LIGHT_GREY, VGA_COLOR_BLACK);
	terminal_buffer = (uint16*) 0xB8000;
	for (uint32 y = 0; y < VGA_HEIGHT; y++) {
		for (uint32 x = 0; x < VGA_WIDTH; x++) {
			const uint32 index = y * VGA_WIDTH + x;
			terminal_buffer[index] = vga_entry(' ', BLACKONBLACK); //vga_entry(' ', terminal_color);
		}
	}
}
 
void terminal_setcolor(uint8 color) 
{
	terminal_color = color;
}
 
void terminal_putentryat(char c, uint8 color, uint32 x, uint32 y) 
{
	const uint32 index = y * VGA_WIDTH + x;
	terminal_buffer[index] = vga_entry(c, color);
}
 
void terminal_putchar(char c) 
{
	if (c == '\n') {
		terminal_column = 0;
		++terminal_row;
	}
	else {
		terminal_putentryat(c, WHITEONBLACK, terminal_column, terminal_row);
		if (++terminal_column == VGA_WIDTH) {
			terminal_column = 0;
			if (++terminal_row >= VGA_DISP_HEIGHT)
				terminal_row = VGA_DISP_HEIGHT;
		}
	}
	
}
 
void terminal_write(const char* data, uint32 size) 
{
	for (uint32 i = 0; i < size; i++)
		terminal_putchar(data[i]);
}

uint32 count = 0;
char* messagebuffer[100000];

void terminal_writestring(const char* data) 
{
	if (count != 100000) {
		messagebuffer[count++] = data;
		terminal_write(data, strlen(data));
	}
	else {
		terminal_writestring("100,000 messages in buffer, shutting down terminal");
	}	
}

void kernel_main(void) 
{
	/* Initialize terminal interface */
	terminal_initialize();

	char buffer[20] = {0};
	i32toa(buffer, 7 << 4);
	terminal_writestring(buffer);
	terminal_writestring("Hello, kernel World!\n");
	terminal_writestring("Hello again lol\n");
	terminal_writestring("Hello, kernel World!\n");
	terminal_writestring("Hello again lol\n");
	terminal_writestring("Hello, kernel World!\n");
	terminal_writestring("Hello again lol\n");
	terminal_writestring("Hello, kernel World!\n");
	terminal_writestring("Hello again lol\n");
	terminal_writestring("Hello, kernel World!\n");
	terminal_writestring("Hello again lol\n");
	terminal_writestring("Hello, kernel World!\n");
	terminal_writestring("Hello again lol\n");
	terminal_writestring("Hello, kernel World!\n");
	terminal_writestring("Hello again lol\n");
	terminal_writestring("Hello, kernel World!\n");
	terminal_writestring("Hello again lol\n");
	terminal_writestring("Hello, kernel World!\n");
	terminal_writestring("Hello again lol\n");
	terminal_writestring("Hello, kernel World!\n");
	terminal_writestring("Hello again lol\n");
	terminal_writestring("Hello, kernel World!\n");
	terminal_writestring("Hello again lol\n");
	terminal_writestring("Hello, kernel World!\n");
	terminal_writestring("Hello again lol\n");
	terminal_writestring("Hello, kernel World!\n");
	terminal_writestring("Hello again lol\n");
	terminal_writestring("Hello, kernel World!\n");
	terminal_writestring("Hello again lol\n");
}