#include "Queen.h"

bool Queen::pathIsClear(int prevX, int prevY, int nextX, int nextY, char* map)
{

    bool isClear = true;

    // checking if queen can move like bishop
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



    // checking if queen can move like rook
    if (prevX == nextX || prevY == nextY) {

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
    }

    return isClear;
}

bool Queen::isPossibleForQueen(int prevInd, int nextInd, int mapWidth, int mapHeight, char* map)
{
    int prevIndXpos = findXpos(prevInd, mapWidth);
    int prevIndYpos = findYpos(prevInd, mapWidth);
    int nextIndXpos = findXpos(nextInd, mapWidth);
    int nextIndYpos = findYpos(nextInd, mapWidth);


    if ((prevIndXpos + prevIndYpos == nextIndXpos + nextIndYpos) ||
        (prevIndXpos - prevIndYpos == nextIndXpos - nextIndYpos) ||
        (prevIndXpos == nextIndXpos || prevIndYpos == nextIndYpos)) {

        if (pathIsClear(prevIndXpos, prevIndYpos, nextIndXpos, nextIndYpos, &map[0])) {

            return true;
        }
        else return false;
    }
    else return false;
}
