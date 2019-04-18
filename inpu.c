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




void getLibrary(int n,Tile (*t))
{

	FILE *f;
	f=fopen("Library.txt","r");

	char str[8];

	int i;

	for ( i=0;i<42;i++)
	{
		int k;
		k=i/3;
		fgets(str,8,(FILE*)f);
		//printf("%d: %s\n",i,str);

		if (n==k)
		{
			//printf("%d: %s\n",i,str);
			stringtoStruct(n+1,str,t);
			//printTile(t);
			break;
		}
	}


}


void stringtoStruct (int n,char s[],Tile *tile)
{
   tile->ID=n;
   tile->N=s[0];
   tile->E=s[1];
   tile->S=s[2];
   tile->W=s[3];
   tile->Temple=s[4];
   tile->Shield=s[5];
   tile->Crossroad=s[6];
}


void getTiles (int (*a)[14])
{
	FILE *f;
	f=fopen("Tiles.txt","r");

	//char str[28];
    int i;
	for (i=0;i<14;i++)
    {
        int c;
        fscanf(f,"%d ",&c);
        (*a)[i]=c;
        //printf("%d ",(*a)[i]);
    }
	//fscanf(f,"%d ",a[k]);


	/*fgets(str,30,(FILE*)f);

	int i;
	for (i=0;i<28;i++)
	{
		//printf("%d:%c\n",i,str[i]);
        int k;
        k=i/2;
        if(i%2==0)
        {

           (*a)[k]=str[i]-'0';
        }

	}*/
	fclose(f);

}

void printArr(int n,int a[])
{

	int i;
	for ( i=0;i<n;i++)
	{
		printf("%d ",a[i]);
	}
	printf("\n");
}

void genTiles()
{
    int a[14];
    int i,r;
    srand(time(NULL));
    for (i=0;i<14;i++)
    {
        r=rand();
        a[i]=r%20;

    }
   // printArr(14,a);
    FILE *f;
	f=fopen("Tiles.txt","w");
	for (i=0;i<14;i++)
    {
      fprintf(f,"%d ",a[i]);
    }
	fclose(f);


}


void decreaseTile(int n,int (*a)[14])
{
    (*a)[n-1]--;
}

int sumArray(int a[14])
{
    int sum=0;
    int i;
    for (i=0;i<14;i++)
    {
        sum+=a[i];
    }
    return sum;
}

void readBoard()
{
    FILE *f;
	f=fopen("Board.txt","r");
	int i,j;
	for (i=0;i<30;i++)
    {
        //if (i%2==0)
        //{
            //int k;
            //k=i/2;
           for (j=0;j<30;j++)
            {
                //char c;
                fscanf(f,"%c ",&Board[i][j]);
                //printf("%c ",c);

            }
       // }
        printf("\n");

    }

	fclose(f);
}
