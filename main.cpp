
#include <iostream>
#include <string>
#include <ctime>

#include "util.h"
//
using namespace std;
// 
#define height 6
#define width 7


int main() {
int counter = 0;
//this varible determines wiether of not the game is over
bool Won = false;
// if single or multi player
int pt = 1;
//coordinates 
int lastMoveX, lastMoveY;
//count for game 
int count = 0;

//create board
int board[height][width] = {{0,0,0,0,0,0,0},
                            {0,0,0,0,0,0,0},
                            {0,0,0,0,0,0,0},
                            {0,0,0,0,0,0,0},
                            {0,0,0,0,0,0,0},
                            {0,0,0,0,0,0,0}};

  pt = choosePlayer();

  cout << "Player " << pt << " gets to go first." << endl; 

  cout << "----------------------" << endl;
  printBoard(board);
  cout << "----------------------" << endl;
  cout << "| 1| 2| 3| 4| 5| 6| 7|" << endl;


while(!Won){
  //Current Chip/Column
  int cc;

  //Player Input
  cout << "Player" << pt << " pick a column between 1-7:";
  cin >> cc;

  while((cc < 1) | (cc > 7)){
    cout << "Please re-enter a valid value:";
    cin >> cc;
  }
  //these values are used in the ifWon Method
  lastMoveX = cc - 1;
  
  for(int i = height - 1; i >= 0; i--){
    if(board[i][lastMoveX] == 0){
      lastMoveY = i;
      break;
    }
  }
//place's the value in the array
  placeChip(cc,pt,board);
//this makes the board
  cout << "----------------------" << endl;
  printBoard(board);
  cout << "----------------------" << endl;
  cout << "| 1| 2| 3| 4| 5| 6| 7|" << endl;
 
 
  
  // tests if the either current player won with their move
  Won = ifWon(lastMoveX, lastMoveY, pt, board);
  
  
//checks to see if the player made a winning move
  if(Won){
    cout << "Congratulations, Player " << pt << " has won the game!" << endl;
    break;
  }
// if the game is full
  if (count >= 56){
    cout << "Sorry the game was a draw";
    break;
  }
// switchs player turn
  switchTurn(pt);
  
}


 return 0;
}