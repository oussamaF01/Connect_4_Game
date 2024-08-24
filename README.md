
# Connect Four Game

## Description

This is a console-based implementation of the classic **Connect Four** game. The game allows you to play against a friend or challenge an AI bot with varying difficulty levels. The game is built in C and features a simple text-based user interface with colored tokens for visual clarity.

## Features

- **Single Player Mode**: Play against a bot with three difficulty levels (Easy, Medium, Hard).
- **Two Player Mode**: Play against a friend locally on the same machine.
- **Color-Coded Tokens**: Player 1's token is red, and Player 2's token (or the bot's token) is blue.
- **Win Detection**: The game automatically checks for horizontal, vertical, and diagonal connections of four tokens to determine the winner.
- **Instructions**: Provides clear instructions on how to play the game.
- **Menu**: Easy-to-navigate menu to start a new game, view instructions, or quit the game.

## How to Run

### Prerequisites

- A C compiler (e.g., GCC)

### Compilation

To compile the game, use the following command in your terminal:

\`\`\`bash
gcc -o connect_four puissance 4.c
\`\`\`

### Execution

To start the game, run the following command:

\`\`\`bash
./connect_four
\`\`\`

## Game Instructions

- **Objective**: Be the first player to form a horizontal, vertical, or diagonal line of four tokens.
- **Gameplay**:
  1. Players take turns to drop their colored tokens into one of the seven columns.
  2. The token will occupy the lowest available space within the chosen column.
  3. The game continues until one player connects four tokens or the board is full, resulting in a draw.
- **Single Player**: Choose your token ('X' or 'O') and the bot's difficulty level before starting.
- **Two Player**: Player 1 uses 'X', and Player 2 uses 'O'.

## Bot Difficulty Levels

- **Easy**: The bot makes random moves.
- **Medium**: The bot occasionally makes random moves but also attempts to block your winning moves.
- **Hard**: The bot prioritizes blocking your winning moves and also attempts to create winning opportunities for itself.


## Credits

- **Group 7**: Developed by Group 7 as part of a programming project.
