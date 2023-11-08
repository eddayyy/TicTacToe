/* ****************************************************************************************************************************
// Program name: "TicTacToe Game".This program allows 1 player to play a game of TicTacToe in the terminal against the        *
//                alpha-beta pruning game algorithms.                                                                         *
// This program is free software : you can redistribute it and / or modify it under the terms of the GNU General Public       *
// License version 3 as published by the Free Software Foundation.This program is distributed in the hope that it             *
// will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A            *
// PARTICULAR PURPOSE.See the GNU General Public License for more details.A copy of the GNU General Public                    *
// License v3 is available here : < https: // www.gnu.org/licenses/>.                                                         *
// ****************************************************************************************************************************

// ========1=========2=========3=========4=========5=========6=========7=========8=========9=========0=========1=========2=========3**

// Author Information
//   Author name : Eduardo Nunez
//   Author email : eduardonunez.eng@gmail.com
//
// Program information
//   Program name: Alpha-Beta Pruning Tic-Tac-Toe
//   Programming languages : C++
//   Date program began : 2023 - Mar - 24 0200 PDT GMT - 07 : 00
//   Date of last update : (2023 - Mar - 25 0108 PDT GMT - 07 : 00)
//   Files in this program : main.cpp, tictactoe.cpp, tictactoe.h, run_alphabeta.sh
//   Status : Finished.
//   References consulted : C++ Standard Library, Stack Overflow, and cppreference.com

// Purpose:
//   This program demonstrates how to create a simple TicTacToe game that is played in the terminal and how to implement the alpha-beta pruning algorithms.
//   The intention is to teach readers the ins and outs of the program so they may recreate their own.

// This file
//   File name : tictactoe.cpp
//   Language : C++
// ========1=========2=========3=========4=========5=========6=========7=========8=========9=========0=========1=========2=========3**
// Compiling and Linking this program and file:
// File : run_alphabeta.sh
// All assembling, compiling, and linking has been condensed for the user into a single file the following is a user - tutorial.

// Instructions : Enter the following in your linux terminal

// chmod + x run_alphabeta.sh
// ./run_alphabeta.sh

// ===== Begin code area ======================================================================================================== */

#include <climits>
#include <limits>
#include <typeinfo>

#include <iostream>

#include "../AB-headers/tictactoe.h"

// Constructor initializes the board, current marker, and current player
TicTacToe::TicTacToe()
{
    // Initialize board
    board[0][0] = '1';
    board[0][1] = '2';
    board[0][2] = '3';
    board[1][0] = '4';
    board[1][1] = '5';
    board[1][2] = '6';
    board[2][0] = '7';
    board[2][1] = '8';
    board[2][2] = '9';

    // Set initial current marker and current player
    current_marker = 'X';
    current_player = 1;
}

int TicTacToe::evaluateBoard()
{
    // Iterate through each row and column of the 3x3 board
    for (int i = 0; i < 3; i++)
    {
        // Check rows for a winning combination
        // If all three cells in the row are the same (either 'O' or 'X')
        if (board[i][0] == board[i][1] && board[i][1] == board[i][2])
        {
            // If the winning combination is 'O', return a score of 10
            if (board[i][0] == 'O')
                return 10;
            // If the winning combination is 'X', return a score of -10
            else if (board[i][0] == 'X')
                return -10;
        }

        // Check columns for a winning combination
        // If all three cells in the column are the same (either 'O' or 'X')
        if (board[0][i] == board[1][i] && board[1][i] == board[2][i])
        {
            // If the winning combination is 'O', return a score of 10
            if (board[0][i] == 'O')
                return 10;
            // If the winning combination is 'X', return a score of -10
            else if (board[0][i] == 'X')
                return -10;
        }
    }

    // Check the first diagonal for a winning combination
    // If all three cells in the diagonal are the same (either 'O' or 'X')
    if (board[0][0] == board[1][1] && board[1][1] == board[2][2])
    {
        // If the winning combination is 'O', return a score of 10
        if (board[0][0] == 'O')
            return 10;
        // If the winning combination is 'X', return a score of -10
        else if (board[0][0] == 'X')
            return -10;
    }

    // Check the second diagonal for a winning combination
    // If all three cells in the diagonal are the same (either 'O' or 'X')
    if (board[0][2] == board[1][1] && board[1][1] == board[2][0])
    {
        // If the winning combination is 'O', return a score of 10
        if (board[0][2] == 'O')
            return 10;
        // If the winning combination is 'X', return a score of -10
        else if (board[0][2] == 'X')
            return -10;
    }

    // If there is no winner yet, return a score of 0
    return 0;
}

