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
//   Program name : TicTacToe Game
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
//   File name : tictactoe.h
//   Language : C++
// ========1=========2=========3=========4=========5=========6=========7=========8=========9=========0=========1=========2=========3**
// Compiling and Linking this program and file:
// File : r.sh
// All assembling, compiling, and linking has been condensed for the user into a single file the following is a user - tutorial.

// Instructions : Enter the following in your linux terminal

// chmod + x r.sh
// ./ r.sh

// ===== Begin code area ======================================================================================================== */

#ifndef TICTACTOE_H
#define TICTACTOE_H

#include <iostream>

// Global variables
class TicTacToe{
    public:
        TicTacToe();

        void drawboard();
        bool placeMarker(int slot);
        int winner();
        void swapPlayerAndMarker();
        void validateMarker(char &player1_marker);
        void game();

    private:
        char board[3][3];
        char current_marker;
        int current_player;
};

#endif // TICTACTOE_H
