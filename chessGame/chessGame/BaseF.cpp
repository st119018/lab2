#include "BaseF.h"

bool BaseF::isPossible(int prevInd, int nextInd, BaseF* map)
{
	//checking: we do not attack our figures, address to nothing
	if (map[prevInd].team != 'n') {
		if (map[nextInd].team == 'n') {
			return true;
		}
		else if (map[prevInd].team == 'w'&& map[nextInd].team == 'b') {
			return true;
		}
		else if (map[prevInd].team == 'b' && map[nextInd].team == 'w') {
			return true;
		}
	}

	return false;
}

void BaseF::setXpos(int x)
{
	Xpos = x;
}

void BaseF::setYpos(int y)
{
	Ypos = y;
}

void BaseF::setTeam(char t)
{
	team = t;
}

char BaseF::getTeam()
{
	return team;
}

void BaseF::setPieceType(char p)
{
	pieceType = p;
}

char BaseF::getPieceType()
{
	return pieceType;
}
