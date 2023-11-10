#pragma once
#include "Moves.h"

class Rook : public Moves {

public:

	bool isPossibleForRook(int prevInd, int nextInd, int mapWidth, int mapHeight, char* map);

	bool pathIsClear(int prevX, int prevY, int nextX, int nextY, char* map);

};