// Minimax function for determining the best move for the AI
int TicTacToe::minimax(int depth, int maxDepth, bool isMax, int alpha, int beta)
{
    // Evaluate the current board state
    int score = evaluateBoard();
    // If AI is winning, return score adjusted for depth
    if (score == 10)
        return score - depth;
    // If the opponent is winning, return score adjusted for depth
    if (score == -10)
        return score + depth;
    // If the board is full, return a draw (0)
    if (depth == 9)
        return 0;

    // If it's AI's turn (maximizing player)
    if (isMax)
    {
        int bestVal = INT_MIN;
        // Iterate through the board
        for (int i = 0; i < 3; i++)
        {
            for (int j = 0; j < 3; j++)
            {
                // If the cell is empty
                if (board[i][j] != 'X' && board[i][j] != 'O')
                {
                    // Make a temporary move for the AI
                    char prev = board[i][j];
                    board[i][j] = 'O';
                    // Recursively call minimax for the next depth
                    bestVal = std::max(bestVal, minimax(depth + 1, maxDepth, !isMax, alpha, beta));
                    // Undo the temporary move
                    board[i][j] = prev;
                    // Update alpha value for pruning
                    alpha = std::max(alpha, bestVal);
                    // Check for pruning opportunity
                    if (beta <= alpha)
                        break;
                }
            }
        }
        // Return the best value found
        return bestVal;
    }
    // If it's the opponent's turn (minimizing player)
    else
    {
        int bestVal = INT_MAX;
        // Iterate through the board
        for (int i = 0; i < 3; i++)
        {
            for (int j = 0; j < 3; j++)
            {
                // If the cell is empty
                if (board[i][j] != 'X' && board[i][j] != 'O')
                {
                    // Make a temporary move for the opponent
                    char prev = board[i][j];
                    board[i][j] = 'X';
                    // Recursively call minimax for the next depth
                    bestVal = std::min(bestVal, minimax(depth + 1, maxDepth, !isMax, alpha, beta));
                    // Undo the temporary move
                    board[i][j] = prev;
                    // Update beta value for pruning
                    beta = std::min(beta, bestVal);
                    // Check for pruning opportunity
                    if (beta <= alpha)
                        break;
                }
            }
        }
        // Return the best value found
        return bestVal;
    }
}

// Function to draw the Tic-Tac-Toe board
void TicTacToe::drawboard()
{
    std::cout << " " << board[0][0] << " | " << board[0][1] << " | " << board[0][2] << std::endl;
    std::cout << "-----------\n";
    std::cout << " " << board[1][0] << " | " << board[1][1] << " | " << board[1][2] << std::endl;
    std::cout << "-----------\n";
    std::cout << " " << board[2][0] << " | " << board[2][1] << " | " << board[2][2] << std::endl;
}

// Function to place a marker on the board
bool TicTacToe::placeMarker(int slot)
{
    // Calculate row and initialize col to 0
    int row = slot / 3, col = 0;

    // If slot is divisible by 3
    if (slot % 3 == 0)
    {
        // Decrement row by 1
        row = row - 1;
        // Set col to 2
        col = 2;
    }
    else // If slot is not divisible by 3
    {
        // Calculate col based on the remainder
        col = slot % 3 - 1;
    }

    // Check if the slot on the board is not already occupied by 'X' or 'O'
    if (board[row][col] != 'X' && board[row][col] != 'O')
    {
        // Place the current marker on the board
        board[row][col] = current_marker;
        // Return true for successful placement
        return true;
    }
    // Return false for unsuccessful placement (slot is already occupied)
    return false;
}

