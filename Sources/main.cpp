// Author: Eduardo Nunez
// Author email: eduardonunez.eng@gmail.com

#include <iostream>
// Global variables
// 2 Dimensionall array for our board
char board[3][3] = {{'1', '2', '3'}, {'4', '5', '6'}, {'7', '8', '9'}};
char current_marker;
int current_player;

// Drawing our board in 2 dimensions
void drawboard()
{
    std::cout << " " << board[0][0] << " | " << board[0][1] << " | " << board[0][2] << std::endl;
    std::cout << "-----------\n";
    std::cout << " " << board[1][0] << " | " << board[1][1] << " | " << board[1][2] << std::endl;
    std::cout << "-----------\n";
    std::cout << " " << board[2][0] << " | " << board[2][1] << " | " << board[2][2] << std::endl;
}

bool placeMarker(int slot)
{
    int row = slot / 3, col = 0;
    if (slot % 3 == 0)
    {
        row = row - 1;
        col = 2;
    }
    else{
        col = slot % 3 - 1;
    }
    if(board[row][col] != 'X' && board[row][col] != 'O'){
        board[row][col] = current_marker;
        return true;
    }
    return false;
}

int winner()
{
    for (int i = 0; i < 3; i++){
        // rows
        if(board[i][0] == board[i][1] && board[i][1] == board[i][2]){
            return current_player;
        }
        // columns
        if (board[0][i] == board[1][i] && board[1][i] == board[2][i]){
            return current_player;
        }
    }
    // Diagonals
    if(board[0][0] == board[1][1] && board[1][1] == board[2][2]){
        return current_player;
    }
    if (board[0][2] == board[1][1] && board[1][1] == board[2][0])
    {
        return current_player;
    }
    return 0;   // means no winner
}

void swapPlayerAndMarker(){
    if (current_marker == 'X'){
        current_marker = 'O';
    }
    else{
        current_marker = 'X';
    }
    if (current_player == 1){
        current_player = 2;
    }
    else{
        current_player = 1;
    }
}

void game(){
    char player1_marker;
    std::cout << "Welcome to Eduardo Nunez's Tic-Tac-Toe Game!\n" \
    "Player 1 choose your marker (X or O):\n";
    std::cin >> player1_marker;

    current_player = 1;
    current_marker = player1_marker;

    drawboard();

    int player_winner;

    // Game can only last 9 moves
    for (int i = 0; i < 9; i++){

        // Collecting player moves 
        std::cout << "It's player " << current_player << "'s turn. Enter your move:\n";
        int slot;
        std::cin >> slot;
        if(slot < 1 || slot > 9){
            std::cout << "That is an invalid slot, please try again!\n";
            i--;
            continue;
        }
        if(!placeMarker(slot)){
            std::cout << "That slot is already taken, Try another slot!\n";
            i--;
            continue;
        }

        // Playing game
        swapPlayerAndMarker();
        drawboard();

        // Check for a winner
        player_winner = winner();
        if(player_winner == 1){
            std::cout << "Player 1 is the winner!\n";
            break;
        }
        else if(player_winner == 2){
            std::cout << "Player 2 is the winner!\n";
            break;
        }
    }

    if(player_winner == 0)
    {
        std::cout << "It's a draw!\n";
    }
}

int main()
{
    game();
    return 0;
}