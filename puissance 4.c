#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ROWS 6
#define COLS 7

char board[ROWS][COLS];

void initializeBoard() {
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            board[i][j] = ' ';
        }
    }
}

void printBoard() {
    printf("\n  1   2   3   4   5   6   7\n");
    printf("+---+---+---+---+---+---+---+\n");
    for (int i = 0; i < ROWS; i++) {
        printf("|");
        for (int j = 0; j < COLS; j++) {
            if (board[i][j] == 'X') {
                printf(" \033[1;31mX\033[0m |"); // Red color for Player 1
            } else if (board[i][j] == 'O') {
                printf(" \033[1;34mO\033[0m |"); // Blue color for Player 2
            } else {
                printf("   |");
            }
        }
        printf("\n+---+---+---+---+---+---+---+\n");
    }
}

int dropToken(int col, char token) {
    for (int i = ROWS - 1; i >= 0; i--) {
        if (board[i][col] == ' ') {
            board[i][col] = token;
            return i;
        }
    }
    return -1; // Column is full
}

int checkWin(int row, int col, char token) {
    // Check horizontally
    for (int j = 0; j <= COLS - 4; j++) {
        if (board[row][j] == token &&
            board[row][j + 1] == token &&
            board[row][j + 2] == token &&
            board[row][j + 3] == token) {
            return 1;
        }
    }

    // Check vertically
    for (int i = 0; i <= ROWS - 4; i++) {
        if (board[i][col] == token &&
            board[i + 1][col] == token &&
            board[i + 2][col] == token &&
            board[i + 3][col] == token) {
            return 1;
        }
    }

    // Check diagonally (top-left to bottom-right)
    for (int i = 0; i <= ROWS - 4; i++) {
        for (int j = 0; j <= COLS - 4; j++) {
            if (board[i][j] == token &&
                board[i + 1][j + 1] == token &&
                board[i + 2][j + 2] == token &&
                board[i + 3][j + 3] == token) {
                return 1;
            }
        }
    }

    // Check diagonally (top-right to bottom-left)
    for (int i = 0; i <= ROWS - 4; i++) {
        for (int j = COLS - 1; j >= 3; j--) {
            if (board[i][j] == token &&
                board[i + 1][j - 1] == token &&
                board[i + 2][j - 2] == token &&
                board[i + 3][j - 3] == token) {
                return 1;
            }
        }
    }

    return 0; // No win
}

int getAvailableRow(int col) {
    for (int i = ROWS - 1; i >= 0; i--) {
        if (board[i][col] == ' ') {
            return i;
        }
    }
    return -1;
}

int botMove(int difficulty, char playerToken) {
    if (difficulty == 1) {

        return rand() % COLS;
    } else if (difficulty == 2) {

        if (rand() % 10 < 3) {
            return rand() % COLS;
        }
    }


    for (int col = 0; col < COLS; col++) {
        int row = getAvailableRow(col);
        if (row != -1) {
            board[row][col] = playerToken;
            if (checkWin(row, col, playerToken)) {
                board[row][col] = ' ';
                return col;
            }
            board[row][col] = ' ';
        }
    }


    char opponentToken = (playerToken == 'X') ? 'O' : 'X';
    for (int col = 0; col < COLS; col++) {
        int row = getAvailableRow(col);
        if (row != -1) {
            board[row][col] = opponentToken;
            if (checkWin(row, col, opponentToken)) {
                board[row][col] = ' ';
                return col;
            }
            board[row][col] = ' ';
        }
    }

    //
    return rand() % COLS;
}

void intro() {
    system("cls");
    printf("\033[1;36m#################################################################\n");
    printf("                             Welcome                            \n");
    printf("             *@@@*         Connect Four         *@@@*         \n");
    printf("                     *    Made by Group 7      *               \n");
    printf("#################################################################\033[0m\n");

    printf("\033[1;33mPress Enter to continue...\033[0m");
    getchar();
}

void menu() {
    system("cls");
    printf("\n\n");
    printf("\033[1;32m                         MENU OPTIONS                           \n");
    printf("---------------------------------------------------------------\n");
    printf("1. Play against Bot\n");
    printf("2. Play with a Friend\n");
    printf("3. Instructions\n");
    printf("4. Quit\n");
    printf("---------------------------------------------------------------\n\033[0m");
    printf("\033[1;36mEnter your choice: \033[0m");
}

