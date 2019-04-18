#ifndef CALC_FILE
#define CALC_FILE
#include "inpu.h"
#include "outpu.h"


int countMinPoints();
//counts the minimal points without any ended roads or cities
int countMinTile(int a, int b);
 //counts the min  points for a certain tile on the board
int countCities();
//counts the points for the connected city segments
int countSinCity(int a,int b);
//single connected city segment
void removeSinCity(int a,int b);
//removes single city segment from the board
int countPoints();
//counts the minimal points with the connected city points (no roads yet ;(..,but they will be available soon)


#endif
