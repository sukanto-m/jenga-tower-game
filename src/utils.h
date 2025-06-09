#ifndef UTILS_H
#define UTILS_H

#include "tower.h"

#define COLOR_RED    1
#define COLOR_GREEN  2
#define COLOR_YELLOW 3
#define COLOR_BLUE   4
#define COLOR_CYAN   5
#define COLOR_RESET  0

extern FILE *log_file;

void log_action(const char *action, Block *b);
void print_color(const char *text, int color_code);

#endif