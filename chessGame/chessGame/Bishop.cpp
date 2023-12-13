#include "Bishop.h"

Bishop::Bishop(char team, std::string side)
{
	pieceType = 'b';
	this->team = team;

	for (auto c : side) {
		if (c >= 'A' && c <= 'Z') {
			c = c - 'A' + 'a';
		}
	}

	if (team == 'b') {
		if (side == "right") {
			Xpos = 6;
			Ypos = 1;
		}
		else {
			Xpos = 3;
			Ypos = 1;
		}
	}
	else {
		if (side == "right") {
			Xpos = 6;
			Ypos = 8;
		}
		else {
			Xpos = 3;
			Ypos = 8;
		}

	}
}


bool Bishop::isPossible(int prevInd, int nextInd, BaseF* map)
{
	// calculating previous positions
	int prevXpos = findXpos(prevInd);
	int prevYpos = findYpos(prevInd);

	if (prevXpos == Xpos && prevYpos == Ypos) {

		int nextXpos = findXpos(nextInd);
		int nextYpos = findYpos(nextInd);

		if ((prevXpos + prevYpos == nextXpos + nextYpos) ||
			(prevXpos - prevYpos == nextXpos - nextYpos)) {

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


bool Bishop::pathIsClear(int prevX, int prevY, int nextX, int nextY, BaseF* map)
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

	return isClear;
}
