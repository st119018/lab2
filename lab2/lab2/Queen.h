#pragma once
#include "Moves.h"

class Queen : public Moves {
private:
	int SmallQueenInd;
	int LargeQueenInd;

	// any of 16 pawns can become a queen
	int SmallQueen1 = 0;
	int SmallQueen2 = 0;
	int SmallQueen3 = 0;
	int SmallQueen4 = 0;
	int SmallQueen5 = 0;
	int SmallQueen6 = 0;
	int SmallQueen7 = 0;
	int SmallQueen8 = 0;

	int LargeQueen1 = 0;
	int LargeQueen2 = 0;
	int LargeQueen3 = 0;
	int LargeQueen4 = 0;
	int LargeQueen5 = 0;
	int LargeQueen6 = 0;
	int LargeQueen7 = 0;
	int LargeQueen8 = 0;

public:

	Queen(int SmallIndex, int LargeIndex);

	bool pathIsClear(int prevX, int prevY, int nextX, int nextY, char* map);

	bool isPossibleForQueen(int prevInd, int nextInd, int mapWidth, int mapHeight, char* map);

	void addSmallInd(int index);

	void addLargeInd(int index);

};