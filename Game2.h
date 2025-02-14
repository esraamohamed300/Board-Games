
#ifndef _GAME2_H
#define _GAME2_H

#include "BoardGame_Classes.h"

template <typename T>
class game2_Board :public Board<T> {
public:
    game2_Board();
    bool update_board(int x, int y, T symbol);
    void display_board();
    bool is_win();
    bool is_draw();
    bool game_is_over();

};

template <typename T>
class game2_Player : public Player<T> {
public:
    game2_Player(string name, T symbol);
    void getmove(int& x, int& y);

};

template <typename T>
class game2_Random_Player : public RandomPlayer<T> {
public:
    game2_Random_Player(T symbol);
    void getmove(int& x, int& y);
};





//--------------------------------------- IMPLEMENTATION

#include <iostream>
#include <iomanip>
#include <cctype>  // for toupper()

using namespace std;

// Constructor for game2_Board
template <typename T>
game2_Board<T>::game2_Board() {
    this->rows = 6;
     this->columns = 7;
    this->board = new char* [this->rows];
    for (int i = 0; i < this->rows; i++) {
        this->board[i] = new char[this->columns];
        for (int j = 0; j < this->columns; j++) {
            this->board[i][j] = 0;
        }
    }
    this->n_moves = 0;
}

template <typename T>
bool game2_Board<T>::update_board(int x, int y, T mark) {
    // Only update if move is valid

    
        if (!(x < 0 || x >= this->rows || y < 0 || y >= this->columns) && (this->board[x][y] == 0 || mark == 0)) {
            if (x == 5) {
                if (mark == 0) {
                    this->n_moves--;
                    this->board[x][y] = 0;
                }
                else {
                    this->n_moves++;
                    this->board[x][y] = toupper(mark);
                }


                return true;
            }
            else {
                if (this->board[x + 1][y] != 0) {

                    if (mark == 0) {
                        this->n_moves--;
                        this->board[x][y] = 0;
                    }
                    else {
                        this->n_moves++;
                        this->board[x][y] = toupper(mark);
                    }


                    return true;
                }
            }
        
        } 
    return false;
}

// Display the board and the pieces on it
template <typename T>
void game2_Board<T>::display_board() {
    for (int i = 0; i < this->rows; i++) {
        cout << "\n| ";
        for (int j = 0; j < this->columns; j++) {
            cout << "(" << i << "," << j << ")";
            cout << setw(2) << this->board[i][j] << " |";
        }
        cout << "\n-------------------------------------------------------------";
    }
    cout << endl;
}

// Returns true if there is any winner
template <typename T>
bool game2_Board<T>::is_win() {
    // Check rows 
    for (int i = 0; i < this->rows; i++) {
        if ((this->board[i][0] == this->board[i][1] && this->board[i][1] == this->board[i][2] && this->board[i][2] == this->board[i][3] && this->board[i][0] != 0) ||
            (this->board[i][1] == this->board[i][2] && this->board[i][2] == this->board[i][3] && this->board[i][3] == this->board[i][4] && this->board[i][1] != 0) ||
            (this->board[i][2] == this->board[i][3] && this->board[i][3] == this->board[i][4] && this->board[i][4] == this->board[i][5] && this->board[i][2] != 0) ||
            (this->board[i][3] == this->board[i][4] && this->board[i][4] == this->board[i][5] && this->board[i][5] == this->board[i][6] && this->board[i][3] != 0))

        {
            return true;
        }
    }

    //check colloums

    for (int i = 0; i < this->columns; i++) {
        if ((this->board[0][i] == this->board[1][i] && this->board[1][i] == this->board[2][i] && this->board[2][i] == this->board[3][i] && this->board[0][i] != 0) ||
            (this->board[1][i] == this->board[2][i] && this->board[2][i] == this->board[3][i] && this->board[3][i] == this->board[4][i] && this->board[1][i] != 0) ||
            (this->board[2][i] == this->board[3][i] && this->board[3][i] == this->board[4][i] && this->board[4][i] == this->board[5][i] && this->board[2][i] != 0))


        {
            return true;
        }
    }

    //check diagnols left ro right

    for (int row = 0; row < 3; row++) {
        for (int col = 0; col < 4; col++) {
            if (this->board[row][col] != 0 &&
                this->board[row][col] == this->board[row + 1][col + 1] &&
                this->board[row + 1][col + 1] == this->board[row + 2][col + 2] &&
                this->board[row + 2][col + 2] == this->board[row + 3][col + 3] ) {
                return true;
            }
        }
    }

    //check diagnols right to left

    for (int row = 0; row < 3; row++) {
        for (int col = 3; col < 7; col++) {
            if (this->board[row][col] != 0 && this->board[row][col]== this->board[row + 1][col - 1]&&
                this->board[row + 1][col - 1]== this->board[row + 2][col - 2]&&
                this->board[row + 2][col - 2]== this->board[row + 3][col - 3]) {
                return true;
            }
        }
    }
    return false;
}
  
  

// Return true if 42 moves are done and no winner
template <typename T>
bool game2_Board<T>::is_draw() {
    return (this->n_moves == 42 && !is_win());
}

template <typename T>
bool game2_Board<T>::game_is_over() {
    return is_win() || is_draw();
}

//--------------------------------------

// Constructor for game2_Player
template <typename T>
game2_Player<T>::game2_Player(string name, T symbol) : Player<T>(name, symbol) {}

template <typename T>
void game2_Player<T>::getmove(int& x, int& y) {
    cout << "\nPlease enter your move x (0 to 5) and y (0 to 6) separated by spaces: ";
    cin >> x >> y;
}

// Constructor for game2_Random_Player
template <typename T>
game2_Random_Player<T>::game2_Random_Player(T symbol) : RandomPlayer<T>(symbol) {
    
   
    srand(static_cast<unsigned int>(time(0)));  // Seed the random number generator
}


int r = 6;
int c = 7;
template <typename T>
void game2_Random_Player<T>::getmove(int& x, int& y) {
    x = rand() % r;  // Random number between 0 and 5
    y = rand() % c; // Random number between 0 and 6
}
#endif //_Game2_H




