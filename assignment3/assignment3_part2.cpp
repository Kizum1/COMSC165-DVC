//******************************************************************
//Description: This is a very basic tic-tac-toe game. Code is similar to Professor Pentcheva's but fixed bugs that were present in her code.
//Author: Jay Chong
//COMSC 165 Section 5096
//Date February 9th, 2023
//Status: Complete
//*******************************************************************

#include <iostream>

using namespace std;

const int ROWS = 3;
const int COLS = 3;

void displayBoard(char[][COLS]);
void playerTurn(char[][COLS], char);
bool gameOver(char[][COLS]);
bool playerWins(char[][COLS], char);
bool playerCanWin(char[][COLS], char);
void displayWinner(char[][COLS]);

int main() {
  char gameBoard[ROWS][COLS] = {
    '*',
    '*',
    '*',
    '*',
    '*',
    '*',
    '*',
    '*',
    '*'
  };
  do {
    displayBoard(gameBoard);
    playerTurn(gameBoard, 'X');
    displayBoard(gameBoard);

    if (!gameOver(gameBoard))
      playerTurn(gameBoard, 'O');
  } while (!gameOver(gameBoard));
  displayBoard(gameBoard);
  displayWinner(gameBoard);
  return 0;
}

void displayBoard(char board[][COLS]) {
  cout << "      Columns\n";
  cout << "      1 2 3\n";

  for (int row = 0; row < ROWS; row++) {
    cout << "Row " << (row + 1) << ": ";
    for (int col = 0; col < COLS; col++) {
      cout << board[row][col] << " ";
    }
    cout << endl;
  }
}

void playerTurn(char board[][COLS], char symbol) {
  bool isAvailable = false;

  int row;
  int col;

  cout << "Player " << symbol << "'s turn. \n";
  cout << "Enter a row and column to place an " << symbol << ". \n";

  while (!isAvailable) {
    cout << "Row: ";
    cin >> row;

    while (row < 1 || row > ROWS) {
      cout << "Invalid Row \n";
      cout << "Row: ";
      cin >> row;
    }
    cout << "Column: ";
    cin >> col;
    while (col < 1 || col > COLS) {
      cout << "Invalid Column \n";
      cout << "Column: ";
      cin >> col;
    }

    if (board[row - 1][col - 1] == '*')
      isAvailable = true;
    else {
      cout << "Try again this location is invalid" << endl;
    }
  }
  board[row - 1][col - 1] = symbol;
}
//new section, bug fix
bool gameOver(char board[][COLS]) {
  bool status = false; // set a bool value to status
  if (playerWins(board, 'X'))
    status = true; // if player X wins then set bool as true
  else if (playerWins(board, 'O'))
    status = true; // if player O wins then set bool as true 
  else {
    int count = 0; // needed to count the number of filled squres
    for (int row = 0; row < ROWS; row++) { // loop through the rows
      for (int col = 0; col < COLS; col++) { // loop through the columns
        if (board[row][col] != '*') {
            // if the square isnt empty then add 1 to count
          count++;
        }
      }
    }
    if (count == ROWS * COLS) {
      status = true; // game over if all the squares are filled
    }
  }
  return status; // return the status to the function
}

bool playerWins(char board[][COLS], char symbol) {
  bool status = false;

  if (board[0][0] == symbol && board[0][1] == symbol && board[0][2] == symbol)
    status = true;
  if (board[1][0] == symbol && board[1][1] == symbol && board[1][2] == symbol)
    status = true;
  if (board[2][0] == symbol && board[2][1] == symbol && board[2][2] == symbol)
    status = true;
  if (board[0][0] == symbol && board[1][0] == symbol && board[2][0] == symbol)
    status = true;
  if (board[0][1] == symbol && board[1][1] == symbol && board[2][1] == symbol)
    status = true;
  if (board[0][2] == symbol && board[1][2] == symbol && board[2][2] == symbol)
    status = true;
  if (board[0][0] == symbol && board[1][1] == symbol && board[2][2] == symbol)
    status = true;
  return status;
};

bool playerCanwin(char board[][COLS], char symbol) {
  bool status = false;

  if ((board[0][0] == symbol || board[0][0] == '*') &&
    (board[0][1] == symbol || board[0][1] == '*') &&
    (board[0][2] == symbol || board[0][2] == '*'))
    status = true;
  if ((board[1][0] == symbol || board[1][0] == '*') &&
    (board[1][1] == symbol || board[1][1] == '*') &&
    (board[1][2] == symbol || board[1][2] == '*'))
    status = true;
  if ((board[2][0] == symbol || board[2][0] == '*') &&
    (board[2][1] == symbol || board[2][1] == '*') &&
    (board[2][2] == symbol || board[2][2] == '*'))
    status = true;
  if ((board[0][0] == symbol || board[0][0] == '*') &&
    (board[1][0] == symbol || board[1][0] == '*') &&
    (board[2][0] == symbol || board[2][0] == '*'))
    status = true;
  if ((board[0][0] == symbol || board[0][0] == '*') &&
    (board[1][1] == symbol || board[1][1] == '*') &&
    (board[2][1] == symbol || board[2][1] == '*'))
    status = true;
  if ((board[0][2] == symbol || board[0][0] == '*') &&
    (board[1][2] == symbol || board[1][2] == '*') &&
    (board[2][2] == symbol || board[2][2] == '*'))
    status = true;
  if ((board[0][0] == symbol || board[0][0] == '*') &&
    (board[1][1] == symbol || board[1][1] == '*') &&
    (board[2][2] == symbol || board[2][2] == '*'))
    status = true;

  return status;
}

void displayWinner(char board[][COLS]) {
  if (playerWins(board, 'X'))
    cout << "Player 1 (X) Wins" << endl;
  else if (playerWins(board, 'O'))
    cout << "Player 2 (O) Wins" << endl;
  else
    cout << "Tie game, try again" << endl;
}