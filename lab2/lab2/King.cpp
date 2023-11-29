#include "King.h"

King::King(int SmallIndex, int LargeIndex)
{
	SmallKingInd = SmallIndex;
	LargeKingInd = LargeIndex;
}

// determines if king can move
bool King::isPossibleForKing(int nextInd, int mapWidth)
{

	for (int x = -1; x <= 1; x++) {
		for (int y = -1; y <= 1; y++) {

			int newSmallIndex = SmallKingInd + x * mapWidth + y;
			int newLargeIndex = LargeKingInd + x * mapWidth + y;

			if (nextInd == newSmallIndex) {
				SmallKingInd = nextInd;
				return true;
			}
			else if (nextInd == newLargeIndex){
				LargeKingInd = nextInd;
				return true;
			}
		}
	}
	return false;
}
