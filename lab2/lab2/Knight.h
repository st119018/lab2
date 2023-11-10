#pragma once
#include "Moves.h"

class Knight : public Moves {

public:
	bool isPossibleForKnight(int prevInd, int nextInd, int mapWidth, char* map);

};