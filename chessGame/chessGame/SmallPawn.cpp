#include "SmallPawn.h"

SmallPawn::SmallPawn(int column)
{
    pieceType = 'p';
    team = 'b';
    Xpos = column;
    Ypos = 2;
   
}

bool SmallPawn::isPossible(int prevInd, int nextInd, BaseF* map)
{
    // calculating previous and next positions
    int prevXpos = findXpos(prevInd);
    int prevYpos = findYpos(prevInd);


    if (prevXpos == Xpos && prevYpos == Ypos) {

        int nextXpos = findXpos(nextInd);
        int nextYpos = findYpos(nextInd);

        // if pawn moves or attack
        if (((prevXpos == nextXpos) && (nextYpos == prevYpos + 1) && (map[nextInd].getTeam() == 'n')) ||
            ((nextYpos == prevYpos + 1) && ((nextXpos == prevXpos + 1) || (nextXpos == prevXpos - 1)) && map[nextInd].getTeam() != 'n')) {

            Xpos = nextXpos;
            Ypos = nextYpos;

            return true;
        }
        // if pawn moves to 2 squares ahead
        else if (nextXpos == prevXpos && nextYpos == prevYpos + 2 && prevYpos == 2 &&
            map[nextInd].getTeam() == 'n' && map[findFigureIndex(prevXpos, nextYpos - 1)].getTeam() == 'n') { 

            Xpos = nextXpos;
            Ypos = nextYpos;

            return true;
        }
        else return false;
    }
    else return false;
}