// Function to check for a winner
int TicTacToe::winner()
{
    for (int i = 0; i < 3; i++)
    {
        // Check for winning row
        if (board[i][0] == board[i][1] && board[i][1] == board[i][2])
        {
            // Current player wins if row has the same marker
            return current_player;
        }
        // Check for winning column
        if (board[0][i] == board[1][i] && board[1][i] == board[2][i])
        {
            // Current player wins if column has the same marker
            return current_player;
        }
    }
    // Check for winning diagonal (top-left to bottom-right)
    if (board[0][0] == board[1][1] && board[1][1] == board[2][2])
    {
        // Current player wins if diagonal has the same marker
        return current_player;
    }
    // Check for winning diagonal (top-right to bottom-left)
    if (board[0][2] == board[1][1] && board[1][1] == board[2][0])
    {
        // Current player wins if diagonal has the same marker
        return current_player;
    }
    // No winner found
    return 0;
}

// Function to swap the current player and marker
void TicTacToe::swapPlayerAndMarker()
{
    // Swap the current marker (X or O)
    if (current_marker == 'X')
    {
        current_marker = 'O';
    }
    else
    {
        current_marker = 'X';
    }

    // Swap the current player (1 or 2)
    if (current_player == 1)
    {
        current_player = 2;
    }
    else
    {
        current_player = 1;
    }
}

// Function to validate the player's marker choice
void TicTacToe::validateMarker(char &player1_marker)
{
    if (player1_marker != 'X' && player1_marker != 'O')
    {
        std::cout << "Invalid marker please try again!\n";
        std::cout << "Player 1 choose your marker (X or O):\n";
        std::cin >> player1_marker;
        validateMarker(player1_marker);
    }
}

// Main game loop function
void TicTacToe::game()
{
    char player1_marker;
    std::cout << "Welcome to Eduardo Nunez's Tic-Tac-Toe Game!\n"
                 "Player 1 choose your marker (X or O):\n";
    std::cin >> player1_marker;

    // Validate the player's marker input
    validateMarker(player1_marker);

    current_player = 1;
    current_marker = player1_marker;

    drawboard();

    int player_winner;

    // Game can only last 9 moves
    for (int i = 0; i < 9; i++)
    {
        // Collecting player moves
        if (current_player == 1)
        {
            std::cout << "It's player " << current_player << "'s turn. Enter your move:\n";
            int slot;
            std::cin >> slot;

            // Checking for invalid inputs that cause std::cin to fail due to type incompatibilities
            while (std::cin.fail())
            {
                // Clear Fail state
                std::cin.clear();
                // Ignore invalid input by clearing the input buffer
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                // Prompt user agaain and *HOPEFULLY* get a valid input
                std::cout << "Invalid input. Please enter an integer: ";
                std::cin >> slot;
            }

            if (slot < 1 || slot > 9)
            {
                std::cout << "That is an invalid slot, please try again!\n";
                i--;
                continue;
            }
            if (!placeMarker(slot))
            {
                std::cout << "That slot is already taken, Try another slot!\n";
                i--;
                continue;
            }
        }
        else
        {
            // Player 2 (AI) move
            int bestVal = INT_MIN;
            int bestMove = -1;
            int maxDepth = 9; // 9 Possible moves in a Tic-Tac-Toe game

            for (int depth = 1; depth <= maxDepth; depth++)
            {
                for (int slot = 1; slot <= 9; slot++)
                {
                    int row = (slot - 1) / 3;
                    int col = (slot - 1) % 3;

                    if (board[row][col] != 'X' && board[row][col] != 'O')
                    {
                        char prev = board[row][col];
                        board[row][col] = 'O';
                        int moveVal = minimax(0, depth, false, INT_MIN, INT_MAX);
                        board[row][col] = prev;

                        if (moveVal > bestVal)
                        {
                            bestVal = moveVal;
                            bestMove = slot;
                        }
                    }
                }
            }
            placeMarker(bestMove);
            std::cout << "Player 2 (AI) played at slot " << bestMove << std::endl;
        }

        // Playing game
        drawboard();
        // Check for a winner
        player_winner = winner();
        if (player_winner == 1)
        {
            std::cout << "Player 1 is the winner!\n";
            break;
        }
        else if (player_winner == 2)
        {
            std::cout << "Player 2 (AI) is the winner!\n";
            break;
        }
        swapPlayerAndMarker();
    }

    if (player_winner == 0)
    {
        std::cout << "It's a draw!\n";
    }
}
