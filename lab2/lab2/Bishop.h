#pragma once
#include "Moves.h"

class Bishop : public Moves {

public:

	bool pathIsClear(int prevX, int prevY, int nextX, int nextY, char* map);

	bool isPossibleForBishop(int prevInd, int nextInd, int mapWidth, int mapHeight, char* map);


};
