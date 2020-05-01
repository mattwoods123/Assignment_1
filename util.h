#include <iostream>
#include <string>
#include <ctime>

using namespace std;

#define height 6
#define width 7

int choosePlayer();

void switchTurn(int &pt);

void printBoard(int table[height][width]);

void placeChip(int colm, int turn, int board[height][width]);

bool ifWon(int x, int y, int player, int board[height][width]);

bool checkVer(int x, int y, int player, int board[height][width]);

bool checkHor(int x, int y, int player, int board[height][width]);

bool checkDRight(int x, int y, int player, int board[height][width]);

bool checkDLeft(int x, int y, int player, int board[height][width]);







