#ifndef LOGI_FILE
#define LOGI_FILE
#include "inpu.h"
#include "outpu.h"

void playTile (int n,Tile *t,int x,int y,int (*a)[14],int r,int *mo);
//plays the tile
// 1. rotation 2. check placement
//3. a. if correct placement - places the tile and changes the move number
//   b. if wrong placement - informs a player about the wrong movement
int checkPlacementTile(Tile t,int x,int y,int m);
//checks if placement is right and returns either 1 or 0
void rotation (int r,Tile *tile);
//rotates the given tile r%4 times
void placeTile(Tile t,int x,int y,int m);
//places the tile on place [y,x]
int checkPlacementTile2(Tile t,int x,int y,int m);

void placeTile2(Tile t,int x,int y,int m);

#endif
