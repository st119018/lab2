#pragma once
#include "Moves.h"

class King: public Moves {
private:
	int SmallKingInd;
	int LargeKingInd;

public:

	King(int SmallIndex, int LargeIndex);

	bool isPossibleForKing(int nextInd, int mapWidth);

};