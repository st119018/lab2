#include "Queen.h"

Queen::Queen(int SmallIndex, int LargeIndex)
{
    SmallQueenInd = SmallIndex;
    LargeQueenInd = LargeIndex;
}

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
    if (prevInd == SmallQueenInd || prevInd == LargeQueenInd ||

        prevInd == SmallQueen1 || prevInd == SmallQueen2 || prevInd == SmallQueen3 || prevInd == SmallQueen4 ||
        prevInd == SmallQueen5 || prevInd == SmallQueen6 || prevInd == SmallQueen7 || prevInd == SmallQueen8 ||

        prevInd == LargeQueen1 || prevInd == LargeQueen2 || prevInd == LargeQueen3 || prevInd == LargeQueen4 || 
        prevInd == LargeQueen5 || prevInd == LargeQueen6 || prevInd == LargeQueen7 || prevInd == LargeQueen8) {

        int prevIndXpos = findXpos(prevInd, mapWidth);
        int prevIndYpos = findYpos(prevInd, mapWidth);
        int nextIndXpos = findXpos(nextInd, mapWidth);
        int nextIndYpos = findYpos(nextInd, mapWidth);


        if ((prevIndXpos + prevIndYpos == nextIndXpos + nextIndYpos) ||
            (prevIndXpos - prevIndYpos == nextIndXpos - nextIndYpos) ||
            (prevIndXpos == nextIndXpos || prevIndYpos == nextIndYpos)) {

            if (pathIsClear(prevIndXpos, prevIndYpos, nextIndXpos, nextIndYpos, &map[0])) {

                // memorizing new index
                if (prevInd == SmallQueenInd) {
                    SmallQueenInd = nextInd;
                }
                else if (prevInd == LargeQueenInd) {
                    LargeQueenInd = nextInd;
                }
                else if (prevInd == SmallQueen1) {
                    SmallQueen1 = nextInd;
                }
                else if (prevInd == SmallQueen2) {
                    SmallQueen2 = nextInd;
                }
                else if (prevInd == SmallQueen3) {
                    SmallQueen3 = nextInd;
                }
                else if (prevInd == SmallQueen4) {
                    SmallQueen4 = nextInd;
                }
                else if (prevInd == SmallQueen5) {
                    SmallQueen5 = nextInd;
                }
                else if (prevInd == SmallQueen6) {
                    SmallQueen6 = nextInd;
                }
                else if (prevInd == SmallQueen7) {
                    SmallQueen7 = nextInd;
                }
                else if (prevInd == SmallQueen8) {
                    SmallQueen8 = nextInd;
                }
                else if (prevInd == LargeQueen1) {
                    LargeQueen1 = nextInd;
                }
                else if (prevInd == LargeQueen2) {
                    LargeQueen2 = nextInd;
                }
                else if (prevInd == LargeQueen3) {
                    LargeQueen3 = nextInd;
                }
                else if (prevInd == LargeQueen4) {
                    LargeQueen4 = nextInd;
                }
                else if (prevInd == LargeQueen5) {
                    LargeQueen5 = nextInd;
                }
                else if (prevInd == LargeQueen6) {
                    LargeQueen6 = nextInd;
                }
                else if (prevInd == LargeQueen7) {
                    LargeQueen7 = nextInd;
                }
                else if (prevInd == LargeQueen8) {
                    LargeQueen8 = nextInd;
                }

                return true;
            }
            else return false;
        }
        else return false;
    }
    else return false;
}

void Queen::addSmallInd(int index)
{
    if (SmallQueen1 == 0) {
        SmallQueen1 = index;
    }
    else if (SmallQueen2 == 0) {
        SmallQueen2 = index;
    }
    else if (SmallQueen3 == 0) {
        SmallQueen3 = index;
    }
    else if (SmallQueen4 == 0) {
        SmallQueen4 = index;
    }
    else if (SmallQueen5 == 0) {
        SmallQueen5 = index;
    }
    else if (SmallQueen6 == 0) {
        SmallQueen6 = index;
    }
    else if (SmallQueen7 == 0) {
        SmallQueen7 = index;
    }
    else if (SmallQueen8 == 0) {
        SmallQueen8 = index;
    }

}

void Queen::addLargeInd(int index)
{
    if (LargeQueen1 == 0) {
        LargeQueen1 = index;
    }
    else if (LargeQueen2 == 0) {
        LargeQueen2 = index;
    }
    else if (LargeQueen3 == 0) {
        LargeQueen3 = index;
    }
    else if (LargeQueen4 == 0) {
        LargeQueen4 = index;
    }
    else if (LargeQueen5 == 0) {
        LargeQueen5 = index;
    }
    else if (LargeQueen6 == 0) {
        LargeQueen6 = index;
    }
    else if (LargeQueen7 == 0) {
        LargeQueen7 = index;
    }
    else if (LargeQueen8 == 0) {
        LargeQueen8 = index;
    }

}
