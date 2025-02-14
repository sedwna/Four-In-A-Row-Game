# Four-In-A-Row-Game

Welcome to the **Four-In-A-Row-Game** game! This is a terminal-based implementation of the classic **Connect Four** game, where two players take turns dropping colored pieces into a grid. The goal is to be the first to connect four of your pieces in a row (horizontally, vertically, or diagonally). The game features colorful visuals, save/load functionality, and an interactive menu.

---

## Table of Contents
- [Introduction](#introduction)
- [Features](#features)
- [How to Run](#how-to-run)
- [Gameplay](#gameplay)
- [Code Structure](#code-structure)
- [Dependencies](#dependencies)

---

## Introduction

The **Four-In-A-Row-Game** game is a two-player strategy game where players take turns dropping their pieces into a 7x6 grid. The first player to connect four of their pieces in a row wins the game. If the grid is filled without a winner, the game ends in a draw.

This project is implemented in **C** and uses the terminal for input and output. It features:
- **Colorful visuals** using ANSI escape codes.
- **Save and load functionality** to continue games later.
- **Interactive menu** for easy navigation.

---

## Features

- **Two-Player Mode**: Play against a friend on the same device.
- **Colorful Visuals**: Uses ANSI escape codes to display colored pieces in the terminal.
- **Save and Load**: Save your game progress and load it later to continue playing.
- **Interactive Menu**: Easy-to-navigate menu for starting new games, loading saves, and accessing help.
- **Winning Logic**: Automatically checks for a winner or a draw.
- **Cross-Platform**: Works on any system with a C compiler and terminal support.

---

## How to Run

### Prerequisites
- **C Compiler**: Ensure you have a C compiler installed (e.g., `gcc`).
- **Terminal**: The game runs in the terminal.

### Steps to Run
1. **Clone the Repository**:
   ```bash
   git clone https://github.com/your-username/Four-In-A-Row-Game.git
   ```

2. **Compile the Code**:
   Compile the C code using `gcc`:
   ```bash
   gcc main.c -o Four-In-A-Row-Game
   ```

3. **Run the Game**:
   Run the compiled executable:
   ```bash
   ./Four-In-A-Row-Game
   ```

4. **Follow the Instructions**:
   - Use the menu to start a new game, load a saved game, or access help.
   - Follow the on-screen instructions to play the game.

---

## Gameplay

### Objective
- Be the first player to connect four of your pieces in a row (horizontally, vertically, or diagonally).

### Controls
- **Player 1** and **Player 2** take turns entering a column number (0-7) to drop their piece.
- Use the `-1` command to exit the game and save your progress.

### Game Modes
1. **New Game**: Start a fresh game.
2. **Load Game**: Continue from a previously saved game.
3. **Help**: Access game instructions and rules.

### Saving and Loading
- The game automatically saves your progress when you exit.
- Use the **Load Game** option to continue from where you left off.

---

## Code Structure

The project is organized into the following functions:

- **`menu()`**: Displays the main menu and handles user input.
- **`Start()`**: Initializes a new game.
- **`ChoiseColumn()`**: Handles player input for selecting a column.
- **`PrintBoard()`**: Displays the current state of the game board.
- **`check_board()`**: Checks for a winning condition or a draw.
- **`FWrite()`**: Saves the game state to a file.
- **`FRead()`**: Loads the game state from a file.
- **`Help()`**: Displays game instructions and rules.

---

## Dependencies

- **C Standard Library**: The project uses the standard C library for input/output, file handling, and memory management.
- **ANSI Escape Codes**: Used for adding colored output to the terminal.

---

### Main Menu
```
choise what do you want to happen?

1. (H)ELP
2. (P)lay (to Creat a new game)
3. (S)ave (to Continue from last save)
4. (F)ile (to Read a save file as '0 & 1' in terminal)
5. (E)XIT

Enter choise ---->
```

### Game Board
```
   0     1     2     3     4     5     6     7
+---------------------------------------------+
|     |     |     |     |     |     |     |     |
+---------------------------------------------+
|     |     |     |     |     |     |     |     |
+---------------------------------------------+
|     |     |     |     |     |     |     |     |
+---------------------------------------------+
|     |     |     |     |     |     |     |     |
+---------------------------------------------+
|     |     |     |     |     |     |     |     |
+---------------------------------------------+
|     |     |     |     |     |     |     |     |
+---------------------------------------------+
```

### Winning Message
```
WIN USER '1'
```

---

Enjoy playing **Four-In-A-Row-Game**! If you have any questions or feedback, feel free to open an issue or contribute to the project.

---

