#pragma once
#include "Moves.h"

class Queen : public Moves {

public:

	bool pathIsClear(int prevX, int prevY, int nextX, int nextY, char* map);

	bool isPossibleForQueen(int prevInd, int nextInd, int mapWidth, int mapHeight, char* map);

};