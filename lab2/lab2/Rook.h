#pragma once
#include "Moves.h"

class Rook : public Moves {
private:
	int LeftSmallRookInd;
	int RightSmallRookInd;
	int LeftLargeRookInd;
	int RightLargeRookInd;

	// any of 16 pawns can become a rook
	int SmallRook1 = 0;
	int SmallRook2 = 0;
	int SmallRook3 = 0;
	int SmallRook4 = 0;
	int SmallRook5 = 0;
	int SmallRook6 = 0;
	int SmallRook7 = 0;
	int SmallRook8 = 0;

	int LargeRook1 = 0;
	int LargeRook2 = 0;
	int LargeRook3 = 0;
	int LargeRook4 = 0;
	int LargeRook5 = 0;
	int LargeRook6 = 0;
	int LargeRook7 = 0;
	int LargeRook8 = 0;

public:

	Rook(int LeftSmallIndex, int RightSmallIndex, int LeftLargeIndex, int RightLargeIndex);

	bool isPossibleForRook(int prevInd, int nextInd, int mapWidth, int mapHeight, char* map);

	bool pathIsClear(int prevX, int prevY, int nextX, int nextY, char* map);

	void addSmallInd(int index);

	void addLargeInd(int index);

};
