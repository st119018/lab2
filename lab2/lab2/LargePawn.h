#pragma once
#include "Moves.h"


class LargePawn : public Moves {
private:
	int Pawn1;
	int Pawn2;
	int Pawn3;
	int Pawn4;
	int Pawn5;
	int Pawn6;
	int Pawn7;
	int Pawn8;

public:

	LargePawn(int Ind1, int Ind2, int Ind3, int Ind4, int Ind5, int Ind6, int Ind7, int Ind8);

	bool isPossibleForLargePawn(int prevInd, int nextInd, int mapWidth, char* map);

};