/*
Aparajita Baidya
10.10.2025
Tic-Tac-Toe
Create a 3x3 grid (letters and nums) --- 2d array
User enters move
Check if move is legal
Enter if move is legal, if not, ask again
check if win or tie --> tell users
Reset board, inform players of currents wins and ties
ask if replay(?) -- redraw board
*/

#include <iostream>

using namespace std;

//declare functions


//main
//while gameon == true, run game
//when board full, end game, ask if play again, if 'n', gameon == false
//make sure to get the user input properly 
//reset board at top 
int main()
{
  char gameon = 'y'; //this is obvious
  char board[4][4] = {{' ', '1', '2', '3'},{'a', ' ',' ',' '},{'b',' ',' ',' '},{'c',' ',' ',' '}}; //initial board
  int turn = 0; //whose turn
  /*
  for(int a = 0; a<4; a++)
  {
    for(int b = 0; b < 4; b++)
    {
      cout << board[a][b] << " ";
    }
    cout << endl;
  } wanted to test out printing, may use this soon*/
  while(gameon == 'y')
    {
      cout << 'a'<< endl;
      cout << "do you want to play again? y/n" << endl;
      cin >> gameon;//need to figure out how to get only first char from input
    }
  cout << "farewell";
}

//check move legality --> return bool   


//check board state --> return char --> if board filled: 'x', 'o', 'n'


//score keeper --> return char array --> ['x',':','#',' ','o',':','#',' ','t','i','e',':','#']
