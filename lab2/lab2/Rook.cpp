#include "Rook.h"

bool Rook::pathIsClear(int prevX, int prevY, int nextX, int nextY, char* map)
{
    bool isClear = true;

    if (nextX < prevX) {

        int i = prevX - 1;
        while (i > nextX) {
            int index = findFigureIndex(i, prevY);
            if (map[index] != ' ') {

                    isClear = false;
            }
            i--;
        }
    }
    else if (nextX > prevX) {

        int i = prevX + 1;
        while (i < nextX) {
            int index = findFigureIndex(i, prevY);
            if (map[index] != ' ') {

                isClear = false;
            }
            i++;
        }
    }

    if (nextY < prevY) {

        int j = prevY - 1;
        while (j > nextY) {
            int index = findFigureIndex(prevX, j);
            if (map[index] != ' ') {

                isClear = false;
            }
            j--;
        }
    }
    else if (nextY > prevY) {
        
        int j = prevY + 1;
        while (j > nextY) {
            int index = findFigureIndex(prevX, j);
            if (map[index] != ' ') {

                isClear = false;
            }
            j++;
        }
    }


    return isClear;
}


bool Rook::isPossibleForRook(int prevInd, int nextInd, int mapWidth, int mapHeight, char* map)
{
    int prevIndXpos = findXpos(prevInd, mapWidth);
    int prevIndYpos = findYpos(prevInd, mapWidth);
    int nextIndXpos = findXpos(nextInd, mapWidth);
    int nextIndYpos = findYpos(nextInd, mapWidth);


    if (prevIndXpos == nextIndXpos || prevIndYpos == nextIndYpos) {

        if (pathIsClear(prevIndXpos, prevIndYpos, nextIndXpos, nextIndYpos, map)) {

            return true;
        }
        else return false;
    }
    else return false;
}

