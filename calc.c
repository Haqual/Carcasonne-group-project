#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "inpu.h"
#include "outpu.h"
#include "logi.h"
#include "calc.h"
# ifdef __unix__
# include <unistd.h>
# elif defined _WIN32
# include <windows.h>
# endif

int countCities()
{
    int points;
    points=0;
    int i,j;
    for (i=0;i<30;i++)
    {
        for (j=0;j<30;j++)
        {
            if (i%3==1&&j%3==1)
                continue;
            if (Board[i][j]=='C')
            {

                if (countSinCity(i,j)>0)
                {

                    //printf("%d %d\n",i,j);
                    points=points+countSinCity(i,j);
                    //printf("%d\n",points);
                    removeSinCity(i,j);
                    //printBoard();

                }
            }
        }
    }
    //readBoard(30);
    return points;
}

void removeSinCity(int a,int b)
{
    if (a%3==0)
    {
       if (Board[a-1][b]=='C'&&Board[a-2][b]!='S')
           {
               Board[a-1][b]='-';
               Board[a][b]='-';
               return 0;
           }
       else if(Board[a-1][b]!='C')
            {
               return 0;
           }
       else if (Board[a-1][b]=='C'&&Board[a-2][b]=='S')
       {
          Board[a][b]='-';
          Board[a-1][b]='-';
          removeSinCity(a-3,b);
          removeSinCity(a-2,b-1);
          removeSinCity(a-2,b+1);
       }

    }
    else if (a%3==1)
    {
        if (b%3==0)
        {
            if (Board[a][b-1]=='C'&&Board[a][b-2]!='S')
               {
                   Board[a][b]='-';
                    Board[a][b-1]='-';
                   return 0;
               }
            else if(Board[a][b-1]!='C')
                {

                   return 0;
               }
            else if (Board[a][b-1]=='C'&&Board[a][b-2]=='S')
               {
                   Board[a][b]='-';
                   Board[a][b-1]='-';
                  removeSinCity(a,b-3);
                  removeSinCity(a-1,b-2);
                  removeSinCity(a+1,b-1);
               }
        }
        else if (b%3==2)
        {
            if (Board[a][b+1]=='C'&&Board[a][b+2]!='S')
               {
                   Board[a][b]='-';
                   Board[a][b+1]='-';
                   return 0;
               }
            else if(Board[a][b+1]!='C')
                {
                   return 0;
               }
            else if (Board[a][b+1]=='C'&&Board[a][b+2]=='S')
               {
                  Board[a][b]='-';
                  Board[a][b+1]='-';
                  removeSinCity(a,b+3);
                  removeSinCity(a+1,b+2);
                  removeSinCity(a-1,b+2);
               }
        }
    }
    else if (a%3==2)
    {
        if (Board[a+1][b]=='C'&&Board[a+2][b]!='S')
           {
               Board[a][b]='-';
               Board[a+1][b]='-';
               return 0;
           }
       else if(Board[a+1][b]!='C')
            {
               return 0;
           }
       else if (Board[a+1][b]=='C'&&Board[a+2][b]=='S')
           {
              Board[a][b]='-';
              Board[a+1][b]='-';
              removeSinCity(a+3,b);
              removeSinCity(a+2,b-1);
              removeSinCity(a+2,b+1);
           }
    }
}

int countSinCity(int a,int b)
{
    if (a%3==0)
    {
       if (Board[a-1][b]=='C'&&Board[a-2][b]!='S')
               return 2;
       else if(Board[a-1][b]!='C')
            return -100;
       else if (Board[a-1][b]=='C'&&Board[a-2][b]=='S')
          return (countSinCity(a-3,b)+countSinCity(a-2,b-1)+countSinCity(a-2,b+1)-2);


    }
    else if (a%3==1)
    {
        if (b%3==0)
        {
            if (Board[a][b-1]=='C'&&Board[a][b-2]!='S')
                   return 2;
            else if(Board[a][b-1]!='C')
                return -100;
            else if (Board[a][b-1]=='C'&&Board[a][b-2]=='S')
                  return (countSinCity(a,b-3)+countSinCity(a-1,b-2)+countSinCity(a+1,b-1)-1);
        }
        else if (b%3==2)
        {
            if (Board[a][b+1]=='C'&&Board[a][b+2]!='S')
               {
                   //Board[a][b]='-';
                   //Board[a][b+1]='-';
                   return 2;
               }
            else if(Board[a][b+1]!='C')
                return -100;
            else if (Board[a][b+1]=='C'&&Board[a][b+2]=='S')
               {
                  //Board[a][b]='-';
                  return (countSinCity(a,b+3)+countSinCity(a+1,b+2)+countSinCity(a-1,b+2)-1);
               }
        }
    }
    else if (a%3==2)
    {
        if (Board[a+1][b]=='C'&&Board[a+2][b]!='S')
           {

               return 2;
           }
       else if(Board[a+1][b]!='C')
            return -100;
       else if (Board[a+1][b]=='C'&&Board[a+2][b]=='S')
           {

              return (countSinCity(a+3,b)+countSinCity(a+2,b-1)+countSinCity(a+2,b+1)-1);
           }
    }
}

/*void searchCross(int *y,int *x)
{
    int i,j;
    for (i=0;i<30;i++)
    {
        for (j=0;j<30;j++)
        {
            if (Board[i][j]=='C'||Board[i][j]=='T')
                x[];
        }
    }
}*/

 int countMinPoints()
 {
     int size=30;
     int sum=0;
     int k,l;
     int i,j;
     for (i=0;i<10;i++)
     {
         l=i*3;
         for (j=0;j<10;j++)
         {
             k=j*3;
             if (Board[k][l]=='-')
                continue;
             else
             {
                 sum=sum+countMinTile(k, l);
             }

         }
     }
     return sum;
 }

 int countMinTile(int a, int b)
 {
     char side='a';
     int points=0;
     int i;
     int ad1=0;
     int ad2=0;
    if (Board[a][b]=='-')
        return 0;
    if (Board[a+1][b+1]=='-'||Board[a+1][b+1]=='S')
    {

            if (Board[a][b+1]!=side&&Board[a][b+1]!='P')
            {
               side=Board[a][b+1];
               points++;
            }

             if (Board[a+1][b+2]!=side&&Board[a+1][b+2]!='P')
            {
               side=Board[a+1][b+2];
               points++;
            }
            if (Board[a+2][b+1]!=side&&Board[a+2][b+1]!='P')
            {
               side=Board[a+2][b+1];
               points++;
            }

             if (Board[a+1][b]!=side&&Board[a+1][b]!='P')
            {
               side=Board[a+1][b];
               points++;
            }
            if(side=='C')
            {
                points++;
            }


    }
    else
    {

            if (Board[a][b+1]!='P')
            {
               points++;
            }

             if (Board[a+1][b+2]!='P')
            {
               points++;
            }
            if (Board[a+2][b=1]!='P')
            {
               points++;
            }

            if (Board[a+1][b]!='P')
            {
               points++;
            }
            if(Board[a+1][b+1]=='T')
            {
                points++;
            }

    }
    return points;
 }

 int countPoints()
 {
     int points;

     points=countMinPoints()+countCities();

 }
