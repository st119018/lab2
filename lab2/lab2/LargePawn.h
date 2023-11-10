#pragma once
#include "Moves.h"


class LargePawn : public Moves {

public:

	bool isPossibleForLargePawn(int prevInd, int nextInd, int mapWidth, char* map);

};