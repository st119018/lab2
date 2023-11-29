#include "Rook.h"

Rook::Rook(int LeftSmallIndex, int RightSmallIndex, int LeftLargeIndex, int RightLargeIndex)
{
    LeftSmallRookInd = LeftSmallIndex;
    RightSmallRookInd = RightSmallIndex;
    LeftLargeRookInd = LeftLargeIndex;
    RightLargeRookInd = RightLargeIndex;
}

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
    if (prevInd == LeftSmallRookInd || prevInd == RightSmallRookInd || 
        prevInd == LeftLargeRookInd || prevInd == RightLargeRookInd ||

        prevInd == SmallRook1 || prevInd == SmallRook2 || prevInd == SmallRook3 || prevInd == SmallRook4 || 
        prevInd == SmallRook5 || prevInd == SmallRook6 || prevInd == SmallRook7 || prevInd == SmallRook8 ||

        prevInd == LargeRook1 || prevInd == LargeRook2 || prevInd == LargeRook3 || prevInd == LargeRook4 || 
        prevInd == LargeRook5 || prevInd == LargeRook6 || prevInd == LargeRook7 || prevInd == LargeRook8) {

        int prevIndXpos = findXpos(prevInd, mapWidth);
        int prevIndYpos = findYpos(prevInd, mapWidth);
        int nextIndXpos = findXpos(nextInd, mapWidth);
        int nextIndYpos = findYpos(nextInd, mapWidth);


        if (prevIndXpos == nextIndXpos || prevIndYpos == nextIndYpos) {

            if (pathIsClear(prevIndXpos, prevIndYpos, nextIndXpos, nextIndYpos, map)) {

                // memorizing new index
                if (prevInd == LeftSmallRookInd) {
                    LeftSmallRookInd = nextInd;
                }
                else if (prevInd == RightSmallRookInd) {
                    RightSmallRookInd = nextInd;
                }
                else if (prevInd == LeftLargeRookInd) {
                    LeftLargeRookInd = nextInd;
                }
                else if (prevInd == RightLargeRookInd) {
                    RightLargeRookInd = nextInd;
                }
                else if (prevInd == SmallRook1) {
                    SmallRook1 = nextInd;
                }
                else if (prevInd == SmallRook2) {
                    SmallRook2 = nextInd;
                }
                else if (prevInd == SmallRook3) {
                    SmallRook3 = nextInd;
                }
                else if (prevInd == SmallRook4){
                    SmallRook4 = nextInd;
                }
                else if (prevInd == SmallRook5) {
                    SmallRook5 = nextInd;
                }
                else if (prevInd == SmallRook6) {
                    SmallRook6 = nextInd;
                }
                else if (prevInd == SmallRook7) {
                    SmallRook7 = nextInd;
                }
                else if (prevInd == SmallRook8) {
                    SmallRook8 = nextInd;
                }
                else if (prevInd == LargeRook1) {
                    LargeRook1 = nextInd;
                }
                else if (prevInd == LargeRook2) {
                    LargeRook2 = nextInd;
                }
                else if (prevInd == LargeRook3) {
                    LargeRook3 = nextInd;
                }
                else if (prevInd == LargeRook4) {
                    LargeRook4 = nextInd;
                }
                else if (prevInd == LargeRook5) {
                    LargeRook5 = nextInd;
                }
                else if (prevInd == LargeRook6) {
                    LargeRook6 = nextInd;
                }
                else if (prevInd == LargeRook7) {
                    LargeRook7 = nextInd;
                }
                else if (prevInd == LargeRook8) {
                    LargeRook8 = nextInd;
                }

                return true;
            }
            else return false;
        }
        else return false;
    }
    else return false;
}


void Rook::addSmallInd(int index)
{
    if (SmallRook1 == 0) {
        SmallRook1 = index;
    }
    else if (SmallRook2 == 0) {
        SmallRook2 = index;
    }
    else if (SmallRook3 == 0) {
        SmallRook3 = index;
    }
    else if (SmallRook4 == 0) {
        SmallRook4 = index;
    }
    else if (SmallRook5 == 0) {
        SmallRook5 = index;
    }
    else if (SmallRook6 == 0) {
        SmallRook6 = index;
    }
    else if (SmallRook7 == 0) {
        SmallRook7 = index;
    }
    else if (SmallRook8 == 0) {
        SmallRook8 = index;
    }

}

void Rook::addLargeInd(int index)
{
    if (LargeRook1 == 0) {
        LargeRook1 = index;
    }
    else if (LargeRook2 == 0) {
        LargeRook2 = index;
    }
    else if (LargeRook3 == 0) {
        LargeRook3 = index;
    }
    else if (LargeRook4 == 0) {
        LargeRook4 = index;
    }
    else if (LargeRook5 == 0) {
        LargeRook5 = index;
    }
    else if (LargeRook6 == 0) {
        LargeRook6 = index;
    }
    else if (LargeRook7 == 0) {
        LargeRook7 = index;
    }
    else if (LargeRook8 == 0) {
        LargeRook8 = index;
    }

}
