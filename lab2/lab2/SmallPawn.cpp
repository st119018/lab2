#include "SmallPawn.h"

bool SmallPawn::isPossibleForSmallPawn(int prevInd, int nextInd, int mapWidth, char* map)
{
    // calculating previous and next positions
    int prevX = findXpos(prevInd, mapWidth);
    int prevY = findYpos(prevInd, mapWidth);
    int nextX = findXpos(nextInd, mapWidth);
    int nextY = findYpos(nextInd, mapWidth);

    // if pawn moves or attack
    if ((prevX == nextX) && (nextY == prevY + 1) && (map[nextInd] == ' ') ||
       (nextY == prevY + 1) && ((nextX == prevX + 1) || (nextX == prevX - 1)) && map[nextInd] != ' ') {

        return true;
    }

    // if pawn moves to 2 squares ahead
    else if (nextX == prevX && nextY == prevY + 2 && prevY == 2 &&
             map[nextInd] == ' ' && map[findFigureIndex(prevX, nextY + 1)]) {

        return true;
    }
    else return false;

}
