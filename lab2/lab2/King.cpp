#pragma once
#include "King.h"

// determines if king can move
bool King::isPossibleForKing(int prevInd, int nextInd, int mapWidth)
{

	for (int x = -1; x <= 1; x++) {
		for (int y = -1; y <= 1; y++) {
			int Index = prevInd + x * mapWidth + y;
			if (nextInd == Index) {
				return true;
			}
		}
	}
	return false;
}
