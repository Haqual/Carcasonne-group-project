#ifndef OUTPU_FILE
#define OUTPU_FILE
#include "inpu.h"

char **Board;//the board

void clearBoard();
//assign every place of an array with an '-'
void printBoard();
//prints the board
void printtofileBoard();
//prints the board into the file
void setBoard(char** x);
//sets the board
void showDeck(Tile t[14],int a[14]);
//shows the deck of tiles and number of each tile type
void showTile(Tile t);
//showing the tile in board way

#endif // OUTPU_FILE
