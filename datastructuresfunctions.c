#include "dsfunctions.h"

struct Tile;

void printArray(int a[], int len)
{
    for (int i = 0; i < len; i++)
        printf("%d ", a[i]);

    printf("\n");
}


void printTile( struct Tile *tile )
{
   printf( "Tile ID: %d\n", tile->ID);
   printf( "Tile north : %c\n", tile->N);
   printf( "Tile east : %c\n", tile->E);
   printf( "Tile south : %c\n", tile->S);
   printf( "Tile west : %c\n", tile->W);
   printf( "Tile has a temple : %c \n",tile->Temple);
   printf( "Tile has a shield : %c \n",tile->Shield);
   printf( "Tile has a crossroad : %c \n",tile->Crossroad);
}

void rotation(int r,struct Tile *tile)
{
    int x;
    x=r%4; //modulo we talked about

    for (int i=0;i<x;i++)
    {
        char temp;
        temp=tile->N;
        tile->N=tile->W;
        tile->W=tile->S;
        tile->S=tile->E;
        tile->E=temp;
    }
}

 /*void defineTile (int n,int x,int y,struct Tile *tile)
    {
        if (n==1)
        {
            tile->ID = 1;
            tile->X = x;
            tile->Y = y;
            tile->N = 'p';
            tile->E = 'p';
            tile->S = 'r';
            tile->W = 'p';
            tile->Temple = 1;


        }
        else if (n==2)
        {
            tile->ID = 2;
            tile->X = x;
            tile->Y = y;
            tile->N = 'p';
            tile->E = 'p';
            tile->S = 'p';
            tile->W = 'p';
            tile->Temple = 1;


        }
        else if (n==3)
        {
            tile->ID = 3;
            tile->X = x;
            tile->Y = y;
            tile->N = 'c';
            tile->E = 'c';
            tile->S = 'c';
            tile->W = 'c';
            tile->Temple = 0;


        }
        else if (n==4)
        {
            tile->ID = 4;
            tile->X = x;
            tile->Y = y;
            tile->N = 'r';
            tile->E = 'c';
            tile->S = 'r';
            tile->W = 'p';
            tile->Temple = 0;


        }
        else if (n==5)
        {
            tile->ID = 5;
            tile->X = x;
            tile->Y = y;
            tile->N = 'c';
            tile->E = 'p';
            tile->S = 'p';
            tile->W = 'p';
            tile->Temple = 1;


        }
        else if (n==6)
        {
            tile->ID = 6;
            tile->X = x;
            tile->Y = y;
            tile->N = 'p';
            tile->E = 'c';
            tile->S = 'p';
            tile->W = 'c';
            tile->Temple = 0;


        }
        else if (n==7)
        {
            tile->ID = 7;
            tile->X = x;
            tile->Y = y;
            tile->N = 'p';
            tile->E = 'c';
            tile->S = 'c';
            tile->W = 'p';
            tile->Temple = 0;


        }
        else if (n==8)
        {
            tile->ID = 8;
            tile->X = x;
            tile->Y = y;
            tile->N = 'c';
            tile->E = 'r';
            tile->S = 'r';
            tile->W = 'p';
            tile->Temple = 0;


        }
        else if (n==9)
        {
            tile->ID = 9;
            tile->X = x;
            tile->Y = y;
            tile->N = 'r';
            tile->E = 'c';
            tile->S = 'p';
            tile->W = 'r';
            tile->Temple = 0;


        }
        else if (n==10)
        {
            tile->ID = 10;
            tile->X = x;
            tile->Y = y;
            tile->N = 'r';
            tile->E = 'c';
            tile->S = 'r';
            tile->W = 'r';
            tile->Temple = 0;


        }
        else if (n==11)
        {
            tile->ID = 11;
            tile->X = x;
            tile->Y = y;
            tile->N = 'r';
            tile->E = 'p';
            tile->S = 'r';
            tile->W = 'p';
            tile->Temple = 0;


        }
        else if (n==12)
        {
            tile->ID = 12;
            tile->X = x;
            tile->Y = y;
            tile->N = 'p';
            tile->E = 'p';
            tile->S = 'r';
            tile->W = 'r';
            tile->Temple = 0;


        }
        else if (n==13)
        {
            tile->ID = 13;
            tile->X = x;
            tile->Y = y;
            tile->N = 'p';
            tile->E = 'r';
            tile->S = 'r';
            tile->W = 'r';
            tile->Temple = 0;


        }
        else if (n==14)
        {
            tile->ID = 14;
            tile->X = x;
            tile->Y = y;
            tile->N = 'r';
            tile->E = 'r';
            tile->S = 'r';
            tile->W = 'r';
            tile->Temple = 0;


        }

    }*/

