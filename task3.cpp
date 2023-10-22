/* Build a simple console-based Tic-Tac-Toe game that
allows two players to play against each other

Game Board: Create a 3x3 grid as the game board.
Players: Assign "X" and "O" to two players.
Display Board: Show the current state of the board.
Player Input: Prompt the current player to enter their move.
Update Board: Update the game board with the player's move.
Check for Win: Check if the current player has won.
Check for Draw: Determine if the game is a draw.
Switch Players: Alternate turns between "X" and "O" players.
Display Result: Show the result of the game (win, draw, or ongoing).
Play Again: Ask if the players want to play another game.*/

// I have not used namespace std which is standard form to be practical

#include <iostream>
#include <vector>

// Function to display the Tic-Tac-Toe board
void displayBoard(const std::vector<std::vector<char>>& board) {
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            std::cout << board[i][j];
            if (j < 2) {
                std::cout << " | ";
            }
        }
        std::cout << std::endl;
        if (i < 2) {
            std::cout << "---------" << std::endl;
        }
    }
}

// Function to check if the current player has won
bool checkWin(const std::vector<std::vector<char>>& board, char player) {
    for (int i = 0; i < 3; i++) {
        if (board[i][0] == player && board[i][1] == player && board[i][2] == player) {
            return true; // Horizontal win
        }
        if (board[0][i] == player && board[1][i] == player && board[2][i] == player) {
            return true; // Vertical win
        }
    }
    if (board[0][0] == player && board[1][1] == player && board[2][2] == player) {
        return true; // Diagonal win (top-left to bottom-right)
    }
    if (board[0][2] == player && board[1][1] == player && board[2][0] == player) {
        return true; // Diagonal win (top-right to bottom-left)
    }
    return false;
}

// Function to check if the game is a draw
bool checkDraw(const std::vector<std::vector<char>>& board) {
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            if (board[i][j] == ' ') {
                return false; // There are empty spaces, so the game is not a draw yet
            }
        }
    }
    return true; // All spaces are filled, and no player has won
}

int main() {
    std::vector<std::vector<char>> board(3, std::vector<char>(3, ' ')); // Initialize the empty game board
    char currentPlayer = 'X';

    std::cout << "Welcome to Tic-Tac-Toe!" << std::endl;

    do {
        std::cout << "Current board:" << std::endl;
        displayBoard(board);

        int row, col;
        do {
            std::cout << "Player " << currentPlayer << ", enter your move (row and column): ";
            std::cin >> row >> col;
        } while (row < 0 || row >= 3 || col < 0 || col >= 3 || board[row][col] != ' ');

        board[row][col] = currentPlayer;

        if (checkWin(board, currentPlayer)) {
            std::cout << "Player " << currentPlayer << " wins!" << std::endl;
            break;
        } else if (checkDraw(board)) {
            std::cout << "It's a draw!" << std::endl;
            break;
        }

        // Switch players
        currentPlayer = (currentPlayer == 'X') ? 'O' : 'X';

    } while (true);

    std::cout << "Final board:" << std::endl;
    displayBoard(board);

    std::cout << "Do you want to play again? (y/n): ";
    char playAgain;
    std::cin >> playAgain;

    if (playAgain == 'n' || playAgain == 'N') {
        std::cout << "Thank you for playing Tic-Tac-Toe!" << std::endl;
    }

    return 0;
}
