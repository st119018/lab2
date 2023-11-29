#pragma once
#include "Moves.h"

class Bishop : public Moves {
private:
	int LeftSmallBishopInd;
	int RightSmallBishopInd;
	int LeftLargeBishopInd;
	int RightLargeBishopInd;

	// any of 16 pawns can become a bishop
	int SmallBishop1 = 0;
	int SmallBishop2 = 0;
	int SmallBishop3 = 0;
	int SmallBishop4 = 0;
	int SmallBishop5 = 0;
	int SmallBishop6 = 0;
	int SmallBishop7 = 0;
	int SmallBishop8 = 0;

	int LargeBishop1 = 0;
	int LargeBishop2 = 0;
	int LargeBishop3 = 0;
	int LargeBishop4 = 0;
	int LargeBishop5 = 0;
	int LargeBishop6 = 0;
	int LargeBishop7 = 0;
	int LargeBishop8 = 0;


public:

	Bishop(int LeftSmallIndex, int RightSmallIndex, int LeftLargeIndex, int RightLargeIndex);

	bool pathIsClear(int prevX, int prevY, int nextX, int nextY, char* map);

	bool isPossibleForBishop(int prevInd, int nextInd, int mapWidth, int mapHeight, char* map);

	void addSmallInd(int index);

	void addLargeInd(int index);

};