void instructions() {
    system("cls");
    printf("\033[1;36mInstructions for Connect Four:\n");
    printf("---------------------------------\n");
    printf("Start a game of Connect Four:\n");
    printf("- To start a game of Connect Four, designate the first player.\n");
    printf("- The first player drops their colored token into a column of their choice.\n");
    printf("- The token then falls to the bottom of the column.\n");
    printf("\n");
    printf("Playing the game:\n");
    printf("- The second player then inserts their token, of the other color, into the column of their choice. And so on until a row of 4 tokens of the same color is achieved.\n");
    printf("\n");
    printf("How to win at Connect Four:\n");
    printf("- To win a game of Connect Four, be the first to connect four of your colored tokens horizontally, vertically, or diagonally.\n");
    printf("- If, during a game, all tokens are played without any token alignment, the game is declared a draw.\n");
    printf("\n");
    printf("Press Enter to return to the menu...\033[0m");
    getchar();
}

int main() {
    srand(time(NULL)); // Seed for random number generation
    intro();

    menu();
    int choice;
    do {
        scanf("%d", &choice);
        switch (choice) {
            case 1: {
                system("cls");
                initializeBoard();
                printBoard();
                char player1Token, player2Token;
                printf("\033[1;36mChoose your token (X or O): \033[0m");
                scanf(" %c", &player1Token);
                if (player1Token != 'X' && player1Token != 'O') {
                    printf("\033[1;31mInvalid token choice. Defaulting to 'X'.\n\033[0m");
                    player1Token = 'X';
                }
                player2Token = (player1Token == 'X') ? 'O' : 'X';

                int currentPlayer = 1;
                int column;
                int win = 0;
                int moves = 0;
                int difficulty;
                printf("\033[1;36mChoose bot difficulty:\n");
                printf("1. Easy\n");
                printf("2. Medium\n");
                printf("3. Hard\n");
                printf("Enter your choice: \033[0m");
                scanf("%d", &difficulty);

                do {
                    if (currentPlayer == 1) {
                        printf("\n\033[1;36mPlayer %d's turn (Enter column 1-7): \033[0m", currentPlayer);
                        scanf("%d", &column);
                        column--; // Adjust for 0-based indexing
                        if (column < 0 || column >= COLS || board[0][column] != ' ') {
                            printf("\033[1;31mInvalid column! Please choose again.\n\033[0m");
                            continue;
                        }
                    } else {
                        printf("\n\033[1;36mBot's turn...\n\033[0m");
                        column = botMove(difficulty, player2Token);
                    }

                    int row = dropToken(column, (currentPlayer == 1) ? player1Token : player2Token);
                    system("cls");
                    printBoard();
                    win = checkWin(row, column, (currentPlayer == 1) ? player1Token : player2Token);
                    moves++;

                    if (win) {
                        if (currentPlayer == 1) {
                            printf("\n\033[1;32mPlayer %d wins!\n\033[0m", currentPlayer);
                        } else {
                            printf("\n\033[1;32mBot wins!\n\033[0m");
                        }
                        break;
                    } else if (moves == ROWS * COLS) {
                        printf("\n\033[1;33mThe game is a draw!\n\033[0m");
                        break;
                    }

                    currentPlayer = (currentPlayer == 1) ? 2 : 1;
                } while (!win);

                break;
            }
            case 2:
                system("cls");
                initializeBoard();
                printBoard();
                printf("\033[1;36mPlayer 1's token is 'X' and Player 2's token is 'O'.\n\033[0m");

                int currentPlayer = 1;
                int column;
                int win = 0;
                int moves = 0;

                do {
                    printf("\n\033[1;36mPlayer %d's turn (Enter column 1-7): \033[0m", currentPlayer);
                    scanf("%d", &column);
                    column--; // Adjust for 0-based indexing
                    if (column < 0 || column >= COLS || board[0][column] != ' ') {
                        printf("\033[1;31mInvalid column! Please choose again.\n\033[0m");
                        continue;
                    }

                    int row = dropToken(column, (currentPlayer == 1) ? 'X' : 'O');
                    system("cls");
                    printBoard();
                    win = checkWin(row, column, (currentPlayer == 1) ? 'X' : 'O');
                    moves++;

                    if (win) {
                        printf("\n\033[1;32mPlayer %d wins!\n\033[0m", currentPlayer);
                        break;
                    } else if (moves == ROWS * COLS) {
                        printf("\n\033[1;33mThe game is a draw!\n\033[0m");
                        break;
                    }

                    currentPlayer = (currentPlayer == 1) ? 2 : 1;
                } while (!win);

                break;
            case 3:
                instructions();
                break;
            case 4:
                printf("\033[1;33mQuitting game...\n\033[0m");
                return 0;
            default:
                printf("\033[1;31mInvalid choice. Please enter a number from 1 to 4.\n\033[0m");
                break;
        }

        printf("\n\033[1;33mPress Enter to return to the menu...\033[0m");
        getchar();
        getchar(); // Consume newline character
        system("cls");
        menu();
    } while (choice != 4);

    return 0;
}
