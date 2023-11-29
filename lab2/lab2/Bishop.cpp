#include "Bishop.h"


Bishop::Bishop(int LeftSmallIndex, int RightSmallIndex, int LeftLargeIndex, int RightLargeIndex)
{
    LeftSmallBishopInd = LeftSmallIndex;
    RightSmallBishopInd = RightSmallIndex;
    LeftLargeBishopInd = LeftLargeIndex;
    RightLargeBishopInd = RightLargeIndex;

}

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
    if (prevInd == LeftSmallBishopInd || prevInd == RightSmallBishopInd ||
        prevInd == LeftLargeBishopInd || prevInd == RightLargeBishopInd ||

        prevInd == SmallBishop1 || prevInd == SmallBishop2 || prevInd == SmallBishop3 || prevInd == SmallBishop4 || 
        prevInd == SmallBishop5 || prevInd == SmallBishop6 || prevInd == SmallBishop7 || prevInd == SmallBishop8 ||

        prevInd == LargeBishop1 || prevInd == LargeBishop2 || prevInd == LargeBishop3 || prevInd == LargeBishop4 || 
        prevInd == LargeBishop5 || prevInd == LargeBishop6 || prevInd == LargeBishop7 || prevInd == LargeBishop8) {

        int prevIndXpos = findXpos(prevInd, mapWidth);
        int prevIndYpos = findYpos(prevInd, mapWidth);
        int nextIndXpos = findXpos(nextInd, mapWidth);
        int nextIndYpos = findYpos(nextInd, mapWidth);


        if ((prevIndXpos + prevIndYpos == nextIndXpos + nextIndYpos) ||
            (prevIndXpos - prevIndYpos == nextIndXpos - nextIndYpos)) {

            if (pathIsClear(prevIndXpos, prevIndYpos, nextIndXpos, nextIndYpos, &map[0])) { // checking if bishop can move

                // memorizing new index
                if (prevInd == LeftSmallBishopInd) {
                    LeftSmallBishopInd = nextInd;
                }
                else if (prevInd == RightSmallBishopInd) {
                    RightSmallBishopInd = nextInd;
                }
                else if (prevInd == LeftLargeBishopInd) {
                    LeftLargeBishopInd = nextInd;
                }
                else if (prevInd == RightLargeBishopInd) {
                    RightLargeBishopInd = nextInd;
                }
                else if (prevInd == SmallBishop1) {
                    SmallBishop1 = nextInd;
                }
                else if (prevInd == SmallBishop2) {
                    SmallBishop2 = nextInd;
                }
                else if (prevInd == SmallBishop3) {
                    SmallBishop3 = nextInd;
                }
                else if (prevInd == SmallBishop4) {
                    SmallBishop4 = nextInd;
                }
                else if (prevInd == SmallBishop5) {
                    SmallBishop5 = nextInd;
                }
                else if (prevInd == SmallBishop6) {
                    SmallBishop6 = nextInd;
                }
                else if (prevInd == SmallBishop7) {
                    SmallBishop7 = nextInd;
                }
                else if (prevInd == SmallBishop8) {
                    SmallBishop8 = nextInd;
                }
                else if (prevInd == LargeBishop1) {
                    LargeBishop1 = nextInd;
                }
                else if (prevInd == LargeBishop2) {
                    LargeBishop2 = nextInd;
                }
                else if (prevInd == LargeBishop3) {
                    LargeBishop3 = nextInd;
                }
                else if (prevInd == LargeBishop4) {
                    LargeBishop4 = nextInd;
                }
                else if (prevInd == LargeBishop5) {
                    LargeBishop5 = nextInd;
                }
                else if (prevInd == LargeBishop6) {
                    LargeBishop6 = nextInd;
                }
                else if (prevInd == LargeBishop7) {
                    LargeBishop7 = nextInd;
                }
                else if (prevInd == LargeBishop8) {
                    LargeBishop8 = nextInd;
                }

                return true;
            }
            else return false;
        }
        else return false;
    }
    else return false;
}

void Bishop::addSmallInd(int index)
{
    if (SmallBishop1 == 0) {
        SmallBishop1 = index;
    }
    else if (SmallBishop2 == 0) {
        SmallBishop2 = index;
    }
    else if (SmallBishop3 == 0) {
        SmallBishop3 = index;
    }
    else if (SmallBishop4 == 0) {
        SmallBishop4 = index;
    }
    else if (SmallBishop5 == 0) {
        SmallBishop5 = index;
    }
    else if (SmallBishop6 == 0) {
        SmallBishop6 = index;
    }
    else if (SmallBishop7 == 0) {
        SmallBishop7 = index;
    }
    else if (SmallBishop8 == 0) {
        SmallBishop8 = index;
    }
}

void Bishop::addLargeInd(int index)
{
    if (LargeBishop1 == 0) {
        LargeBishop1 = index;
    }
    else if (LargeBishop2 == 0) {
        LargeBishop2 = index;
    }
    else if (LargeBishop3 == 0) {
        LargeBishop3 = index;
    }
    else if (LargeBishop4 == 0) {
        LargeBishop4 = index;
    }
    else if (LargeBishop5 == 0) {
        LargeBishop5 = index;
    }
    else if (LargeBishop6 == 0) {
        LargeBishop6 = index;
    }
    else if (LargeBishop7 == 0) {
        LargeBishop7 = index;
    }
    else if (LargeBishop8 == 0) {
        LargeBishop8 = index;
    }
}
