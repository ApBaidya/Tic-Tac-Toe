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
int moveCheck(char b[4][4], char r, char c, char p); //check if move legal, ig yes, update board, if no, ask again
char boardState(char b[4][4], char p); //check if win or tie after turn

//main
//while gameon == true, run game
//when board full, end game, ask if play again, if 'n', gameon == false
//make sure to get the user input properly 
//reset board at top 
int main()
{
  char playing = 'y'; //playing game note to self, ct space then alt w to select, ct y to paste, tab to correct indent ct k to del line
  char board[4][4] = {{' ', '1', '2', '3'},{'a', ' ',' ',' '},{'b',' ',' ',' '},{'c',' ',' ',' '}}; //initial board
  int turn = 0;//0 = x 1 = o 
  char row = 'a';
  char col = '1';
  int legal = 0;//1 move is legal, 0 if it isn't
  char player = 'x';
  char gamestate = 'c'; //c for continue
  char gameon = 'y';
  int xwin = 0;
  int owin = 0;
  int tie = 0;
  while(playing == 'y')
  {
    // reset board. could write a for loop, but no. 
    board[0][0] = ' ';
    board[0][1] = '1';
    board[0][2] = '2';
    board[0][3] = '3';
    board[1][0] = 'a';
    board[2][0] = 'b';
    board[3][0] = 'c';
    for(int i = 1; i < 4; i++)//caved and wrote a for loop
    {
      for(int j = 1; j < 4; j++)
      {
	board[i][j] = ' ';
      }
    }
    for(int a = 0; a<4; a++)//show off the base board
      {
	for(int b = 0; b < 4; b++)
	  {
	    cout << board[a][b] << " ";
	  }
	cout << endl;
      }
    //what needs to reset each game
    turn = 0; //could be cool to randomize this someday 
    row = 'a';
    col = '1';
    legal = 0;
    player = 'x';
    gamestate = 'c';
    gameon = 'y';
    while(gameon == 'y')//while the board is not full
      {
	//check who is playing
	if(turn == 0)
	{
	  player = 'x';
	  turn = 1;
	}
	else
	{
	  player = 'o';
	  turn = 0;
	}
	//get move section
	cout << "it is " << player << "'s turn" << endl;
	cout << "what is your move?" << endl;
	cout << "please enter the row" << endl;
	cin >> row;
	cin.ignore(10,'\n');//no one is crazy enough to enter more than 10 chars...hopefully
	cout << endl;
	cout << "now enter the column" << endl;
	cin >> col;
	cin.ignore(10, '\n');
	//move legality + update board section
	legal = moveCheck(board, row, col, player);//check if move is legal
	while(legal == 0) //legal == false
	  {
	    cout << "dude that doesn't exit. try again."<<endl;
	    cout << "row?" << endl;
	    cin >> row;
	    cin.ignore(10, '\n');
	    cout << endl;
	    cout << "colum?"<<endl;
	    cin >> col;
	    cin.ignore(10, '\n');
	    cout << endl;
	    legal = moveCheck(board, row, col, player);
	  }
	//print new board
	for(int a = 0; a<4; a++)
	  {
	    for(int b = 0; b < 4; b++)
	      {
		cout << board[a][b] << " ";
	      }
	    cout << endl;
	  }
	//check if round is over or not
	gamestate = boardState(board, player);
	//cout << gamestate << endl;
	if(gamestate != 'c')
	{
	  gameon = 'n';
	}
	if(gamestate == 'x')
	{
	  xwin ++;
	}
	else if(gamestate == 'o')
	{
	  owin ++;
	}
	else if(gamestate == 't')
	{
	  tie ++;
	} 
      }
    if(gamestate == 't')
    {
      cout << "The round has ended in a tie." << endl;
    }
    else
    {
      cout << player << " has won" << endl;
    }
    cout << "These are the current scores:" << endl;
    cout << "x:" << xwin << endl;
    cout << "o:" << owin << endl;
    cout << "ties:" << tie << endl;
    cout << "do you want to play again? y/n" << endl;
    cin >> playing;
    cin.ignore(10,'\n');//no one would enter a really long input...right?
  }
  cout << "Farewell" << endl;
}

//check move legality --> return bool   
int moveCheck(char b[4][4], char r, char c, char p)//board, row, col
{
  int check = 0;
  int ind1 = 0;
  int ind2 = 0;
  for(int i = 0; i < 4; i++)
  {
    if(b[0][i] == c)
      {
	check ++;
	ind1 = i;
      }
    if(b[i][0] == r)
    {
      check ++;
      ind2 = i;
    }
  }
  if(check == 2 && b[ind2][ind1] == ' ') //is move in box and legal 
  {
    b[ind2][ind1] = p;
    return 1;
  }
  return 0;
}

//check board state --> return char --> if board filled: 'x', 'o', 't' for tie --> if board still has empty spots: 'c' for continue

char boardState(char b[4][4], char p) //board, player
{
  
  int counter = 0;
  //check if win by checking if there is a set of three: if statement hell?
  for(int i = 1; i < 4; i++)
  {
    if(b[i][1] == b[i][2] && b[i][1] == b[i][3] && b[i][1] != ' ')//look through each spot in a row
    {
      return p;
    }
    //vert
    if(b[1][i] == b[2][i] && b[1][i] == b[3][i] && b[1][i] != ' ')//look through each 
    {
      return p;
    }
  }	
  //diagonal
  if(b[1][1] == b[2][2] && b[1][1] == b[3][3] && b[1][1] != ' ')
  {
    return p;
  }
  if(b[1][3] == b[2][2] && b[1][3] == b[3][1] && b[1][3] != ' ')
  {
    return p;
  }
  //if no winner: tie check
  for(int i = 0; i < 4; i++)
  {
    for(int j = 0; j < 4; j++)
    {
      if(b[i][j] == ' ')
      {
	counter ++;
      }
    }
  }
  if(counter>1)//still empty space?
  {
    return 'c';
  }
  else
  {
    return 't';
  }
}
