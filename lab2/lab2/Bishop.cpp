#include "Bishop.h"


bool Bishop::pathIsClear(int prevX, int prevY, int nextX, int nextY, char* map) {

    bool isClear = true;

    if (prevX + prevY == nextX + nextY) {
        if (prevX < nextX) {
            int i = prevX + 1;
            int j = prevY - 1;
            while (i < nextX && j > nextY) {
                int index = findFigureIndex(i, j);
                if (map[index] != ' ') {

                    isClear = false;
                }
                i++;
                j--;
            }
        }
        else if (prevX > nextX) {
            int i = prevX - 1;
            int j = prevY + 1;
            while (i > nextX && j < nextY) {
                int index = findFigureIndex(i, j);
                if (map[index] != ' ') {

                    isClear = false;
                }
                i--;
                j++;
            }

        }
    }


    else if (prevX - prevY == nextX - nextY) {
        if (prevX < nextX) {
            int i = prevX + 1;
            int j = prevY + 1;
            while (i < nextX && j < nextY) {
                int index = findFigureIndex(i, j);
                if (map[index] != ' ') {

                    isClear = false;
                }
                i++;
                j++;
            }
        }
        else if (prevX > nextX) {
            int i = prevX - 1;
            int j = prevY - 1;
            while (i > nextX && j > nextY) {
                int index = findFigureIndex(i, j);
                if (map[index] != ' ') {

                    isClear = false;
                }
                i--;
                j--;
            }
        }
    } 


    return isClear;
}



bool Bishop::isPossibleForBishop(int prevInd, int nextInd, int mapWidth, int mapHeight, char* map)
{

    int prevIndXpos = findXpos(prevInd, mapWidth);
    int prevIndYpos = findYpos(prevInd, mapWidth);
    int nextIndXpos = findXpos(nextInd, mapWidth);
    int nextIndYpos = findYpos(nextInd, mapWidth);

    
    if ((prevIndXpos + prevIndYpos == nextIndXpos + nextIndYpos) ||
        (prevIndXpos - prevIndYpos == nextIndXpos - nextIndYpos)) {

        if (pathIsClear(prevIndXpos, prevIndYpos, nextIndXpos, nextIndYpos, &map[0])) { // checking if bishop can move

            return true;
        }
        else return false;

    }
    else return false;

}
