#include "King.h"

King::King(char team)
{
    pieceType = 'k';
    this->team = team;

    if (team == 'b') {
        Xpos = 4;
        Ypos = 1;
    }
    else {
        Xpos = 4;
        Ypos = 8;
    }
}

bool King::isPossible(int prevInd, int nextInd, BaseF* map)
{
    int prevXpos = findXpos(prevInd);
    int prevYpos = findYpos(prevInd);
    
    // 
    if (prevXpos == Xpos && prevYpos == Ypos) {
        for (int x = -1; x <= 1; x++) {
            for (int y = -1; y <= 1; y++) {

                int newInd = prevInd + x * 8 + y;

                if (newInd == nextInd && map[nextInd].getTeam() != map[prevInd].getTeam()) {

                    Xpos = findXpos(nextInd);
                    Ypos = findYpos(nextInd);

                    return true;
                }

            }
        }
    }

    return false;
}

int King::getXpos()
{
    return Xpos;
}

int King::getYpos()
{
    return Ypos;
}
