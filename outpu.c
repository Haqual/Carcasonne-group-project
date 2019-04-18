#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "outpu.h"
#include "inpu.h"

void clearBoard()
{
    int i,j;
    for(i=0;i<30;i++)
    {
        for(j=0;j<30;j++)
        {
            Board[i][j]='-';
        }
    }
}

void setBoard(char **x)
{
    int i;
    //x = malloc(30 * sizeof(char*));
    for (i=0;i<30;i++)
    {
        x[i]=malloc(30);
    }
}

void printBoard()
{
    printf("\n");
    int i,j;
    for(i=0;i<30;i++)
    {
        for(j=0;j<30;j++)
        {
            if(j%3==2)
            {
                printf("%c   ",Board[i][j]);
            }
            else
            {
                printf("%c ",Board[i][j]);
            }

        }
        if(i%3==2)
        {
            printf("\n");
        }
        printf("\n");
    }
}

void printtofileBoard()
{

    FILE *f;
    f=fopen("Board.txt","w");
    int i,j;
    for(i=0;i<30;i++)
    {
        for(j=0;j<30;j++)
        {
            //Board[i][j]='-';
            /*if(j%3==2)
            {
                fprintf(f,"%c   ",Board[i][j]);
            }
            else
            {*/
                fprintf(f,"%c",Board[i][j]);
            //}

        }
       // if(i%3==2)
        //{
          //  fprintf(f,"\n");
        //}
        fprintf(f,"\n");
    }
}


void showDeck(Tile t[14],int a[14])
{

    printf("\nYOUR TILES:\n\n");

    int i;
    for(i=0;i<7;i++)
    {
        printf("    %c  ",t[i].N);
    }
    printf("\n");
    for(i=0;i<7;i++)
    {
           if(t[i].Temple=='T')
        {
          printf("%d: %cT%c ",i+1,t[i].W,t[i].E);
        }
        else if(t[i].Crossroad=='T')
        {
          printf("%d: %cC%c ",i+1,t[i].W,t[i].E);
        }
        else if(t[i].Shield=='T')
        {
          printf("%d: %cS%c ",i+1,t[i].W,t[i].E);
        }
        else
        {
          printf("%d: %c %c ",i+1,t[i].W,t[i].E);
        }

        //printf("%d: %c %c ",i+1,t[i].W,t[i].W);
    }
    printf("\n");
    for(i=0;i<7;i++)
    {
        printf("    %c  ",t[i].S);
    }
    printf("\n");
    printf("\n");
    for(i=0;i<7;i++)
    {
        printf("    %d  ",a[i]);
    }
    printf("\n");
    printf("\n");


    for(i=7;i<14;i++)
    {
        //if (i<10)
        printf("    %c  ",t[i].N);
        //else
       // printf("     %c  ",t[i].N);
    }
    printf("\n");
    for(i=7;i<14;i++)
    {
        if (i<9)
            printf("%d: %c %c ",i+1,t[i].W,t[i].E);
        else
        {

               if(t[i].Temple=='T')
            {
              printf("%d:%cT%c ",i+1,t[i].W,t[i].E);
            }
            else if(t[i].Crossroad=='T')
            {
              printf("%d:%cC%c ",i+1,t[i].W,t[i].E);
            }
            else if(t[i].Shield=='T')
            {
              printf("%d:%cS%c ",i+1,t[i].W,t[i].E);
            }
            else
            {
              printf("%d:%c %c ",i+1,t[i].W,t[i].E);
            }


        }
        //printf("%d:%c %c ",i+1,t[i].W,t[i].W);
    }
    printf("\n");
    for(i=7;i<14;i++)
    {
        //if (i<10)
        printf("    %c  ",t[i].S);
        //else
        //printf("     %c  ",t[i].S);


    }
    printf("\n");
    printf("\n");
    for(i=7;i<14;i++)
    {
        //if (i<10)
        printf("    %d  ",a[i]);
        //else
        //printf("     %d  ",a[i]);
    }
    printf("\n");
    printf("\n");
}

void showTile(Tile t)
{
    printf(" %c \n",t.N);
    if(t.Temple=='T')
    {
      printf("%c%c%c\n",t.W,t.Temple,t.E);
    }
    else if(t.Crossroad=='T')
    {
      printf("%cC%c\n",t.W,t.E);
    }
    else if(t.Shield=='T')
    {
      printf("%cS%c\n",t.W,t.E);
    }
    else
    {
      printf("%c %c\n",t.W,t.E);
    }
    printf(" %c \n",t.S);
}


