#include <stdio.h>
#include <stdlib.h>
#include "inpu.h"
#include "outpu.h"
#include "logi.h"
#include "auto.h"
# ifdef __unix__
# include <unistd.h>
# elif defined _WIN32
# include <windows.h>
# endif


int main()
{
    Tile tiles[14];


    getTiles(&quant);

    int plid,ex,rot,xco,yco,mov;
    int i;
	for (i=0;i<14;i++)
	{
		getLibrary(i,&tiles[i]);
		//printTile(&tiles[i]);
		//showTile(tiles[i]);
	}

	printf("CARCASSONNE INTERACTIVE MODE\n");

	Board = malloc(30 * sizeof(char*));

    setBoard(Board);
    clearBoard();
   // printBoard();
    //readBoard(30);
    //printBoard();


    //int test1,test2;
    //searchCross(&test1,&test2);
    //printf("First crossroads coordinates y:%d x:%d\n",test1,test2);
    //printf("Min points for tiles :%d %d %d %d\n",countMinTile(9,15),countMinTile(12,15),countMinTile(12,12),countMinTile(15,15));
    //printf("All min points: %d\n",countMinPoints());
    //printf("%d\n",countPoints());
    //printBoard();
    int mod;
    mov=1;
    //printBoard();
    //readBoard(30);
   // printBoard();
   printf("Generate the tiles?\nYES - 1\nNO - 0\nPut the corresponding number\n");
               int answ;
               scanf("%d",&answ);
               if (answ==1)
               {
                   genTiles();
                   getTiles(&quant);
               }

   printf("1. 1 for interactive mode\n2. 2 for automatic mode\n");
   scanf("%d",&mod);
   switch (mod){
        case 1:
            {



                mov=1;
                printf("CARCASSONNE INTERACTIVE MODE\n");
                while(sumArray(quant)!=0)
                {

                    printBoard();
                    printf("MOVE NR %d\n",mov);
                    showDeck(tiles,quant);
                    printf("Choose the tile id (from 1-14):\n");
                    scanf("%d",&plid);
                    while(quant[plid-1]==0)
                    {
                        printf("No tile of this type\n");
                        printf("Choose the tile id (from 1-14):\n");
                        scanf("%d",&plid);
                    }
                    showTile(tiles[plid-1]);
                    printf("Put 4 numbers with spaces in such order:\n");
                    printf("1: 1-play the tile 2-choose another tile 3-replay 4-exit \n2: number of rotations \n3: y coordinate of placement \n4: x coordinate of placement\n");
                    scanf("%d %d %d %d",&ex,&rot,&yco,&xco);
                    //printf("%d %d %d %d",ex,rot,yco,xco);

                    switch (ex){
                    case 1:
                        playTile(plid,&tiles[plid-1],xco,yco,&quant,rot,&mov);
                        break;
                    case 2:
                        break;
                    case 3:
                        clearBoard();
                        getTiles(&quant);
                        mov=1;
                        printf("GAME RESTART\n");
                        break;
                    case 4:
                        printf("END OF THE GAME \n");
                        printtofileBoard();
                        printf("Points:%d\n",countPoints());
                        return 0;

                    }

                }
            }

        case 2:
            {
                srand(time(NULL));
                int j,moves;
                int tile_numbers[14],tile_number;
                //int tile_places[100];

                arrsize=1;
                data = malloc(arrsize * sizeof *data);
                data[0]=rand()%100;
                tile_numbers[0]=rand()%14;
                autoAddCoordinate(data[0]);
                printf("hello\n");
                autoPlaceTile(tiles[0],(data[0]/10)+1,(data[0])%10+1,1);
                printf("hello\n");

                moves=1;
                for(i=0;i<14;i++)
                {
                    tile_numbers[i]=i;

                }

                for (i = 0; i < 14; i++) {    // shuffle array
                int temp = tile_numbers[i];
                int randomIndex = rand() % 13;

                tile_numbers[i] = tile_numbers[randomIndex];
                tile_numbers[randomIndex] = temp;
                }
                for(i=0;i<100;i++)
                {

                    int plac=rand()%arrsize;
                    int rottile=rand()%3;
                    autoFinalPlaceTile(&tiles[i%14],(data[plac]/10)+1,(data[plac]%10)+1,rottile,&moves);
                    //printf("%d    %d    \n",(data[plac]/10)+1,(data[plac]%10)+1);

                }
                printBoard();



                break;

            }
        default:
            {
                printf("Mode not Recognized.");
                exit(0);
            }



   }


    return 0;
}










