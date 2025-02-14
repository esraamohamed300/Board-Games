🎲 Board Game Framework 🎮

📝 Overview

This project is a board game framework that utilizes Object-Oriented Programming (OOP) principles, focusing on modularity and reusability. It allows the creation of various board games without building them from scratch by inheriting from a set of base classes.

✨ Features

🛠 A generic game framework to create board games easily.

🎭 Includes a GameManager, Player, Board, and RandomPlayer.

🔄 Demonstrates the Open/Closed Principle by allowing extensions without modifying existing code.

🤖 Supports AI players for enhanced gameplay.

🎮 Implemented Games

This framework includes the following games:

1️⃣ Pyramid Tic-Tac-Toe 🔺

🏗 Board shaped like a pyramid (5-3-1 squares).

🎯 Win by getting three-in-a-row vertically, horizontally, or diagonally.

2️⃣ Four-in-a-Row 🔵🔴

🟦 Played on a 7x6 grid.

🔄 Players take turns marking the lowest available spot in a column.

🏆 Win by getting four-in-a-row.

3️⃣ 5x5 Tic-Tac-Toe ❌⭕

🎲 Played on a 5x5 board.

🔄 Players take turns marking X or O.

🏆 The player with the most three-in-a-row wins.

4️⃣ Word Tic-Tac-Toe 🔠

✍️ Players place letters instead of Xs and Os.

🏆 Form valid words horizontally, vertically, or diagonally to win.

📖 Uses a dictionary file (dic.txt) for validation.

5️⃣ Numerical Tic-Tac-Toe 🔢

🔄 Uses numbers instead of Xs and Os.

1️⃣ Player 1 plays odd numbers, 2️⃣ Player 2 plays even numbers.

🏆 Win by getting three numbers that sum to 15.

6️⃣ Misere Tic-Tac-Toe ❌⭕

❌ The objective is to avoid getting three-in-a-row.

🎭 The player who gets three in a row loses.

8️⃣ Ultimate Tic-Tac-Toe 🌎

🎲 Played on a 3x3 grid of smaller Tic-Tac-Toe boards.

🏆 Win a smaller board to claim its position on the main board.

🎯 Win by getting three smaller boards in a row.

9️⃣ SUS 🆂🆄🆂

🔳 Played on a 3x3 grid.

📝 Players place "S" or "U" to form "S-U-S" sequences.

🏆 The player who forms the most sequences wins.

🚀 How to Extend the Framework

To create a new game: 1️⃣ Inherit from the Board class to define new game rules. 2️⃣ Inherit from the Player class if custom player behavior is needed. 3️⃣ Implement a RandomPlayer for AI gameplay. 4️⃣ Integrate the new game into the main menu for selection.

🤝 Contributions

Contributions are welcome! 💡 Feel free to fork the repo, create a new branch, and submit a pull request. 🚀

📜 License

This project is open-source under the MIT License. 📝
