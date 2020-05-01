
#include <iostream>
#include <string>
#include <ctime>

#include "util.h"

using namespace std;

#define height 6
#define width 7
#define numOfPlayer 2
// randomly chooses Player
int choosePlayer(){
  int num;

  unsigned seed = time(0);
  srand(seed);
  num = rand() % numOfPlayer + 1;

  return num;
}
// randomly chooses Player
void switchTurn(int &pt){
  if(pt == 1){
    pt = 2;
  }else{
    pt = 1;
  }
}

// This logic Places The Chips for the player
void placeChip(int colm, int turn, int board[height][width]){
int i = height - 1;
  while(board[i][colm-1] != 0){
    i -= 1;
    if(i < 0){
      cout << "This column is FULL, sorry you lose your turn" << endl;
      break;
      
    }
  }
if(board[i][colm-1] == 0){
  board[i][colm-1] = turn;
}

}
// Shows the board to player
void printBoard(int table[height][width]){
 
  for(int i = 0; i < 6; i++){
   for(int x = 0; x < 7; x++){
      string chip;
      if(table[i][x] == 0) chip = " ";
      else if(table[i][x] == 1) chip = "X";
      else if(table[i][x] == 2) chip = "O";

     cout << "|" << chip << "|";
   }
   cout << "\n";
  }
}

bool checkVer(int x, int y, int player, int board[height][width]){

   int tally = 1;
   int pos = 1;
   
   while((y+pos < height) && (y+pos >= 0)){
      if (board[y+pos][x] == player){
         tally++;
         pos++;
      }else{
        break;
      }
   }
   if (tally == 4){ 
     return true;
   }else {
     return false;
   } 
}

bool checkHor(int x, int y, int player, int board[height][width]){

  int tally = 1;
  int pos = 1;
   
   while((x+pos >= 0) && (x+pos < width))
   {
      if (board[y][x+pos] == player) 
      {
         tally++;
         pos++;

      }else{
        break; 
      }  
   }

   pos = 1;
   while((x-pos < width) && (x-pos >=0))
   {
      if (board[y][x-pos] == player)  
      {
         tally++;
         pos++;
      } else {
        break; 
      }  
   }
   
   if (tally == 4){
     return true;
   } else{
     return false;
   } 
   
}

bool checkDRight(int x, int y, int player, int board[height][width]){

int tally = 1;
int pos = 1;

  while((y-pos >= 0) && (x+pos < width))
   {
   
      if (board[y-pos][x+pos] == player){
         tally++;
         pos++;
      } else {
        break;
      }  
   }
  pos = 1;
   while((y+pos < height) && (x-pos >= 0))
   {
     
      if (board[y+pos][x-pos] == player){
         tally++;
         pos++;
      } else {
        break;
      }
   }

   if (tally == 4){
     return true;
   } else {
     return false;
   }

}

bool checkDLeft(int x, int y, int player, int board[height][width]){

   int tally = 1;
   int pos = 1;
   
   while((y+pos >= 0) && (x+pos < width))
   {
      if (board[y+pos][x+pos] == player){
         tally++;
         pos++;
      } else {
        break; 
      }
   }
   pos = 1;
   while((y-pos < height) && (x-pos >=0))
   {

      if (board[y-pos][x-pos] == player){
         tally++;
         pos++;
      } else {
        break;
      }
   }
   
   if (tally == 4){
     return true;
   } else {
     return false;
   }

}
// This compiles all the functions to test if the player won
bool ifWon(int x, int y, int player, int board[height][width]){

  if(checkVer(x,y,player,board)){ 
    return true;
  } else if(checkHor(x,y,player,board)) {
    return true;
  }else if(checkDRight(x,y,player,board)) {
    return true;
  }else if(checkDLeft(x,y,player,board)) {
    return true;
  } else {
    return false;
  }

}

