#include "Knight.h"

Knight::Knight(int LeftSmallIndex, int RightSmallIndex, int LeftLargeIndex, int RightLargeIndex)
{
    LeftSmallKnightInd = LeftSmallIndex;
    RightSmallKnightInd = RightSmallIndex;
    LeftLargeKnightInd = LeftLargeIndex;
    RightLargeKnightInd = RightLargeIndex;
}

// determines if knight can move
bool Knight::isPossibleForKnight(int prevInd, int nextInd, int mapWidth, char* map)
{
    if (prevInd == LeftSmallKnightInd || prevInd == RightSmallKnightInd ||
        prevInd == LeftLargeKnightInd || prevInd == RightLargeKnightInd ||

        prevInd == SmallKnight1 || prevInd == SmallKnight2 || prevInd == SmallKnight3 || prevInd == SmallKnight4 ||
        prevInd == SmallKnight5 || prevInd == SmallKnight6 || prevInd == SmallKnight7 || prevInd == SmallKnight8 ||

        prevInd == LargeKnight1 || prevInd == LargeKnight2 || prevInd == LargeKnight3 || prevInd == LargeKnight4 ||
        prevInd == LargeKnight5 || prevInd == LargeKnight6 || prevInd == LargeKnight7 || prevInd == LargeKnight8) {

        // calculating previous and next positions
        int prevXpos = findXpos(prevInd, mapWidth);
        int prevYpos = findYpos(prevInd, mapWidth);
        int nextXpos = findXpos(nextInd, mapWidth);
        int nextYpos = findYpos(nextInd, mapWidth);

        bool isPossible1 = false;
        bool isPossible2 = false;

        // shift by 1 position on the X axis and 2 positions on the Y axis
        if (nextXpos == prevXpos + 1 || nextXpos == prevXpos - 1) {
            if (nextYpos == prevYpos + 2 || nextYpos == prevYpos - 2) {

                isPossible1 = true;
            }
        }
        // shift by 2 positions on the X axis and 1 position on the Y axis
        else if (nextXpos == prevXpos + 2 || nextXpos == prevXpos - 2) {
            if (nextYpos == prevYpos + 1 || nextYpos == prevYpos - 1) {

                isPossible2 = true;
            }
        }

        if (isPossible1 || isPossible2) {

            // memorizing new index
            if (prevInd == LeftSmallKnightInd) {
                LeftSmallKnightInd = nextInd;
            }
            else if (prevInd == RightSmallKnightInd) {
                RightSmallKnightInd = nextInd;
            }
            else if (prevInd == LeftLargeKnightInd) {
                LeftLargeKnightInd = nextInd;
            }
            else if (prevInd == RightLargeKnightInd) {
                RightLargeKnightInd = nextInd;
            }
            else if (prevInd == SmallKnight1) {
                SmallKnight1 = nextInd;
            }
            else if (prevInd == SmallKnight2) {
                SmallKnight2 = nextInd;
            }
            else if (prevInd == SmallKnight3) {
                SmallKnight3 = nextInd;
            }
            else if (prevInd == SmallKnight4) {
                SmallKnight4 = nextInd;
            }
            else if (prevInd == SmallKnight5) {
                SmallKnight5 = nextInd;
            }
            else if (prevInd == SmallKnight6) {
                SmallKnight6 = nextInd;
            }
            else if (prevInd == SmallKnight7) {
                SmallKnight7 = nextInd;
            }
            else if (prevInd == SmallKnight8) {
                SmallKnight8 = nextInd;
            }
            else if (prevInd == LargeKnight1) {
                LargeKnight1 = nextInd;
            }
            else if (prevInd == LargeKnight2) {
                LargeKnight2 = nextInd;
            }
            else if (prevInd == LargeKnight3) {
                LargeKnight3 = nextInd;
            }
            else if (prevInd == LargeKnight4) {
                LargeKnight4 = nextInd;
            }
            else if (prevInd == LargeKnight5) {
                LargeKnight5 = nextInd;
            }
            else if (prevInd == LargeKnight6) {
                LargeKnight6 = nextInd;
            }
            else if (prevInd == LargeKnight7) {
                LargeKnight7 = nextInd;
            }
            else if (prevInd == LargeKnight8) {
                LargeKnight8 = nextInd;
            }

            return true;
        }
        else return false;
    }
    else return false;
}

void Knight::addSmallInd(int index)
{
    if (SmallKnight1 == 0) {
        SmallKnight1 = index;
    }
    else if (SmallKnight2 == 0) {
        SmallKnight2 = index;
    }
    else if (SmallKnight3 == 0) {
        SmallKnight3 = index;
    }
    else if (SmallKnight4 == 0) {
        SmallKnight4 = index;
    }
    else if (SmallKnight5 == 0) {
        SmallKnight5 = index;
    }
    else if (SmallKnight6 == 0) {
        SmallKnight6 = index;
    }
    else if (SmallKnight7 == 0) {
        SmallKnight7 = index;
    }
    else if (SmallKnight8 == 0) {
        SmallKnight8 = index;
    }

}

void Knight::addLargeInd(int index)
{
    if (LargeKnight1 == 0) {
        LargeKnight1 = index;
    }
    else if (LargeKnight2 == 0) {
        LargeKnight2 = index;
    }
    else if (LargeKnight3 == 0) {
        LargeKnight3 = index;
    }
    else if (LargeKnight4 == 0) {
        LargeKnight4 = index;
    }
    else if (LargeKnight5 == 0) {
        LargeKnight5 = index;
    }
    else if (LargeKnight6 == 0) {
        LargeKnight6 = index;
    }
    else if (LargeKnight7 == 0) {
        LargeKnight7 = index;
    }
    else if (LargeKnight8 == 0) {
        LargeKnight8 = index;
    }

}

