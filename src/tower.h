#ifndef TOWER_H
#define TOWER_H

#define MAX_BLOCKS 64

typedef struct {
    char label[8];
    int instability_score;
} Block;

typedef struct {
    Block *blocks[MAX_BLOCKS];
    int top;
} JengaTower;

// Tower operations
void init_tower(JengaTower *tower);
int push_block(JengaTower *tower, int safe_mode);
int pop_block(JengaTower *tower);
void print_tower(JengaTower *tower);
void simulate_overflow(JengaTower *tower);

#endif
