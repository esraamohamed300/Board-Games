
#ifndef _GAME5_H
#define _GAME5_H

#include "BoardGame_Classes.h"
#include<set>

template <typename T>
class game5_Board :public Board<T> {
private:
    set<int>usednums;
public:
    game5_Board();
    bool update_board(int x, int y, T symbol);
    void display_board();
    bool is_win();
    bool is_draw();
    bool game_is_over();


};

template <typename T>
class game5_Player : public Player<T> {


public:
    game5_Player(string name, T symbol);
    void getmove(int& x, int& y);


};

template <typename T>
class game5_Random_Player : public RandomPlayer<T> {
public:
    game5_Random_Player(T symbol);
    void getmove(int& x, int& y);
};





//--------------------------------------- IMPLEMENTATION

#include <iostream>
#include <iomanip>
#include <cctype>  // for toupper()

using namespace std;

// Constructor for game5_Board
template <typename T>
game5_Board<T>::game5_Board() {
    this->rows = 3;
    this->columns = 3;
    this->board = new int* [this->rows];
    for (int i = 0; i < this->rows; i++) {
        this->board[i] = new int[this->columns];
        for (int j = 0; j < this->columns; j++) {
            this->board[i][j] = 0;
        }
    }
    this->n_moves = 0;
}

template <typename T>
bool game5_Board<T>::update_board(int x, int y, T mark) {
    // Only update if move is valid


    if (!(x < 0 || x >= this->rows || y < 0 || y >= this->columns) && (this->board[x][y] == 0)) {

        if (this->usednums.find(mark) != this->usednums.end()) {
            cout << "THIS NUMBER HAS BEEN ALREADY TAKEN" << endl;
            return false;
        }

        if (this->n_moves % 2 == 0) {
            if (mark == 1 || mark == 3 || mark == 5 || mark == 7 || mark == 9) {
                this->n_moves++;
                this->board[x][y] = mark;
                this->usednums.insert(mark);
                return true;
            }
            else if (mark == 0) {

                this->n_moves--;
                this->board[x][y] = 0;
                return true;

            }
        }
        else if (this->n_moves % 2 != 0) {
            if (mark == 2 || mark == 4 || mark == 6 || mark == 8) {
                this->n_moves++;
                this->board[x][y] = mark;
                this->usednums.insert(mark);
                return true;
            }
            else if (mark == 0) {

                this->n_moves--;
                this->board[x][y] = 0;
                return true;

            }

        }


    }
    return false;
}


// Display the board and the pieces on it
template <typename T>
void game5_Board<T>::display_board() {
    for (int i = 0; i < this->rows; i++) {
        cout << "\n| ";
        for (int j = 0; j < this->columns; j++) {
            cout << "(" << i << "," << j << ")";
            cout << setw(2) << this->board[i][j] << " |";
        }
        cout << "\n------------------------------";
    }
    cout << endl;
}

// Returns true if there is any winner
template <typename T>
bool game5_Board<T>::is_win() {
    // Check rows and columns
    for (int i = 0; i < this->rows; i++) {
        if ((this->board[i][0] + this->board[i][1] + this->board[i][2] == 15 && this->board[i][0] != 0
            && this->board[i][1] != 0 && this->board[i][2] != 0) ||
            (this->board[0][i] + this->board[1][i] + this->board[2][i] == 15
                && this->board[0][i] != 0 && this->board[1][i] != 0 && this->board[2][i] != 0)) {
            return true;
        }
    }

    // Check diagonals
    if ((this->board[0][0] + this->board[1][1] + this->board[2][2] == 15
        && this->board[0][0] != 0 && this->board[1][1] != 0 && this->board[2][2] != 0) ||
        (this->board[0][2] + this->board[1][1] + this->board[2][0] == 15
            && this->board[0][2] != 0 && this->board[1][1] != 0 && this->board[2][0] != 0)) {
        return true;
    }

    return false;
}

// Return true if 9 moves are done and no winner
template <typename T>
bool game5_Board<T>::is_draw() {
    return (this->n_moves == 9 && !is_win());

}

template <typename T>
bool game5_Board<T>::game_is_over() {
    return is_win() || is_draw();
}

//--------------------------------------

// Constructor for game5_Player
template <typename T>
game5_Player<T>::game5_Player(string name, T symbol) : Player<T>(name, symbol) {}

template <typename T>
void game5_Player<T>::getmove(int& x, int& y) {

    int number;
    cout << "\nPlease enter your move x,y(0 to 2) and the number separated by spaces: ";
    cin >> x >> y >> number;
    this->symbol = number;
}



// Constructor for game5_Random_Player
template <typename T>
game5_Random_Player<T>::game5_Random_Player(T symbol) : RandomPlayer<T>(symbol) {

    this->dimension = 3;

    srand(static_cast<unsigned int>(time(0)));  // Seed the random number generator
}



template <typename T>
void game5_Random_Player<T>::getmove(int& x, int& y) {
    x = rand() % this->dimension;  // Random number between 0 and 2
    y = rand() % this->dimension; // Random number between 0 and 2

    int number;

    number = (rand() % 9) + 1;//// Random number between 1 and 9
    this->symbol = number;


}
#endif //_Game5_H
