
#ifndef INPU_FILE
#define INPU_FILE


int quant[14];

//int i,j;

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
//assigns parameters from a string to the struct
void getLibrary(int n,Tile *t);
//gets the data from library of the n line and assigns them to the tile given to the function
//loop for assigning every tile
//int i;
	//for (i=0;i<14;i++)
	//{
	//	getLibrary(i,&tiles[i]);
	//	printTile(&tiles[i]);
	//}
//k=n/2 i<28 - linu; k=n/3 i<42 - windows
void getTiles (int (*a)[14]);
//reads the numbers of each type of tile and assigns it to the array

//void printTile(Tile *tile);
//complex printing of the tile

void printArr(int n,int a[]);
//prints an array
void genTiles();
//generate tiles to file to max 19 tiles

void decreaseTile(int n,int (*a)[14]);

int sumArray(int a[14]);

void readBoard();
//reads the board from Board.txt

#endif // INPU_FILE





