#ifndef _GAME9_H
#define _GAME9_H

#include "BoardGame_Classes.h"

template <typename T>
class game9_Board :public Board<T> {
protected:
    int points11 = 0;
    int points22 = 0;
    int lastx;
    int lasty;


public:
    game9_Board();
    bool update_board(int x, int y, T symbol);
    void display_board();
    bool is_win();
    bool is_draw();
    bool game_is_over();





};

template <typename T>
class game9_Player : public Player<T> {


public:
    game9_Player(string name, T symbol);
    void getmove(int& x, int& y);


};

template <typename T>
class game9_Random_Player : public RandomPlayer<T> {

public:
    game9_Random_Player(T symbol);
    void getmove(int& x, int& y);
};





//--------------------------------------- IMPLEMENTATION

#include <iostream>
#include <iomanip>
#include <cctype>  // for toupper()
#include<algorithm>
using namespace std;

int nnmoves;
bool dado;
// Constructor for SUS_Board
template <typename T>
game9_Board<T>::game9_Board() {
    this->rows = this->columns = 3;
    this->board = new char* [this->rows];
    for (int i = 0; i < this->rows; i++) {
        this->board[i] = new char[this->columns];
        for (int j = 0; j < this->columns; j++) {
            this->board[i][j] = 0;
        }
    }
    nnmoves = 0;
}

template <typename T>
bool game9_Board<T>::update_board(int x, int y, T mark) {

    if (nnmoves == 10) { return true; }
    // Only update if move is valid
    if (!(x < 0 || x >= this->rows || y < 0 || y >= this->columns) && this->board[x][y] == 0) {

       
        this->board[x][y] = toupper(mark);
        this->lastx = x;
        this->lasty = y;

        nnmoves++;
        return true;
    }
    return false;
}

// Display the board and the pieces on it
template <typename T>
void game9_Board<T>::display_board() {
    if (nnmoves == 10) { return; }
    for (int i = 0; i < this->rows; i++) {
        cout << "\n| ";
        for (int j = 0; j < this->columns; j++) {
            cout << "(" << i << "," << j << ")";
            cout << setw(2) << this->board[i][j] << " |";
        }
        cout << "\n-----------------------------";
    }
    cout << endl;
}


template <typename T>
bool game9_Board<T>::is_win() {



    // Check rows and columns for winning patterns

    if (this->board[this->lastx][0] == 'S' && this->board[this->lastx][1] == 'U' && this->board[this->lastx][2] == 'S') {
        if (nnmoves % 2 == 0) {
            this->points22++;


        }

        else { this->points11++; }

        cout << "PLAYER S POINTS: "<<this->points11 << " " << "PLAYER U POINTS: "<< this->points22 << endl;
    }
    if (this->board[0][this->lasty] == 'S' && this->board[1][this->lasty] == 'U' && this->board[2][this->lasty] == 'S') {
        if (nnmoves % 2 == 0) {
            this->points22++;

        }
        else {
            this->points11++;
        }

        cout << "PLAYER S POINTS: " << this->points11 << " " << "PLAYER U POINTS: " << this->points22 << endl;
    }


    // Check diagonals for winning patterns
    if (this->lastx == this->lasty && this->board[0][0] == 'S' && this->board[1][1] == 'U' && this->board[2][2] == 'S') {
        if (nnmoves % 2 == 0) {
            this->points22++;

        }
        else {
            this->points11++;
        }
        cout << "PLAYER S POINTS: " << this->points11 << " " << "PLAYER U POINTS: " << this->points22 << endl;
    }
    if (this->lastx + this->lasty == 2 && this->board[0][2] == 'S' && this->board[1][1] == 'U' && this->board[2][0] == 'S') {
        if (nnmoves % 2 == 0) {
            this->points22++;

        }
        else {
            this->points11++;
        }
        cout << "PLAYER S POINTS: " << this->points11 << " " << "PLAYER U POINTS: " << this->points22 << endl;
    }



    if (nnmoves == 9 && (this->points11 > this->points22)) {
        dado = true;
        return true;
    }
    else if (nnmoves == 9 && (this->points22 > this->points11)) {

        nnmoves++;
        dado =false;
        return false;



    }
    if (nnmoves == 10 && (this->points22 > this->points11)) {
        dado = true;
        return true;
    }
    dado = false;
    return false; // Always return false to prevent premature ending
}


// Return true if 9 moves are done and no winner
// Return true if 9 moves are done and no winner
template <typename T>
bool game9_Board<T>::is_draw() {
    return (nnmoves == 9 && dado==false);
}

template <typename T>
bool game9_Board<T>::game_is_over() {
    return dado==true || is_draw();
}

//--------------------------------------

// Constructor for SUS_Player

template <typename T>
game9_Player<T>::game9_Player(string name, T symbol) : Player<T>(name, symbol) {}

template <typename T>
void game9_Player<T>::getmove(int& x, int& y) {

    if (nnmoves == 10) {
        return;
    }
    cout << "\nPlease enter your move x and y (0 to 2) separated by spaces: ";
    cin >> x >> y;
}

// Constructor for SUS_Random_Player
template <typename T>
game9_Random_Player<T>::game9_Random_Player(T symbol) : RandomPlayer<T>(symbol) {
    this->dimension = 3;
    this->name = "Random Computer Player";
    srand(static_cast<unsigned int>(time(0)));  // Seed the random number generator
}

template <typename T>
void game9_Random_Player<T>::getmove(int& x, int& y) {
    if (nnmoves == 10) {
        return;
    }
    x = rand() % this->dimension;  // Random number between 0 and 2
    y = rand() % this->dimension;  // Random number between 0 and 2
}
#endif //_GAME9_H