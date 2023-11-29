#pragma once
#include "Moves.h"

class Knight : public Moves {
private:

	int LeftSmallKnightInd;
	int RightSmallKnightInd;
	int LeftLargeKnightInd;
	int RightLargeKnightInd;

	// any of 16 pawns can become a queen
	int SmallKnight1 = 0;
	int SmallKnight2 = 0;
	int SmallKnight3 = 0;
	int SmallKnight4 = 0;
	int SmallKnight5 = 0;
	int SmallKnight6 = 0;
	int SmallKnight7 = 0;
	int SmallKnight8 = 0;

	int LargeKnight1 = 0;
	int LargeKnight2 = 0;
	int LargeKnight3 = 0;
	int LargeKnight4 = 0;
	int LargeKnight5 = 0;
	int LargeKnight6 = 0;
	int LargeKnight7 = 0;
	int LargeKnight8 = 0;

public:

	Knight(int LeftSmallIndex, int RightSmallIndex, int LeftLargeIndex, int RightLargeIndex);

	bool isPossibleForKnight(int prevInd, int nextInd, int mapWidth, char* map);

	void addSmallInd(int index);

	void addLargeInd(int index);

};