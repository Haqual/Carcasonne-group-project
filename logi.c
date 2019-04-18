#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "inpu.h"
#include "outpu.h"
#include "logi.h"
# ifdef __unix__
# include <unistd.h>
# elif defined _WIN32
# include <windows.h>
# endif


int checkPlacementTile(Tile t,int x,int y,int m)
{
    int check=0;
    int l,k;
    k=(x-1)*3;
    l=(y-1)*3;

    if(Board[l][k]=='-')
    {
        check++;
    }
    if(l==0||t.N==Board[l-1][k+1]||Board[l-1][k+1]=='-')
    {
        check++;
    }
    if(k+2==29||t.E==Board[l+1][k+3]||Board[l+1][k+3]=='-')
    {
        check++;
    }
    if(l+2==29||t.S==Board[l+3][k+1]||Board[l+3][k+1]=='-')
    {
        check++;
    }
    if(k==0||t.W==Board[l+1][k-1]||Board[l+1][k-1]=='-')
    {
        check++;
    }
    if ((k==0||Board[l+1][k-1]=='-')&&(l+2==29||Board[l+3][k+1]=='-')&&(k+2==29||Board[l+1][k+3]=='-')&&(l==0||Board[l-1][k+1]=='-'))
    {
      check--;
    }
    if (m==1)
    {
        check++;
    }
    if(check==5)
    {
        return 1;
    }
    else
    {
        return 0;
    }

}

void rotation (int r,Tile *tile)
{
   int x;
   x=r%4;
    int i;
   for ( i=0;i<x;i++)
   {
	char temp;
	temp=tile->N;
	tile->N=tile->W;
	tile->W=tile->S;
	tile->S=tile->E;
	tile->E=temp;
   }


}

void placeTile(Tile t,int x,int y,int m)
{
    if(checkPlacementTile(t,x,y,m)==1)
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
        //printBoard();
      }
      else
    {
        printf("Wrong Placement\n");
    }

}

void playTile (int n,Tile *t,int x,int y,int (*a)[14],int r,int *mo)
{
        rotation(r,t);

        //printf("%d",*mo);


            if(checkPlacementTile(*t,x,y,*mo)==0)
            {
                printf("Wrong placement. Change your move.\n");
                Sleep(2000);

            }
            else if (checkPlacementTile(*t,x,y,*mo)==1)
            {
               placeTile(*t,x,y,*mo);
               (*a)[n-1]--;
               (*mo)++;
            }

}


 int checkPlacementTile2(Tile t,int x,int y,int m)
{
    int check=0;
    int l,k;
    k=(x-1)*3;
    l=(y-1)*3;

    if(Board[l][k]=='-')
    {
        check++;
    }
    if(l==0||t.N==Board[l-1][k+1]||Board[l-1][k+1]=='-')
    {
        check++;
    }
    if(k+2==29||t.E==Board[l+1][k+3]||Board[l+1][k+3]=='-')
    {
        check++;
    }
    if(l+2==29||t.S==Board[l+3][k+1]||Board[l+3][k+1]=='-')
    {
        check++;
    }
    if(k==0||t.W==Board[l+1][k-1]||Board[l+1][k-1]=='-')
    {
        check++;
    }
   /* if ((k==0||Board[l+1][k-1]=='-')&&(l+2==29||Board[l+3][k+1]=='-')&&(k+2==29||Board[l+1][k+3]=='-')&&(l==0||Board[l-1][k+1]=='-'))
    {
      check--;
    }
    if (m==1)
    {
      check++;
    }*/
    if(check==5)
    {
        return 1;
    }
    else
    {
        return 0;
    }

}


void placeTile2(Tile t,int x,int y,int m)
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
      }
      else
    {
        printf("Wrong Placement\n");
    }

}
