#include <stdio.h>
#include <stdlib.h>
#include "dsfunctions.h"

int main()
{
    struct Tile tile1;

        tile1.ID=1;
        tile1.N='r';
        tile1.E='p';
        tile1.S='p';
        tile1.W='p';
        tile1.Temple='F';
        tile1.Shield='T';
        tile1.Crossroad='F';

        printTile (&tile1 );

        int rot;

        scanf("%d",&rot);

        rotation(rot,&tile1);

        printTile (&tile1 );


}
