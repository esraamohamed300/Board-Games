
#ifndef _GAME1_H
#define _GAME1_H

#include "BoardGame_Classes.h"

template <typename T>
class X_O_Board :public Board<T> {
public:
    X_O_Board();
    bool update_board(int x, int y, T symbol);
    void display_board();
    bool is_win();
    bool is_draw();
    bool game_is_over();

};

template <typename T>
class X_O_Player : public Player<T> {
public:
    X_O_Player(string name, T symbol);
    void getmove(int& x, int& y);

};

template <typename T>
class X_O_Random_Player : public RandomPlayer<T> {
public:
    X_O_Random_Player(T symbol);
    void getmove(int& x, int& y);
};





//--------------------------------------- IMPLEMENTATION

#include <iostream>
#include <iomanip>
#include <cctype>  // for toupper()

using namespace std;

// Constructor for X_O_Board
template <typename T>
X_O_Board<T>::X_O_Board() {
    this->rows = 3;
    this->columns = 9;
    this->board = new char* [this->rows];
    int size[] = { 1,3,5 };
    for (int i = 0; i < this->rows; i++) {
        this->board[i] = new char[size[i]];
        for (int j = 0; j < size[i]; j++) {
            this->board[i][j] = 0;
        }
    }
    this->n_moves = 0;
}

template <typename T>
bool X_O_Board<T>::update_board(int x, int y, T mark) {
    // Only update if move is valid
    if (x < 0 || x >= this->rows || y < 0 || y >= (x * 2 + 1) || this->board[x][y] != 0) {
        return false;
    }

    this->board[x][y] = toupper(mark);
    this->n_moves++;

    return true;


}

// Display the board and the pieces on it
template <typename T>
void X_O_Board<T>::display_board() {
    int widths[] = { 1, 3, 5 }; // Number of cells at each level
    for (int i = 0; i < this->rows; i++) {
        cout << setw(6 - i * 2) << ""; // Indent for pyramid
        for (int j = 0; j < widths[i]; j++) {
            cout << (this->board[i][j] == 0 ? '.' : this->board[i][j]) << " ";
        }
        cout << "\n";
    }
}

// Returns true if there is any winner
template <typename T>
bool X_O_Board<T>::is_win() {
    char b[9] = { this->board[0][0],this->board[1][0],this->board[1][1],this->board[1][2],this->board[2][0],this->board[2][1],this->board[2][2],this->board[2][3],this->board[2][4] };
    //vertical
    if (b[0] == b[2] && b[2] == b[6] && b[0] != 0) {
        return true;
    }
    //Horizontal
    if ((b[1] == b[2] && b[2] == b[3] && b[1] != 0) || (b[4] == b[5] && b[5] == b[6] && b[4] != 0) || (b[5] == b[6] && b[6] == b[7] && b[5] != 0) || (b[6] == b[7] && b[7] == b[8] && b[6] != 0)) {
        return true;
    }
    //Diagonal
    if ((b[0] == b[1] && b[1] == b[4] && b[0] != 0) || (b[0] == b[3] && b[3] == b[8] && b[0] != 0)) {
        return true;
    }
   return false;
}

// Return true if 9 moves are done and no winner
template <typename T>
bool X_O_Board<T>::is_draw() {
    return (this->n_moves == 9 && !is_win());
}

template <typename T>
bool X_O_Board<T>::game_is_over() {
    return is_win() || is_draw();
}

//--------------------------------------

// Constructor for X_O_Player
template <typename T>
X_O_Player<T>::X_O_Player(string name, T symbol) : Player<T>(name, symbol) {}

template <typename T>
void X_O_Player<T>::getmove(int& x, int& y) {
    cout << "\nPlease enter your move x and y (0 to 2) separated by spaces: ";
    cin >> x >> y;
}


// Constructor for X_O_Random_Player
template <typename T>
X_O_Random_Player<T>::X_O_Random_Player(T symbol) : RandomPlayer<T>(symbol) {
    this->name = "Random Computer Player";
    srand(static_cast<unsigned int>(time(0)));  // Seed the random number generator
}

template <typename T>
void X_O_Random_Player<T>::getmove(int& x, int& y) {
    x = rand() % 3;  // Random number between 0 and 2
    y = rand() % 5;
}

#endif //_GAME1_H

