#include "SmallPawn.h"

SmallPawn::SmallPawn(int Ind1, int Ind2, int Ind3, int Ind4, int Ind5, int Ind6, int Ind7, int Ind8)
{
    Pawn1 = Ind1;
    Pawn2 = Ind2;
    Pawn3 = Ind3;
    Pawn4 = Ind4;
    Pawn5 = Ind5;
    Pawn6 = Ind6;
    Pawn7 = Ind7;
    Pawn8 = Ind8;
}

bool SmallPawn::isPossibleForSmallPawn(int prevInd, int nextInd, int mapWidth, char* map)
{
    if (prevInd == Pawn1 || prevInd == Pawn2 || prevInd == Pawn3 || prevInd == Pawn4 || 
        prevInd == Pawn5 || prevInd == Pawn6 || prevInd == Pawn7 || prevInd == Pawn8) {

        // calculating previous and next positions
        int prevX = findXpos(prevInd, mapWidth);
        int prevY = findYpos(prevInd, mapWidth);
        int nextX = findXpos(nextInd, mapWidth);
        int nextY = findYpos(nextInd, mapWidth);

        // if pawn moves or attack
        if ((prevX == nextX) && (nextY == prevY + 1) && (map[nextInd] == ' ') ||
            (nextY == prevY + 1) && ((nextX == prevX + 1) || (nextX == prevX - 1)) && map[nextInd] != ' ') {

            if (prevInd == Pawn1) {
                Pawn1 = nextInd;
            }
            else if (prevInd == Pawn2) {
                Pawn2 = nextInd;
            }
            else if (prevInd == Pawn3) {
                Pawn3 = nextInd;
            }
            else if (prevInd == Pawn4) {
                Pawn4 = nextInd;
            }
            else if (prevInd == Pawn5) {
                Pawn5 = nextInd;
            }
            else if (prevInd == Pawn6) {
                Pawn6 = nextInd;
            }
            else if (prevInd == Pawn7) {
                Pawn7 = nextInd;
            }
            else if (prevInd == Pawn8) {
                Pawn8 = nextInd;
            }

            return true;
        }

        // if pawn moves to 2 squares ahead
        else if (nextX == prevX && nextY == prevY + 2 && prevY == 2 &&
                 map[nextInd] == ' ' && map[findFigureIndex(prevX, nextY + 1)]) {

            if (prevInd == Pawn1) {
                Pawn1 = nextInd;
            }
            else if (prevInd == Pawn2) {
                Pawn2 = nextInd;
            }
            else if (prevInd == Pawn3) {
                Pawn3 = nextInd;
            }
            else if (prevInd == Pawn4) {
                Pawn4 = nextInd;
            }
            else if (prevInd == Pawn5) {
                Pawn5 = nextInd;
            }
            else if (prevInd == Pawn6) {
                Pawn6 = nextInd;
            }
            else if (prevInd == Pawn7) {
                Pawn7 = nextInd;
            }
            else if (prevInd == Pawn8) {
                Pawn8 = nextInd;
            }

            return true;
        }
        else return false;
    }
    else return false;
}
