#include <stdio.h>
#include <stdlib.h>
#include <time.h>


void printArray(int a[], int len);
void generateTile(int g,int (*a)[]);

// to see the right result you need to put the txt file called "Tiles.txt" to the same
// folder as the program and probably also add to the project files I'll send you maybe
// the screen shot and also I added it to the functions in the c and header files

int main()
{
    int quant[14]={0};

    //putting 0 in every place of an array

    printArray(quant, 14);

    // printing to check if everything is zero

    int gen;

    scanf("%d",&gen);
    //asking for a number of generated tiles

    generateTile(gen,&quant);

    //generating the tiles

    printArray(quant, 14);

    //printing what should be in the text file check it out

    return 0;

}

void printArray(int a[], int len)
{
    for (int i = 0; i < len; i++)
        printf("%d ", a[i]);

    printf("\n");
}


void generateTile(int g,int (*a)[])
{

    srand(time(0));

    for (int i=0;i<g;i++)
    {
        int x=0;
        x = rand () % 14;
        printf("%d \n",x);

        (*a )[x]++;


    }

   FILE *fileTile = fopen("Tiles.txt","w");

   if (fileTile!=NULL)
   {

     for (int i = 0; i < 14; i++)
        fprintf(fileTile,"%d ", (*a)[i]);
        fclose(fileTile);

   }else{

       printf("File not found\n");

    }

}



