

#pragma once
#ifndef _GAME6_H
#define _GAME6_H

#include "BoardGame_Classes.h"


template <typename T>
class Game6_Board : public Board<T> {
public:
    Game6_Board();
    bool update_board(int x, int y, T symbol);
    void display_board();
    bool is_win();
    bool is_draw();
    bool game_is_over();
};

template <typename T>
class Game6_Player : public Player<T> {
public:
    Game6_Player(std::string name, T symbol);
    void getmove(int& x, int& y);
    std::string get_name() const;
};

template <typename T>
class Game6_Random_Player : public RandomPlayer<T> {
public:
    Game6_Random_Player(T symbol);
    void getmove(int& x, int& y);
    std::string get_name() const;
};

//--------------------------------------- IMPLEMENTATION

#include <iostream>
#include <iomanip>
#include <cctype>  // for toupper()
#include <cstdlib> // for rand() and srand()
#include <ctime>   // for time()

using namespace std;
int Moves;
int K = 1000;
bool oufa;
// Constructor for Misere_TicTacToe_Board
template <typename T>
Game6_Board<T>::Game6_Board() {

    this->rows = this->columns = 3;
    this->board = new T * [this->rows];
    for (int i = 0; i < this->rows; i++) {
        this->board[i] = new T[this->columns];
        for (int j = 0; j < this->columns; j++) {
            this->board[i][j] = 0;
        }
    }
    Moves = 0;
}

template <typename T>
bool Game6_Board<T>::update_board(int x, int y, T mark) {
    if (Moves == K + 1)
    {
        return true;
    }
    if (!(x < 0 || x >= this->rows || y < 0 || y >= this->columns) && this->board[x][y] == 0) {
        Moves++;
        this->board[x][y] = toupper(mark);
        return true;
    }
    return false;
}

// Display the board and the pieces on it
template <typename T>
void Game6_Board<T>::display_board() {

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

// Returns true if there is any loser (three in a row)
template <typename T>
bool Game6_Board<T>::is_win() {

    // Check rows and columns
    if (Moves == K + 1)
    {
        oufa = true;
        return true;
    }
    for (int i = 0; i < this->rows; i++) {
        if ((this->board[i][0] != 0 && this->board[i][0] == this->board[i][1] && this->board[i][1] == this->board[i][2]) ||
            (this->board[0][i] != 0 && this->board[0][i] == this->board[1][i] && this->board[1][i] == this->board[2][i])) {
            K = Moves;
            Moves++;
            oufa = false;
            return false;
        }
    }
    // Check diagonals
    if ((this->board[0][0] != 0 && this->board[0][0] == this->board[1][1] && this->board[1][1] == this->board[2][2]) ||
        (this->board[0][2] != 0 && this->board[0][2] == this->board[1][1] && this->board[1][1] == this->board[2][0])) {
        K = Moves;
        Moves++;
        oufa = false;
        return false;
    }

    return false;
}

// Return true if all moves are done and no loser
template <typename T>
bool Game6_Board<T>::is_draw() {
    return (Moves == 9 && oufa==false);
}

template <typename T>
bool Game6_Board<T>::game_is_over() {
    return oufa==true|| is_draw();
}

//--------------------------------------

// Constructor for Misere_TicTacToe_Player
template <typename T>
Game6_Player<T>::Game6_Player(std::string name, T symbol) : Player<T>(name, symbol) {}

template <typename T>
void Game6_Player<T>::getmove(int& x, int& y) {
    if (Moves == K + 1)
    {
        return;
    }
    cout << "\nPlease enter your move x and y (0 to 2) separated by spaces: ";
    cin >> x >> y;
}

template <typename T>
std::string Game6_Player<T>::get_name() const {
    return this->name;
}

// Constructor for Misere_TicTacToe_Random_Player
template <typename T>
Game6_Random_Player<T>::Game6_Random_Player(T symbol) : RandomPlayer<T>(symbol) {
    this->dimension = 3;
    this->name = "Random Computer Player";
    srand(static_cast<unsigned int>(time(0)));  // Seed the random number generator
}

template <typename T>
void Game6_Random_Player<T>::getmove(int& x, int& y) {
    x = rand() % this->dimension;  // Random number between 0 and 2
    y = rand() % this->dimension;  // Random number between 0 and 2
}

template <typename T>
std::string Game6_Random_Player<T>::get_name() const {
    return this->name;
}

#endif //_GAME6_H
