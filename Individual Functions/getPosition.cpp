// Program snippet for the getPosition() function
// We had originally planned to add this in in the main game (check pseudocode.cpp), but in the end our final function did not utilize this function
// By Ellen F.

#include <iostream>
using namespace std;

// Function Declaration:
string getPosition();

string getPosition(){

//determine mini boards A,B,C,D,E,F,G,H,I
  int pos;

  int board_num = pos%9;

  char board;

  switch(board_num){
    case 1:
      board = 'A';
    case 2:
      board = 'B';
    case 3:
      board = 'C';
    case 4:
      board = 'D';
    case 5:
      board = 'E';
    case 6:
      board = 'F';
    case 7:
      board = 'G';
    case 8:
      board = 'H';
    case 9:
      board = 'I';
  }

  //if board is full, return -1; use function winCheck()
  cout<<"enter a position";

  cin<<pos;

  if(winCheck(board_num)== "X" || "O"){
    return "Board already occupied. Try again.";
  }
  else{
    return board + pos;
  }
}
