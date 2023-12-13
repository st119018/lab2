#include "Rook.h"

Rook::Rook(char team, std::string side)
{
    pieceType = 'r';
    this->team = team;

	for (auto c : side) {
		if (c >= 'A' && c <= 'Z') {
			c = c - 'A' + 'a';
		}
	}

	if (team == 'b') {
		if (side == "right") {
			Xpos = 8;
			Ypos = 1;
		}
		else {
			Xpos = 1;
			Ypos = 1;
		}
	}
	else {
		if (side == "right") {
			Xpos = 8;
			Ypos = 8;
		}
		else {
			Xpos = 1;
			Ypos = 8;
		}

	}
}


bool Rook::isPossible(int prevInd, int nextInd, BaseF* map)
{
	// calculating previous positions
	int prevXpos = findXpos(prevInd);
	int prevYpos = findYpos(prevInd);

	if (prevXpos == Xpos && prevYpos == Ypos) {

		int nextXpos = findXpos(nextInd);
		int nextYpos = findYpos(nextInd);
		
		if (nextXpos == prevXpos || nextYpos == prevYpos) {

			if (pathIsClear(prevXpos, prevYpos, nextXpos, nextYpos, map)) {

				Xpos = nextXpos;
				Ypos = nextYpos;

				return true;
			}
			else return false;
		}
		else return false;
	}
    else  return false;
}


bool Rook::pathIsClear(int prevX, int prevY, int nextX, int nextY, BaseF* map)
{
	bool isClear = true;

	if (prevY == nextY) {
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
	}
	else if (prevX == nextX) {
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
