#include "Knight.h"

Knight::Knight(char team, std::string side)
{
	pieceType = 'n';
	this->team = team;

	for (auto c : side) {
		if (c >= 'A' && c <= 'Z') {
			c = c - 'A' + 'a';
		}
	}

	if (team == 'b') {
		if (side == "right") {
			Xpos = 7;
			Ypos = 1;
		}
		else {
			Xpos = 2;
			Ypos = 1;
		}
	} 
	else {
		if (side == "right") {
			Xpos = 7;
			Ypos = 8;
		}
		else {
			Xpos = 2;
			Ypos = 8;
		}

	}
}


bool Knight::isPossible(int prevInd, int nextInd, BaseF* map) 
{
	// calculating previous and next positions
	int prevXpos = findXpos(prevInd);
	int prevYpos = findYpos(prevInd);
	int nextXpos = findXpos(nextInd);
	int nextYpos = findYpos(nextInd);

	if (prevXpos == Xpos && prevYpos == Ypos) {
		// shift by 1 position on the X axis and 2 positions on the Y axis
		if (nextXpos == prevXpos + 1 || nextXpos == prevXpos - 1) {
			if (nextYpos == prevYpos + 2 || nextYpos == prevYpos - 2) {

				Xpos = nextXpos;
				Ypos = nextYpos;

				return true;
			}
		}
		// shift by 2 positions on the X axis and 1 position on the Y axis
		else if (nextXpos == prevXpos + 2 || nextXpos == prevXpos - 2) {
			if (nextYpos == prevYpos + 1 || nextYpos == prevYpos - 1) {

				Xpos = nextXpos;
				Ypos = nextYpos;

				return true;
			}
		}
	}

	return false;
}
