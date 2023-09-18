#include <stdio.h>
#include <stdlib.h>

int main() {
    int choice;
    
    printf("Welcome to the Text-Based Adventure Game!\n");
    printf("1. Start\n");
    printf("2. Exit\n");
    printf("Enter your choice: ");
    scanf("%d", &choice);
    
    switch (choice) {
        case 1:
            printf("You are in a dark cave. What do you do?\n");
            printf("1. Go deeper into the cave\n");
            printf("2. Exit the cave\n");
            scanf("%d", &choice);
            
            if (choice == 1) {
                printf("You encounter a dragon. You have two choices:\n");
                printf("1. Fight the dragon\n");
                printf("2. Run away\n");
                scanf("%d", &choice);
                
                if (choice == 1) {
                    printf("You defeated the dragon and found a treasure!\n");
                } else {
                    printf("You ran away and survived.\n");
                }
            } else {
                printf("You exit the cave safely.\n");
            }
            break;
            
        case 2:
            printf("Exiting the game...\n");
            break;
            
        default:
            printf("Invalid choice. Exiting...\n");
            break;
    }
    
    return 0;
}
