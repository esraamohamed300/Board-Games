#include <iostream>
#include "BoardGame_Classes.h"
#include "Game2.h"
#include "Game5.h"
#include "Game1.h"
#include"Game4.h"
#include"Game9.h"
#include"Game6.h"
#include"Game3.h"
#include"Game8.h"
using namespace std;

void menu() {
    int gamenum;
    cout << "\n WELCOME TO BOARD GAMES :)" << endl;
    cout << "______________________________" << endl;
    cout << "choose a game number to play: " << endl<<endl;
    cout << "1. Pyramic Tic-Tac-Toe" << endl;
    cout << "2. four in row" << endl;
    cout << "3. 5 x 5 Tic Tac Toe" << endl;
    cout << "4. Word Tic-tac-toe" << endl;
    cout << "5. Numerical Tic-Tac-Toe" << endl;
    cout << "6. Misere Tic Tac Toe" << endl;
    cout << "8. Ultimate Tic Tac Toe" << endl;
    cout << "9. SUS" << endl;
    cin >> gamenum;
    cout << "__________________________________________________" <<endl<< endl;
    if (gamenum == 1) {


        int choice;
        Player<char>* players[2];
        X_O_Board<char>* B = new X_O_Board<char>();
        string playerXName, playerOName;

        cout << "*Welcome to Game1*\n" << endl;
        // Set up player 1

        cout << "Choose Player'X' type:\n";
        cout << "1. Human\n";
        cout << "2. Random Computer\n";
        cin >> choice;
        if (choice == 1) {
            cout << "Enter Player'X' name: ";
            cin >> playerXName;

        }


        switch (choice) {
        case 1:

            players[0] = new X_O_Player<char>(playerXName, 'X');
            break;
        case 2:
            players[0] = new X_O_Random_Player<char>('X');
            break;
        default:
            cout << "Invalid choice for Player'X'. Exiting the game.\n";
            return;
        }


      

        // Set up player 2
        cout << "Choose Player'O' type:\n";
        cout << "1. Human\n";
        cout << "2. Random Computer\n";
        cin >> choice;
        if (choice == 1) {
            cout << "Enter Player'O' name: ";
            cin >> playerOName;
        }
        switch (choice) {
        case 1:
            players[1] = new X_O_Player<char>(playerOName, 'O');
            break;
        case 2:
             players[1] = new X_O_Random_Player<char>('O');
            break;
        default:
            cout << "Invalid choice for Player'O'. Exiting the game.\n";
            return;
        }



        // Create the game manager and run the game
         GameManager<char> x_o_game(B, players);
         x_o_game.run();

        // Clean up
        delete B;
        for (int i = 0; i < 2; ++i) {
            delete players[i];
        } 
    }


    else if (gamenum == 2) {
        int choice;
        Player<char>* players[2];
        game2_Board<char>* B = new game2_Board<char>();
        string player1Name, player2Name;


        cout << "*Welcome to Game2*\n" << endl;

        // Set up player 1

        cout << "Choose Player'X' type:\n";
        cout << "1. Human\n";
        cout << "2. Random Computer\n";
        cin >> choice;
        if (choice == 1) {
            cout << "Enter Player'X' name: ";
            cin >> player1Name;

        }


        switch (choice) {
        case 1:

            players[0] = new game2_Player<char>(player1Name, 'X');
            break;
        case 2:
            players[0] = new game2_Random_Player<char>('X');
            break;
        default:
            cout << "Invalid choice for Player'X'. Exiting the game.\n";
            return ;
        }

        // Set up player 2
        cout << "Choose Player'O' type:\n";
        cout << "1. Human\n";
        cout << "2. Random Computer\n";
        cin >> choice;
        if (choice == 1) {
            cout << "Enter Player'O' name: ";
            cin >> player2Name;
        }
        switch (choice) {
        case 1:
            players[1] = new game2_Player<char>(player2Name, 'O');
            break;
        case 2:
            players[1] = new game2_Random_Player<char>('O');
            break;
        default:
            cout << "Invalid choice for Player'O'. Exiting the game.\n";
            return ;
        }

        // Create the game manager and run the game
        GameManager<char> game2(B, players);
        game2.run();

        // Clean up
        delete B;
        for (int i = 0; i < 2; ++i) {
            delete players[i];
        }
    }


    else if (gamenum == 3) {
        int choice;
        Player<char>* players[2];
        game3_Board<char>* B = new game3_Board<char>();
        string player1Name, player2Name;


        cout << "*Welcome to Game3*\n" << endl;

        // Set up player 1

        cout << "Choose Player'X' type:\n";
        cout << "1. Human\n";
        cout << "2. Random Computer\n";
        cin >> choice;
        if (choice == 1) {
            cout << "Enter Player'X' name: ";
            cin >> player1Name;

        }


        switch (choice) {
        case 1:

            players[0] = new game3_Player<char>(player1Name, 'X');
            break;
        case 2:
            players[0] = new game3_Random_Player<char>('X');
            break;
        default:
            cout << "Invalid choice for Player'X'. Exiting the game.\n";
            return;
        }

        // Set up player 2
        cout << "Choose Player'O' type:\n";
        cout << "1. Human\n";
        cout << "2. Random Computer\n";
        cin >> choice;
        if (choice == 1) {
            cout << "Enter Player'O' name: ";
            cin >> player2Name;
        }
        switch (choice) {
        case 1:
            players[1] = new game3_Player<char>(player2Name, 'O');
            break;
        case 2:
            players[1] = new game3_Random_Player<char>('O');
            break;
        default:
            cout << "Invalid choice for Player'O'. Exiting the game.\n";
            return;
        }

        // Create the game manager and run the game
        GameManager<char> game3(B, players);
        game3.run();

        // Clean up
        delete B;
        for (int i = 0; i < 2; ++i) {
            delete players[i];
        }
    }
        

    else if (gamenum == 4) {

         int choice;
         Player<char>* players[2];
         game4_Board<char>* B = new game4_Board<char>();
         string player1Name, player2Name;

         cout << "Welcome to Game4 :\n";

         // Set up player 1

         cout << "Choose Player 1 type:\n";
         cout << "1. Human\n";
         cout << "2. Random Computer\n";
         cin >> choice;
         if (choice == 1) {
             cout << "Enter Player 1 name: ";
             cin >> player1Name;
         }


         switch (choice) {
         case 1:
             players[0] = new game4_Player<char>(player1Name, ' ');
             break;
         case 2:
             players[0] = new game4_Random_Player<char>(' ');
             break;
         default:
             cout << "Invalid choice for Player 1. Exiting the game.\n";
             return;
         }

         // Set up player 2

         cout << "Choose Player 2 type:\n";
         cout << "1. Human\n";
         cout << "2. Random Computer\n";
         cin >> choice;
         if (choice == 1) {
             cout << "Enter Player 2 name: ";
             cin >> player2Name;
         }

         switch (choice) {
         case 1:
             players[1] = new game4_Player<char>(player2Name, ' ');
             break;
         case 2:
             players[1] = new game4_Random_Player<char>(' ');
             break;
         default:
             cout << "Invalid choice for Player 2. Exiting the game.\n";
             return;
         }

         // Create the game manager and run the game
         GameManager<char> game4_game(B, players);
         game4_game.run();

         // Clean up
         delete B;
         for (int i = 0; i < 2; ++i) {
             delete players[i];
         }



     }

    else if (gamenum == 5) {
        int choice;
        Player<int>* players[2];
        game5_Board<int>* B = new game5_Board<int>();
        string player1Name, player2Name;


        cout << "*Welcome to Game5*\n" << endl;

        // Set up player 1

        cout << "Choose Player 1 type:\n";
        cout << "1. Human\n";
        cout << "2. Random Computer\n";
        cin >> choice;
        if (choice == 1) {
            cout << "Enter Player 1 name: ";
            cin >> player1Name;

        }


        switch (choice) {
        case 1:

            players[0] = new game5_Player<int>(player1Name, 0);
            break;
        case 2:
            players[0] = new game5_Random_Player<int>(0);
            break;
        default:
            cout << "Invalid choice for Player 1. Exiting the game.\n";
            return;
        }

        // Set up player 2
        cout << "Choose Player 2 type:\n";
        cout << "1. Human\n";
        cout << "2. Random Computer\n";
        cin >> choice;
        if (choice == 1) {
            cout << "Enter Player 2 name: ";
            cin >> player2Name;
        }
        switch (choice) {
        case 1:
             players[1] = new game5_Player<int>(player2Name, 0);
            break;
        case 2:
            players[1] = new game5_Random_Player<int>(0);
            break;
        default:
            cout << "Invalid choice for Player 2. Exiting the game.\n";
            return;
        }

        // Create the game manager and run the game
        GameManager<int> game5(B, players);
        game5.run();

        // Clean up
        delete B;
        for (int i = 0; i < 2; ++i) {
            delete players[i];
        }
    }


    else if (gamenum == 6) {
        int choice;
        Player<char>* players[2];
        Game6_Board<char>* B = new Game6_Board<char>();
        string playerXName, playerOName;


        cout << "*Welcome to Game6*\n" << endl;

        // Set up player 1

        cout << "Choose Player'X' type:\n";
        cout << "1. Human\n";
        cout << "2. Random Computer\n";
        cin >> choice;
        if (choice == 1) {
            cout << "Enter Player'X' name: ";
            cin >> playerXName;

        }


        switch (choice) {
        case 1:

            players[0] = new  Game6_Player<char>(playerXName, 'X');
            break;
        case 2:
            players[0] = new  Game6_Random_Player<char>('X');
            break;
        default:
            cout << "Invalid choice for Player'X'. Exiting the game.\n";
            return;
        }

        // Set up player 2
        cout << "Choose Player'O' type:\n";
        cout << "1. Human\n";
        cout << "2. Random Computer\n";
        cin >> choice;
        if (choice == 1) {
            cout << "Enter Player'O' name: ";
            cin >> playerOName;
        }
        switch (choice) {
        case 1:
            players[1] = new  Game6_Player<char>(playerOName, 'O');
            break;
        case 2:
            players[1] = new  Game6_Random_Player<char>('O');
            break;
        default:
            cout << "Invalid choice for Player'O'. Exiting the game.\n";
            return;
        }

        // Create the game manager and run the game
        GameManager<char>  Game6(B, players);
        Game6.run();

        // Clean up
        delete B;
        for (int i = 0; i < 2; ++i) {
            delete players[i];
        }
    }

    else if (gamenum == 8) {


            int choice;
            Player<char>* players[2];
            Ultimate_TicTacToe_Board<char>* B = new Ultimate_TicTacToe_Board<char>();
            string playerXName, playerOName;

            cout << "Welcome to Game8 :)\n";

            // Set up player 1

            cout << "Choose Player X type:\n";
            cout << "1. Human\n";
            cout << "2. Random Computer\n";
            cin >> choice;
            if (choice == 1)
            {
                cout << "Enter Player X name: ";
                cin >> playerXName;
            }


            switch (choice) {
            case 1:
                players[0] = new HumanPlayer<char>(playerXName, 'X');
                break;
            case 2:
                players[0] = new Random_Player<char>('X');
                break;
            default:
                cout << "Invalid choice for Player X. Exiting the game.\n";
                return ;
            }

            // Set up player 2

            cout << "Choose Player O type:\n";
            cout << "1. Human\n";
            cout << "2. Random Computer\n";
            cin >> choice;
            if (choice == 1)
            {
                cout << "Enter Player O name: ";
                cin >> playerOName;
            }


            switch (choice) {
            case 1:
                players[1] = new HumanPlayer<char>(playerOName, 'O');
                break;
            case 2:
                players[1] = new Random_Player<char>('O');
                break;
            default:
                cout << "Invalid choice for Player O. Exiting the game.\n";
                return ;
            }

            // Create the game manager and run the game
            GameManager<char> game(B, players);
            game.run();

            // Clean up
            delete B;
            for (int i = 0; i < 2; ++i) {
                delete players[i];
            }

              

    }


    else if (gamenum == 9) {
        int choice;
        Player<char>* players[2];
        game9_Board<char>* B = new game9_Board<char>();
        string playerSName, playerUName;


        cout << "*Welcome to Game9*\n" << endl;

        // Set up player 1

        cout << "Choose Player'S' type:\n";
        cout << "1. Human\n";
        cout << "2. Random Computer\n";
        cin >> choice;
        if (choice == 1) {
            cout << "Enter Player'S' name: ";
            cin >> playerSName;

        }


        switch (choice) {
        case 1:

            players[0] = new game9_Player<char>(playerSName, 'S');
            break;
        case 2:
            players[0] = new game9_Random_Player<char>('S');
            break;
        default:
            cout << "Invalid choice for Player'S'. Exiting the game.\n";
            return;
        }

        // Set up player 2
        cout << "Choose Player'U' type:\n";
        cout << "1. Human\n";
        cout << "2. Random Computer\n";
        cin >> choice;
        if (choice == 1) {
            cout << "Enter Player'U' name: ";
            cin >> playerUName;
        }
        switch (choice) {
        case 1:
            players[1] = new game9_Player<char>(playerUName, 'U');
            break;
        case 2:
            players[1] = new game9_Random_Player<char>('U');
            break;
        default:
            cout << "Invalid choice for Player'U'. Exiting the game.\n";
            return;
        }

        // Create the game manager and run the game
        GameManager<char> game9(B, players);
        game9.run();

        // Clean up
        delete B;
        for (int i = 0; i < 2; ++i) {
            delete players[i];
        }
    }


    else { cout << "INVALID INPUT" << endl; }
}





int main() {

    menu();

    return 0;
}