#pragma once
#include "Moves.h"

class King: public Moves {
	
public:
	bool isPossibleForKing(int prevInd, int nextInd, int mapWidth);
	
};