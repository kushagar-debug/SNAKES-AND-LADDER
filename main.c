#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int rollDice() {
    return (rand() % 6) + 1;
}

int checkSnakeOrLadder(int pos) {
    switch (pos) {
        case 3: return 22;    // Ladder
        case 5: return 8;     // Ladder
        case 11: return 26;   // Ladder
        case 20: return 29;   // Ladder
        case 17: return 4;    // Snake
        case 19: return 7;    // Snake
        case 21: return 9;    // Snake
        case 27: return 1;    // Snake
        default: return pos;
    }
}

void playGame() {
    int pos1 = 0, pos2 = 0, turn = 1;
    srand(time(0));

    while (pos1 < 100 && pos2 < 100) {
        int dice = rollDice();
        printf("\nPlayer %d rolled a %d", turn, dice);

        if (turn == 1) {
            pos1 += dice;
            if (pos1 > 100) pos1 -= dice;
            pos1 = checkSnakeOrLadder(pos1);
            printf("\nPlayer 1 is now at position %d\n", pos1);
            if (pos1 == 100) {
                printf("\n🎉 Player 1 Wins!\n");
                break;
            }
            turn = 2;
        } else {
            pos2 += dice;
            if (pos2 > 100) pos2 -= dice;
            pos2 = checkSnakeOrLadder(pos2);
            printf("\nPlayer 2 is now at position %d\n", pos2);
            if (pos2 == 100) {
                printf("\n🎉 Player 2 Wins!\n");
                break;
            }
            turn = 1;
        }
    }
}

int main() {
    printf("Welcome to Snakes and Ladders!\n");
    playGame();
    return 0;
}
