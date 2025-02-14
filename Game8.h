#ifndef GAME8_H
#define GAME8_H

#include "BoardGame_Classes.h"
#include <iostream>
#include <iomanip>
#include <cctype> // for toupper()
#include <cstdlib> // for rand() and srand()
#include <ctime>  

using namespace std;

// Small Tic Tac Toe board
template <typename T>
class MiniTicTacToeBoard : public Board<T> {
public:
    MiniTicTacToeBoard();
    bool update_board(int x, int y, T symbol) override;
    void display_board() override;
    bool is_win() override;
    bool is_draw() override;
    bool game_is_over() override;
    T find_winner();
    T fetch_cell(int x, int y) const;

private:
    void setup_board();
};

// Ultimate Tic Tac Toe Board
template <typename T>
class Ultimate_TicTacToe_Board : public Board<T> {
    MiniTicTacToeBoard<T>* boards[3][3];
    T main_board[3][3];

public:
    Ultimate_TicTacToe_Board();
    bool update_board(int x, int y, T symbol) override;
    void display_board() override;
    bool is_win() override;
    bool is_draw() override;
    bool game_is_over() override;
};

// Human Player
template <typename T>
class HumanPlayer : public Player<T> {
public:
    HumanPlayer(string n, T symbol);
    void getmove(int& x, int& y) override;
};

// Random Player
template <typename T>
class Random_Player : public RandomPlayer<T> {
public:
    Random_Player(T symbol);
    void getmove(int& x, int& y) override;
};

//--------------------------------------- IMPLEMENTATION

// Constructor for MiniTicTacToeBoard
template <typename T>
MiniTicTacToeBoard<T>::MiniTicTacToeBoard() {
    setup_board();
}

template <typename T>
void MiniTicTacToeBoard<T>::setup_board() {
    this->rows = 3;
    this->columns = 3;
    this->board = new T * [this->rows];
    for (int i = 0; i < this->rows; ++i) {
        this->board[i] = new T[this->columns];
        for (int j = 0; j < this->columns; ++j)
            this->board[i][j] = '.';
    }
}

template <typename T>
bool MiniTicTacToeBoard<T>::update_board(int x, int y, T symbol) {
    if (x >= 0 && x < this->rows && y >= 0 && y < this->columns && this->board[x][y] == '.') {
        this->board[x][y] = symbol;
        this->n_moves++;
        return true;
    }
    return false;
}

template <typename T>
void MiniTicTacToeBoard<T>::display_board() {
    for (int i = 0; i < this->rows; ++i) {
        for (int j = 0; j < this->columns; ++j)
            cout << this->board[i][j] << " ";
        cout << endl;
    }
}

template <typename T>
bool MiniTicTacToeBoard<T>::is_win() {
    // Check rows, columns, diagonals
    for (int i = 0; i < this->rows; ++i) {
        if (this->board[i][0] != '.' && this->board[i][0] == this->board[i][1] && this->board[i][1] == this->board[i][2])
            return true;
    }
    for (int j = 0; j < this->columns; ++j) {
        if (this->board[0][j] != '.' && this->board[0][j] == this->board[1][j] && this->board[1][j] == this->board[2][j])
            return true;
    }
    if (this->board[0][0] != '.' && this->board[0][0] == this->board[1][1] && this->board[1][1] == this->board[2][2])
        return true;
    if (this->board[0][2] != '.' && this->board[0][2] == this->board[1][1] && this->board[1][1] == this->board[2][0])
        return true;

    return false;
}

template <typename T>
bool MiniTicTacToeBoard<T>::is_draw() {
    return this->n_moves == this->rows * this->columns && !is_win();
}

template <typename T>
bool MiniTicTacToeBoard<T>::game_is_over() {
    return is_win() || is_draw();
}

template <typename T>
T MiniTicTacToeBoard<T>::find_winner() {
    return is_win() ? this->board[1][1] : '.';
}

template <typename T>
T MiniTicTacToeBoard<T>::fetch_cell(int x, int y) const {
    return this->board[x][y];
}

// Constructor for Ultimate_TicTacToe_Board
template <typename T>
Ultimate_TicTacToe_Board<T>::Ultimate_TicTacToe_Board() {
    this->rows = this->columns = 3;
    for (int i = 0; i < this->rows; ++i)
        for (int j = 0; j < this->columns; ++j) {
            this->boards[i][j] = new MiniTicTacToeBoard<T>();
            this->main_board[i][j] = '.';
        }
}

template <typename T>
bool Ultimate_TicTacToe_Board<T>::update_board(int x, int y, T symbol) {
    int big_x = x / 3, big_y = y / 3;
    int small_x = x % 3, small_y = y % 3;

    if (this->main_board[big_x][big_y] != '.')
        return false;  // Small board already claimed

    bool valid = this->boards[big_x][big_y]->update_board(small_x, small_y, symbol);
    if (valid && this->boards[big_x][big_y]->is_win()) {
        this->main_board[big_x][big_y] = symbol;
    }
    return valid;
}

template <typename T>
void Ultimate_TicTacToe_Board<T>::display_board() {
    for (int big_x = 0; big_x < 3; ++big_x) {
        for (int small_x = 0; small_x < 3; ++small_x) {
            for (int big_y = 0; big_y < 3; ++big_y) {
                for (int small_y = 0; small_y < 3; ++small_y) {
                    cout << this->boards[big_x][big_y]->fetch_cell(small_x, small_y) << " ";
                }
                cout << "  ";
            }
            cout << endl;
        }
        cout << endl;
    }
    cout << "************************************\n";
}

template <typename T>
bool Ultimate_TicTacToe_Board<T>::is_win() {
    // Check main board for a winner
    for (int i = 0; i < 3; ++i) {
        if (this->main_board[i][0] != '.' && this->main_board[i][0] == this->main_board[i][1] && this->main_board[i][1] == this->main_board[i][2])
            return true;
        if (this->main_board[0][i] != '.' && this->main_board[0][i] == this->main_board[1][i] && this->main_board[1][i] == this->main_board[2][i])
            return true;
    }
    if (this->main_board[0][0] != '.' && this->main_board[0][0] == this->main_board[1][1] && this->main_board[1][1] == this->main_board[2][2])
        return true;
    if (this->main_board[0][2] != '.' && this->main_board[0][2] == this->main_board[1][1] && this->main_board[1][1] == this->main_board[2][0])
        return true;

    return false;
}

template <typename T>
bool Ultimate_TicTacToe_Board<T>::is_draw() {
    for (int i = 0; i < 3; ++i)
        for (int j = 0; j < 3; ++j)
            if (this->main_board[i][j] == '.')
                return false;
    return true;
}

template <typename T>
bool Ultimate_TicTacToe_Board<T>::game_is_over() {
    return is_win() || is_draw();
}

// Constructor for HumanPlayer
template <typename T>
HumanPlayer<T>::HumanPlayer(string n, T symbol) : Player<T>(n, symbol) {}

template <typename T>
void HumanPlayer<T>::getmove(int& x, int& y) {
    cout << this->name << " (" << this->symbol << "), enter your move (x y): ";
    cin >> x >> y;
}

// Constructor for Random_Player
template <typename T>
Random_Player<T>::Random_Player(T symbol) : RandomPlayer<T>(symbol) {
    srand(static_cast<unsigned int>(time(0)));  // Seed the random number generator
}

template <typename T>
void Random_Player<T>::getmove(int& x, int& y) {
    x = rand() % 9;  // Random number between 0 and 8
    y = rand() % 9;
}

#endif // GAME8_H
