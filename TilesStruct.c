#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
int ID;
char N;
char W;
char S;
char E; 
char Temple;
char Shield;
char Crossroad;

}Tile;

void stringtoStruct (int n,char s[],Tile *tile);
void getLibrary(int n,Tile *t);
void getTiles (int (*a)[14]);
void rotation (int r,Tile *tile);
void printTile(Tile *tile);
void printArr(int n,int a[]);


int quant[14];

int main ()
{
	Tile tile1;
	tile1.ID=2;
	tile1.N='P';	
	tile1.W='P';
	tile1.S='R';
	tile1.E='P';
	tile1.Temple='T';
	tile1.Crossroad='T';
	tile1.Shield='F';
	printTile(&tile1);
	int rot;
	scanf("%d",&rot);
	rotation(rot,&tile1);
	printTile(&tile1);

	getTiles(&quant);
	printArr(14,quant);
	
	char example[7] = "PPRRFFF";
	stringtoStruct (9,example,&tile1);
	printTile(&tile1);

	Tile tiles[14];
	getLibrary(12,&tiles[12]);
	

	printTile(&tiles[12]);
	
	
	for (int i=0;i<14;i++)
	{
		getLibrary(i,&tiles[i]);		
		printTile(&tiles[i]);
	}



}


void getLibrary(int n,Tile (*t))
{
	FILE *f;
	f=fopen("Library.txt","r");
	
	char str[8];

	for (int i=0;i<28;i++)
	{	
		int k;
		k=i/2;
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
	
	char str[14];	

	fgets(str,30,(FILE*)f);
	
	int i;
	for (i=0;i<14;i++)
	{	
		printf("%c\n",str[i]);
		(*a)[i]=str[i]-'0';

	}

	fclose(f);	

}

void rotation (int r,Tile *tile)
{		
   int x;
   x=r%4;
	
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


void printTile(Tile *tile)
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



void printArr(int n,int a[])
{
	for (int i=0;i<n;i++)
	{
		printf("%d ",a[i]);
	}
	printf("\n");
}
