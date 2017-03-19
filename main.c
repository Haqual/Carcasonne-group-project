#include <stdio.h>
#include <stdlib.h>

void rotation (int r,char *N,char *E,char *S,char *W);

int main()
{

    int rotate;
    char City,Plain,Road;
    City = 'c';
    Plain = 'p';
    Road = 'r';

    char *North = &City;
    char *East = &Plain;
    char *South = &Road;
    char *West = &Road;

    printf("North : %c \n" "East : %c \n" "South : %c \n" "West : %c \n",*North,*East,*South,*West);

    scanf("%d", &rotate);

    rotation(rotate,North,East,South,West);

    printf("North : %c \n" "East : %c \n" "South : %c \n" "West : %c \n",*North,*East,*South,*West);


    return 0;

}

void rotation(int r,char *N,char *E,char *S, char *W)
{
    int x;
    x=r%4;

    for (int i=0;i<x;i++)
    {
        char *temp;
        temp= N;
        printf("%c\n", *temp);

        N=W;
        printf("%c\n", *N);
        W=S;
        printf("%c\n", *E);
        S=E;
        printf("%c\n", *S);
        E=temp;
        printf("%c\n", *W);
    }

    printf("North : %c \n" "East : %c \n" "South : %c \n" "West : %c \n",*N,*E,*S,*W);
}


