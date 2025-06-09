#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "tower.h"
#include "utils.h"

extern FILE *log_file;

void init_tower(JengaTower *tower) {
    tower->top = -1;
    for (int i = 0; i < MAX_BLOCKS; i++) {
        tower->blocks[i] = NULL;
    }

    log_file = fopen("tower_log.txt", "w");
    if (!log_file) {
        fprintf(stderr, "Failed to open tower_log.txt\n");
        exit(1);
    }
}

int push_block(JengaTower *tower, int safe_mode) {
    if (tower->top >= MAX_BLOCKS - 1) {
        print_color("Tower is full!\n", COLOR_RED);
        return 0;
    }

    Block *new_block = (Block *)malloc(sizeof(Block));
    if (!new_block) {
        fprintf(stderr, "Memory allocation failed\n");
        return 0;
    }

    print_color("Enter label for new block: ", COLOR_YELLOW);
    char temp[256];
    scanf("%s", temp);

    if (safe_mode)
        strncpy(new_block->label, temp, sizeof(new_block->label) - 1);
    else
        strcpy(new_block->label, temp);  // Vulnerable

    new_block->label[7] = '\0';
    new_block->instability_score = rand() % 100;

    tower->top++;
    tower->blocks[tower->top] = new_block;

    log_action("PUSH", new_block);
    printf("✅ Added block '%s' with instability %d\n", new_block->label, new_block->instability_score);
    return 1;
}

int pop_block(JengaTower *tower) {
    if (tower->top < 0) {
        print_color("Tower is already empty!\n", COLOR_YELLOW);
        return 0;
    }

    Block *b = tower->blocks[tower->top];
    printf("❌ Removing block: %s | Instability: %d\n", b->label, b->instability_score);
    log_action("POP", b);

    free(b);
    tower->blocks[tower->top] = NULL;
    tower->top--;

    return 1;
}

void print_tower(JengaTower *tower) {
    print_color("\n=== Jenga Tower ===\n", COLOR_CYAN);
    if (tower->top < 0) {
        print_color("[Tower is empty]\n", COLOR_YELLOW);
        return;
    }

    for (int i = tower->top; i >= 0; i--) {
        Block *b = tower->blocks[i];
        if (b) {
            printf("| %-6s | [Instability: %3d]\n", b->label, b->instability_score);
            printf(" ---------\n");
        }
    }
}

void simulate_overflow(JengaTower *tower) {
    if (tower->top < 0) {
        print_color("No block to overflow!\n", COLOR_YELLOW);
        return;
    }

    print_color("💣 Enter a long label (> 8 chars): ", COLOR_RED);
    char input[256];
    scanf("%s", input);

    strcpy(tower->blocks[tower->top]->label, input);  // Unsafe
    print_color("⚠️  Overflow simulated.\n", COLOR_RED);
}