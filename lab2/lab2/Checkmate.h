#pragma once
#include "Moves.h"

class Checkmate : public Moves {
private:

	// indexes of the kings in the beginning of the game
	int smallKingMapIndex = 15;     // indexes will change during the game
	int largeKingMapIndex = 92;


public:

	void ChangeKingInd(int index, char* map);

	bool isAttacked_RookQueen(int Xpos, int Ypos, int mapWidth, int mapHeight, char* map, bool isLowercase);

	bool isAttacked_BishopQueen(int Xpos, int Ypos, int mapWidth, int mapHeight, char* map, bool isLowercase);

	bool isAttacked_Knight(int Xpos, int Ypos, int mapWidth, int mapHeight, char* map, bool isLowercase);

	bool isAttacked_Pawn(int Xpos, int Ypos, char* map, bool isLowercase);

	bool kingIsAttacked(int kingIndex, int mapWidth, int mapHeight, char* map, bool isLowercase);

	bool chessCheck(char* map, int mapWidth, int mapHeight);

};


