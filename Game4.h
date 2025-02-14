
#ifndef _GAME4_H
#define _GAME4_H

#include "BoardGame_Classes.h"
#include <set>
#include <vector>
using namespace std;

template <typename T>
class game4_Board :public Board<T> {
private:
    set<string>Wo_rd;
    bool validation(const string& word);
public:
    game4_Board();
    bool update_board(int x, int y, T symbol);
    void display_board();
    bool is_win();
    bool is_draw();
    bool game_is_over();

};

template <typename T>
class game4_Player : public Player<T> {
public:
    game4_Player(string name, T symbol);
    void getmove(int& x, int& y);

};

template <typename T>
class game4_Random_Player : public RandomPlayer<T> {
    vector<char> let_ters;
public:
    game4_Random_Player(T symbol);
    void getmove(int& x, int& y);

};





//--------------------------------------- IMPLEMENTATION

#include <iostream>
#include <iomanip>
#include <cctype>  // for toupper()
#include <fstream>
using namespace std;

template <typename T>
bool game4_Board<T>::validation(const string& word) {
    return Wo_rd.find(word) != Wo_rd.end();
}

// Constructor for X_O_Board
template <typename T>
game4_Board<T>::game4_Board() {
    this->rows = this->columns = 3;
    this->board = new char* [this->rows];
    for (int i = 0; i < this->rows; i++) {
        this->board[i] = new char[this->columns];
        for (int j = 0; j < this->columns; j++) {
            this->board[i][j] = 0;
        }
    }

    this->n_moves = 0;

    ifstream dict_file("dic.txt"); // Update to your file name
    if (!dict_file) {
        cerr << "Error: Unable to open dictionary file 'dic.txt'.\n";
        exit(1);
    }

    string word;
    while (dict_file >> word) {
        Wo_rd.insert(word); // Load words into the set
    }
    dict_file.close();
    cout << "Dictionary loaded successfully from 'dic.txt'.\n";


}

template <typename T>
bool game4_Board<T>::update_board(int x, int y, T mark) {
    // Only update if move is valid
    if (!(x < 0 || x >= this->rows || y < 0 || y >= this->columns) && (this->board[x][y] == 0 || mark == 0)) {
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
    return false;
}

// Display the board and the pieces on it
template <typename T>
void game4_Board<T>::display_board() {
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

// Returns true if there is any winner
template <typename T>
bool game4_Board<T>::is_win() {
    // Check rows
    string word;
    for (int i = 0; i < this->rows; i++) {
        word.clear();
        for (int j = 0; j < this->columns; j++) {
            if (this->board[i][j] != 0) {
                word += this->board[i][j];
            }
        }
        if (validation(word)) {
            return true;
        }
    }
    for (int i = 0; i < this->rows; i++) {
        word.clear();
        for (int j = 2; j >=0; j--) {
            if (this->board[i][j] != 0) {
                word += this->board[i][j];
            }
        }
        if (validation(word)) {
            return true;
        }
    }
   // Check columns
    for (int j = 0; j < this->columns; j++) {
        word.clear();
        for (int i = 0; i < this->rows; i++) {
            if (this->board[i][j] != 0) {
                word += this->board[i][j];
            }
        }
        if (validation(word)) {
            return true;
        }
    }

    for (int j = 0; j < this->columns; j++) {
        word.clear();
        for (int i = 2; i >=0; i--) {
            if (this->board[i][j] != 0) {
                word += this->board[i][j];
            }
        }
        if (validation(word)) {
            return true;
        }
    }

    // Check diagonals
    word.clear();
    for (int i = 0; i < this->rows; i++) {
        if (this->board[i][i] != 0) {
            word += this->board[i][i];
        }
    }
    if (validation(word)) {
        return true;
    }

    word.clear();
    for (int i = 2; i >= 0; i--) {
        if (this->board[i][i] != 0) {
            word += this->board[i][i];
        }
    }
    if (validation(word)) {
        return true;
    }

    word.clear();
    word += this->board[0][2];
    word += this->board[1][1];
    word += this->board[2][0];
    if (validation(word)) {
        return true;
    }
    word.clear();
    word += this->board[2][0];
    word += this->board[1][1];
    word += this->board[0][2];
    if (validation(word)) {
        return true;
    }

    return false;
}

// Return true if 9 moves are done and no winner
template <typename T>
bool game4_Board<T>::is_draw() {
    return (this->n_moves == 9 && !is_win());
}

template <typename T>
bool game4_Board<T>::game_is_over() {
    return is_win() || is_draw();
}

//--------------------------------------

// Constructor for X_O_Player
template <typename T>
game4_Player<T>::game4_Player(string name, T symbol) : Player<T>(name, symbol) {}

template <typename T>
void game4_Player<T>::getmove(int& x, int& y) {
    T letter;
    while (true) {
        cout << "\nPlease enter your move (x, y) as two numbers (0 to 2): ";
        cin >> x >> y;

        if (cin.fail() || x < 0 || x > 2 || y < 0 || y > 2) {
            cin.clear(); // Clear the error flag
            cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Discard invalid input
            cout << "Invalid input. Please try again.\n";
            continue;
        }

        cout << "Enter any letter you like: ";
        cin >> letter;

        if (!isalpha(letter)) {
            cout << "Invalid letter. Please enter a single alphabetic character.\n";
            continue;
        }

        this->symbol = toupper(letter); // If symbol assignment is intended
        break;
    }
}


// Constructor for X_O_Random_Player
template <typename T>
game4_Random_Player<T>::game4_Random_Player(T symbol) : RandomPlayer<T>(symbol) {
    this->dimension = 3;
    this->name = "Random Computer Player";
    srand(static_cast<unsigned int>(time(0)));  // Seed the random number generator

   this->let_ters ={
        'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J', 'K', 'L', 'M',
            'N', 'O', 'P', 'Q', 'R', 'S', 'T', 'U', 'V', 'W', 'X', 'Y', 'Z'
    };
}



template <typename T>

void game4_Random_Player<T>::getmove(int& x, int& y) {
    int z;
    x = rand() % this->dimension;  // Random number between 0 and 2
    y = rand() % this->dimension;
    z = rand() % this->let_ters.size();
    this->symbol = this-> let_ters[z];
}


#endif //_GAME4_H


