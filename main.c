#include <stdio.h>
#include <stdlib.h>

void rotation (int r,char *N,char *E,char *S,char *W);

int main()
{

    int rotate;
    char City,Plain,Road;

    char North = 'c';
    char East = 'p';
    char South = 'r';
    char West = 'r';
    //normal char variables

    printf("North : %c \n" "East : %c \n" "South : %c \n" "West : %c \n",North,East,South,West);

    scanf("%d", &rotate);

    rotation(rotate,&North,&East,&South,&West);
    //I use the function declared at the beginning, giving it the addresses of the variables

    printf("North : %c \n" "East : %c \n" "South : %c \n" "West : %c \n",North,East,South,West);
    //I print the variables value after the void function


    return 0;

}

void rotation(int r,char *N,char *E,char *S, char *W)
{
    int x;
    x=r%4; //modulo we talked about

    for (int i=0;i<x;i++)
    {
        char temp;
        temp=*N;
        *N=*W;
        *W=*S;
        *S=*E;
        *E=temp;
    }
    //the loop changing the variables value
}


