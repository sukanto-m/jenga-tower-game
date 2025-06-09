#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "tower.h"
#include "utils.h"

int main() {
    srand(time(NULL));

    JengaTower tower;
    init_tower(&tower);

    int choice;
    int safe_mode = 0;

    print_color("🧱 Welcome to the Jenga Tower Memory Game!\n", COLOR_CYAN);
    printf("Use short labels to stay safe. Use long ones to test memory limits.\n");

    while (1) {
        printf("\n🔧 MENU:\n");
        printf("1. Push Block\n");
        printf("2. Pop Block\n");
        printf("3. Print Tower\n");
        printf("4. Simulate Overflow\n");
        printf("5. Toggle Safe Mode [%s]\n", safe_mode ? "ON" : "OFF");
        printf("6. Exit\n");
        printf("Enter choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                push_block(&tower, safe_mode);
                break;
            case 2:
                pop_block(&tower);
                break;
            case 3:
                print_tower(&tower);
                break;
            case 4:
                simulate_overflow(&tower);
                break;
            case 5:
                safe_mode = !safe_mode;
                print_color(safe_mode ? "✅ Safe mode ON\n" : "⚠️  Safe mode OFF\n", safe_mode ? COLOR_GREEN : COLOR_RED);
                break;
            case 6:
                print_color("👋 Thanks for playing!\n", COLOR_GREEN);
                if (log_file) fclose(log_file);
                return 0;
            default:
                print_color("Invalid choice. Try again.\n", COLOR_YELLOW);
        }
    }
}
