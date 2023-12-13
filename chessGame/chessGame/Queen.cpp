#include "Queen.h"

Queen::Queen(char team)
{
    pieceType = 'q';
    this->team = team;

    if (team == 'b') {
        Xpos = 5;
        Ypos = 1;
    }
    else {
        Xpos = 5;
        Ypos = 8;
    }
}

bool Queen::isPossible(int prevInd, int nextInd, BaseF* map)
{
    // calculating previous positions
    int prevXpos = findXpos(prevInd);
    int prevYpos = findYpos(prevInd);


    if (prevXpos == Xpos && prevYpos == Ypos) {

        int nextXpos = findXpos(nextInd);
        int nextYpos = findYpos(nextInd);

        if ((prevXpos + prevYpos == nextXpos + nextYpos) ||
            (prevXpos - prevYpos == nextXpos - nextYpos) ||
            (nextXpos == prevXpos || nextYpos == prevYpos)) {

            if (pathIsClear(prevXpos, prevYpos, nextXpos, nextYpos, map)) {

				Xpos = nextXpos;
				Ypos = nextYpos;

				return true;
            }
            else return false;
        }
        else return false;
    }
    else return false;
}

bool Queen::pathIsClear(int prevX, int prevY, int nextX, int nextY, BaseF* map)
{
    bool isClear = true;

	if (prevX + prevY == nextX + nextY) {
		if (prevX < nextX) {
			int i = prevX + 1;
			int j = prevY - 1;
			while (i < nextX && j > nextY) {
				int index = findFigureIndex(i, j) - 1;
				if (map[index].getTeam() != 'n') {

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
				int index = findFigureIndex(i, j) - 1;
				if (map[index].getTeam() != 'n') {

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
				int index = findFigureIndex(i, j) - 1;
				if (map[index].getTeam() != 'n') {

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
				int index = findFigureIndex(i, j) - 1;
				if (map[index].getTeam() != 'n') {

					isClear = false;
				}
				i--;
				j--;
			}
		}
	}


	if (prevX == nextX || prevY == nextY) {

		if (nextX < prevX) {

			int i = prevX - 1;
			while (i > nextX) {
				int index = findFigureIndex(i, prevY) - 1;
				if (map[index].getTeam() != 'n') {

					isClear = false;
				}
				i--;
			}
		}
		else if (nextX > prevX) {

			int i = prevX + 1;
			while (i < nextX) {
				int index = findFigureIndex(i, prevY) - 1;
				if (map[index].getTeam() != 'n') {

					isClear = false;
				}
				i++;
			}
		}

		if (nextY < prevY) {

			int j = prevY - 1;
			while (j > nextY) {
				int index = findFigureIndex(prevX, j) - 1;
				if (map[index].getTeam() != 'n') {

					isClear = false;
				}
				j--;
			}
		}
		else if (nextY > prevY) {

			int j = prevY + 1;
			while (j < nextY) { 
				int index = findFigureIndex(prevX, j) - 1;
				if (map[index].getTeam() != 'n') {

					isClear = false;
				}
				j++;
			}
		}
	}

    return isClear;
}
