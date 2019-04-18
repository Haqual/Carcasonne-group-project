#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "outpu.h"
#include "inpu.h"
#include "logi.h"
#include "auto.h"


int autoCheckEmptyTile(int x,int y)
{
    int l,k;
    k=(x-1)*3;
    l=(y-1)*3;

    if(Board[l][k]=='-')
    {
        return 0;
    }
    else
        return 1;

}


int autoTileOpen(Tile *t,int x,int y,int r,int *mo)
{
    int get,i;
    rotation(r,t);
    for(i=0;i<4;i++)
    {
       if(checkPlacementTile2(*t,x,y,*mo)==0)
       {
           r++;
          // printf("HERE");
       }
       else
       {

           placeTile(*t,x,y,*mo);
       }
    }
    if(autoCheckEmptyTile(x,y)==0)
    {
      //  printf("hiiiiiii");
        return 0;

    }
    else
    {
        return 1;
    }


}
void autoAddCoordinate(int x)
{
    int row,col,i;
    row=x/10;
    col=x%10;

    if((row-1==-1&&col-1==-1)||(row-1==-1&&col+1==10)||(row+1==10&&col+1==10)||(row+1==10&&col-1==-1))
    {

        if(row-1==-1&&col-1==-1)
        {
                autoSearchCoor((row*10+(col+1)));
               // autoSearchCoor((row+1)*10+(col+1));
                autoSearchCoor((row+1)*10+(col));
        }
        if(row-1==-1&&col+1==10)
        {
                autoSearchCoor(row*10+(col-1));
                autoSearchCoor((row+1)*10+(col));
                //autoSearchCoor((row+1)*10+(col-1));
        }
        if(row+1==10&&col+1==10)
        {
                //autoSearchCoor((row-1)*10+(col-1));
                autoSearchCoor((row-1)*10+(col));
                autoSearchCoor((row)*10+(col-1));
        }
        if(row+1==10&&col-1==-1)
        {
                autoSearchCoor((row-1)*10+(col));
               // autoSearchCoor((row-1)*10+(col+1));
                autoSearchCoor((row)*10+(col+1));
        }

    }
    else if(row-1==-1)
    {
        autoSearchCoor(row*10+(col-1));
        //printf("HELLO_WORLD");
        autoSearchCoor(row*10+(col+1));
       // autoSearchCoor((row+1)*10+(col-1));
        autoSearchCoor((row+1)*10+col);
       // autoSearchCoor((row+1)*10+(col+1));


    }
    else if(col-1==-1)
    {
        autoSearchCoor((row-1)*10+(col));
       // printf("\t%d\t",row);
        autoSearchCoor((row+1)*10+(col));
       // autoSearchCoor((row-1)*10+(col+1));
        autoSearchCoor((row)*10+(col+1));
       // autoSearchCoor((row+1)*10+(col+1));
    }
    else if(row+1==10)
    {
        autoSearchCoor((row)*10+(col-1));
        autoSearchCoor((row)*10+(col+1));
       // printf("HELLO");
       // autoSearchCoor((row-1)*10+(col-1));
        autoSearchCoor((row-1)*10+(col));
       // autoSearchCoor((row-1)*10+(col+1));
    }
    else if(col+1==10)
    {
        autoSearchCoor((row-1)*10+(col));
        //printf("YAHOO");
        autoSearchCoor((row+1)*10+(col));
       // autoSearchCoor((row-1)*10+(col-1));
        autoSearchCoor((row)*10+(col-1));
       // autoSearchCoor((row+1)*10+(col-1));
    }
    else
    {

        //autoSearchCoor((row-1)*10+(col-1));
        autoSearchCoor((row-1)*10+(col));
        //autoSearchCoor((row-1)*10+(col+1));
        autoSearchCoor((row)*10+(col-1));
        autoSearchCoor((row)*10+(col+1));
        //autoSearchCoor((row+1)*10+(col-1));
        autoSearchCoor((row+1)*10+(col));
        //autoSearchCoor((row+1)*10+(col+1));


    }



}

int autoSearchCoor(int x)
{
    int i;
    for(i=0;i<arrsize;i++)
    {
        if(data[i]==x)
        {
            return 0;
        }
    }
    if(i==arrsize)
    {
        arrsize=arrsize+1;
        realloc(data,arrsize* sizeof *data);
        data[arrsize-1]=x;
        return 1;
    }

}
void autoPlaceTile(Tile t,int x,int y,int m)
{
      if(checkPlacementTile2(t,x,y,m)==1)
      {
        int k,l;
        k=(x-1)*3;
        l=(y-1)*3;

        Board[l][k+1]=t.N;
        Board[l+2][k+1]=t.S;
        Board[l+1][k]=t.W;
        Board[l+1][k+2]=t.E;
        Board[l][k]='\0';
        Board[l][k+2]='\0';
        Board[l+2][k]='\0';
        Board[l+2][k+2]='\0';

         if(t.Temple=='T')
        {
          Board[l+1][k+1]=t.Temple;
        }
        else if(t.Crossroad=='T')
        {
          Board[l+1][k+1]='C';
        }
        else if(t.Shield=='T')
        {
          Board[l+1][k+1]='S';
        }
        else
        {
            Board[l+1][k+1]='\0';
        }
        //printBoard();
        //return 1;
      }
     // else
      //{
      //  return 0;
     // }

}
void autoFinalPlaceTile(Tile *t,int x,int y,int r,int *mo)
{
    rotation(r,t);
    int i;
    for(i=0;i<4;i++)
    {
        if(checkPlacementTile2(*t,x,y,*mo)==1)
        {
           // printf("HELLO");
            placeTile2(*t,x,y,*mo);
            autoAddCoordinate((x*10)+y);
            break;
        }
        else
        {

            r++;
        }
    }
}
