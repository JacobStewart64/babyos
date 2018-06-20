#ifndef VGACOLORS
#include "vgacolors.h"
#endif

#include "safeint.h"

extern uint32 terminal_color_index;
extern uint16 terminal_color;

void set_terminal_color(enum VGACOLOR color)
{
        terminal_color_index = color;
        terminal_color = VGACOLORARR[color];
}

void next_terminal_color(void)
{
        if (++terminal_color_index != VGACOLORLEN)
                terminal_color = VGACOLORARR[terminal_color_index];
        else terminal_color_index = VGACOLORLEN;
}

void previous_terminal_color(void)
{
        if (--terminal_color_index >= 0)
                terminal_color = VGACOLORARR[terminal_color_index];
        else terminal_color_index = 0;
}