/* ****************************************************************************************************************************
// Program name : "TicTacToe Game".This program allows 2 players to play a game of TicTacToe in the terminal.                 *
//                                                                                                                            *
// This program is free software : you can redistribute it and / or modify it under the terms of the GNU General Public       *
// License version 3 as published by the Free Software Foundation.This program is distributed in the hope that it             *
// will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A            *
// PARTICULAR PURPOSE.See the GNU General Public License for more details.A copy of the GNU General Public                    *
// License v3 is available here : < https: // www.gnu.org/licenses/>.                                                         *
// ****************************************************************************************************************************

// ========1=========2=========3=========4=========5=========6=========7=========8=========9=========0=========1=========2=========3**

// Author Information
//   Author name : Eduardo M.Nunez Gomez
//   Author email : eduardonunez @csu.fullerton.edu
//
// Program information
//   Program name: TicTacToe Game
//   Programming languages : C++
//   Date program began : 2023 - Mar - 24 2300 PDT GMT - 07 : 00
//   Date of last update : 2023 - Mar - 25 0108 PDT GMT - 07 : 00
//   Files in this program : main.cpp, tictactoe.cpp, tictactoe.h, run_tictactoe.sh
//   Status : Finished.
//   References consulted : C++ Standard Library, Stack Overflow, and cppreference.com

// Purpose:
//   This program demonstrates how to create a simple TicTacToe game that can be played by 2 players in the terminal.
//   The intention is to teach readers the ins and outs of the program so they may recreate their own.

// This file
//   File name : tictactoe.cpp
//   Language : C++
// ========1=========2=========3=========4=========5=========6=========7=========8=========9=========0=========1=========2=========3**
// Compiling and Linking this program and file:
// File : r.sh
// All assembling, compiling, and linking has been condensed for the user into a single file the following is a user - tutorial.

// Instructions : Enter the following in your linux terminal

// chmod + x r.sh
// ./ r.sh

// ===== Begin code area ======================================================================================================== */

#include <iostream>
#include "../headers/tictactoe.h"

TicTacToe::TicTacToe()
{
    board[0][0] = '1'; board[0][1] = '2'; board[0][2] = '3';
    board[1][0] = '4'; board[1][1] = '5'; board[1][2] = '6';
    board[2][0] = '7'; board[2][1] = '8'; board[2][2] = '9';
    current_marker = 'X';
    current_player = 1;
}

// Drawing our board in 2 dimensions
void TicTacToe::drawboard()
{
    std::cout << " " << board[0][0] << " | " << board[0][1] << " | " << board[0][2] << std::endl;
    std::cout << "-----------\n";
    std::cout << " " << board[1][0] << " | " << board[1][1] << " | " << board[1][2] << std::endl;
    std::cout << "-----------\n";
    std::cout << " " << board[2][0] << " | " << board[2][1] << " | " << board[2][2] << std::endl;
}

bool TicTacToe::placeMarker(int slot)
{
    int row = slot / 3, col = 0;
    if (slot % 3 == 0)
    {
        row = row - 1;
        col = 2;
    }
    else
    {
        col = slot % 3 - 1;
    }
    if (board[row][col] != 'X' && board[row][col] != 'O')
    {
        board[row][col] = current_marker;
        return true;
    }
    return false;
}

int TicTacToe::winner()
{
    for (int i = 0; i < 3; i++)
    {
        // rows
        if (board[i][0] == board[i][1] && board[i][1] == board[i][2])
        {
            return current_player;
        }
        // columns
        if (board[0][i] == board[1][i] && board[1][i] == board[2][i])
        {
            return current_player;
        }
    }
    // Diagonals
    if (board[0][0] == board[1][1] && board[1][1] == board[2][2])
    {
        return current_player;
    }
    if (board[0][2] == board[1][1] && board[1][1] == board[2][0])
    {
        return current_player;
    }
    return 0; // means no winner
}

void TicTacToe::swapPlayerAndMarker()
{
    if (current_marker == 'X')
    {
        current_marker = 'O';
    }
    else
    {
        current_marker = 'X';
    }
    if (current_player == 1)
    {
        current_player = 2;
    }
    else
    {
        current_player = 1;
    }
}

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
        std::cout << "It's player " << current_player << "'s turn. Enter your move:\n";
        int slot;
        std::cin >> slot;
        if (slot < 1 || slot > 9 || !int(slot))
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
            std::cout << "Player 2 is the winner!\n";
            break;
        }
        swapPlayerAndMarker();
    }

    if (player_winner == 0)
    {
        std::cout << "It's a draw!\n";
    }
}
