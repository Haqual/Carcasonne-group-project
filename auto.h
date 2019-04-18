#ifndef AUTO_FILE
#define AUTO_FILE
#include "logi.h"
#include "inpu.h"
#include "outpu.h"


int *data;
int arrsize;
int autoCheckEmptyTile(int x,int y);
int autoTileOpen(Tile *t,int x,int y,int r,int *mo);
void autoAddCoordinate(int x);
int autoSearchCoor(int x);
void autoPlaceTile(Tile t,int x,int y,int m);
void autoFinalPlaceTile(Tile *t,int x,int y,int r,int *mo);



#endif // AUTO_FILE
