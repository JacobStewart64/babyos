#include "safeint.h"
#include "string.h"
#include "vgacolors.h"

const uint32 VGA_WIDTH = 80;
const uint32 VGA_HEIGHT = 25;
const uint32 VGA_DISP_WIDTH = 80;
const uint32 VGA_LAST_ROW_PX = 24 * VGA_WIDTH;
const uint32 VGA_LAST_ROW = 24;
const uint32 VGA_DISP_HEIGHT_PX = 23 * VGA_WIDTH;
const uint32 VGA_DISP_HEIGHT = 23;
uint32 terminal_position = 9 * VGA_WIDTH;
uint16* terminal_buffer = 0xB8000;
char* location = "/";
const uint32 locationlen = 1;
uint32 cursor_column = locationlen + 1;
uint32 count = 0;
char messagebuffer[2000000] = {0};
uint32 terminal_color_index = BW;
uint16 terminal_color = 29;

void initialize(void)
{
	terminal_color = VGACOLORARR[BW];
}

uint16 vga_entry(uint16 c) 
{
	return c | terminal_color; //terminalcolor is high bits
}

void clear_screen(uint32 yh, uint32 yw, uint32 xh, uint32 xw)
{
	for (uint32 y = yh; y < yw; y++) {
		for (uint32 x = xh; x < xw; x++) {
			const uint32 index = y * VGA_WIDTH + x;
			terminal_buffer[index] = vga_entry(' '); //vga_entry(' ', terminal_color);
		}
	}
}

uint32 get_terminal_row(void)
{
	return (terminal_position - (terminal_position % 80)) / 80;
}

void set_terminal_row_px(void)
{
	terminal_position -= terminal_position % 80;
}

void clear_screen_from_terminal_row(void)
{
	clear_screen(get_terminal_row(), VGA_DISP_HEIGHT, terminal_position % 80, VGA_DISP_WIDTH);
}

void vga_next_row(void)
{
	set_terminal_row_px();
	if (terminal_position != VGA_DISP_HEIGHT_PX) {
		terminal_position += 80;	
	}
}
 
void terminal_putchar(char c) 
{
	if (c == '\n') {
		vga_next_row();
	}
	else {
		terminal_buffer[terminal_position++] = vga_entry(c);
	}	
}
 
void terminal_write(const char* data, uint32 datalen) 
{
	for (uint32 i = 0; i < datalen; i++)
		terminal_putchar(data[i]);
}

void copy_buffer(char* out, const char* in, uint32 len)
{
	for (uint32 i = 0; i < len; ++i) {
		out[i] = in[i];
	}
}

void terminal_writestringf(const char* data, uint32 datalen) 
{
	if (count <= (2000000 - datalen)) {
		copy_buffer(messagebuffer+count, data, datalen);
		count += datalen;
		terminal_write(data, datalen);
	}
	else {
		char* string = "100,000 messages in buffer, shutting down terminal";
		uint32 stringlen = strlen(string);
		terminal_writestringf(string, stringlen);
	}	
}

void terminal_writestring(const char* data) 
{	
	terminal_writestringf(data, strlen(data));	
}

void kernel_main(void) 
{
	initialize();

	char buffer[20] = {0};
	i32toa(buffer, 7 << 4);
	terminal_writestring(buffer);
	next_terminal_color();
	terminal_writestring("Hello, kernel World!\n");
	next_terminal_color();
	terminal_writestring("Hello again lol\n");
	next_terminal_color();
	terminal_writestring("Hello, kernel World!\n");
	next_terminal_color();
	terminal_writestring("Hello again lol\n");
	next_terminal_color();
	terminal_writestring("Hello, kernel World!\n");
	next_terminal_color();
	terminal_writestring("Hello again lol\n");
	next_terminal_color();
	terminal_writestring("Hello, kernel World!\n");
	next_terminal_color();
	terminal_writestring("Hello again lol\n");
	next_terminal_color();
	terminal_writestring("Hello, kernel World!\n");
	next_terminal_color();
	terminal_writestring("Hello again lol\n");
	next_terminal_color();
	terminal_writestring("Hello, kernel World!\n");
	next_terminal_color();
	terminal_writestring("Hello again lol\n");
	next_terminal_color();
	terminal_writestring("Hello, kernel World!\n");
	next_terminal_color();
	terminal_writestring("Hello again lol\n");
	next_terminal_color();
	terminal_writestring("Hello, kernel World!\n");
	next_terminal_color();
	terminal_writestring("Hello again lol\n");
	next_terminal_color();
	terminal_writestring("Hello, kernel World!\n");
	next_terminal_color();
	terminal_writestring("Hello again lol\n");
	next_terminal_color();
	terminal_writestring("Hello, kernel World!\n");
	next_terminal_color();
	terminal_writestring("Hello again lol\n");
	next_terminal_color();
	terminal_writestring("Hello, kernel World!\n");
	next_terminal_color();
	terminal_writestring("Hello again lol\n");
	next_terminal_color();
	terminal_writestring("Hello, kernel World!\n");
	next_terminal_color();
	terminal_writestring("Hello again lol\n");
	next_terminal_color();
	terminal_writestring("Hello, kernel World!\n");
	next_terminal_color();
	terminal_writestring("Hello again lol\n");
	next_terminal_color();
	terminal_writestring("Hello, kernel World!\n");
	next_terminal_color();
	terminal_writestring("Hello again lol\n");
	next_terminal_color();
}