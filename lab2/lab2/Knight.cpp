#include "Knight.h"

// determines if knight can move
bool Knight::isPossibleForKnight(int prevInd, int nextInd, int mapWidth, char* map)
{
    // calculating previous and next positions
    int prevXpos = findXpos(prevInd, mapWidth);
    int prevYpos = findYpos(prevInd, mapWidth);
    int nextXpos = findXpos(nextInd, mapWidth);
    int nextYpos = findYpos(nextInd, mapWidth);


    // shift by 1 position on the X axis and 2 positions on the Y axis
    if (nextXpos == prevXpos + 1 || nextXpos == prevXpos - 1) {
        if (nextYpos == prevYpos + 2 || nextYpos == prevYpos - 2) {

            return true;
        }
    }


    // shift by 2 positions on the X axis and 1 position on the Y axis
    else if (nextXpos == prevXpos + 2 || nextXpos == prevXpos - 2) {
        if (nextYpos == prevYpos + 1 || nextYpos == prevYpos - 1) {

            return true;
        }
    }

    else return false;

}

