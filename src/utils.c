#include <stdio.h>
#include "utils.h"

FILE *log_file = NULL;

void log_action(const char *action, Block *b) {
    if (b && log_file) {
        fprintf(log_file, "[%s] Label: %s | Score: %d\n", action, b->label, b->instability_score);
        fflush(log_file);
    }
}

void print_color(const char *text, int color_code) {
    const char *code;
    switch (color_code) {
        case COLOR_RED:    code = "\033[1;31m"; break;
        case COLOR_GREEN:  code = "\033[1;32m"; break;
        case COLOR_YELLOW: code = "\033[1;33m"; break;
        case COLOR_BLUE:   code = "\033[1;34m"; break;
        case COLOR_CYAN:   code = "\033[1;36m"; break;
        default:           code = "\033[0m"; break;
    }
    printf("%s%s\033[0m", code, text);
}