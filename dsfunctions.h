#ifndef DISFUNCTION_H
#define DISFUNCTION_H

struct Tile
    {
        int ID;
        char N;
        char E;
        char S;
        char W;
        char Temple;
        char Shield;
        char Crossroad;
    };

void printTile (struct Tile *tile );

void rotation(int r,struct Tile *tile);

void printArray(int a[], int len);

//void defineTile (int n,int x,int y,struct Tile *tile);

#endif





