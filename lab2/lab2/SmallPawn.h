#pragma once
#include "Moves.h"


class SmallPawn : public Moves {

public:

	bool isPossibleForSmallPawn(int prevInd, int nextInd, int mapWidth, char* map);

};