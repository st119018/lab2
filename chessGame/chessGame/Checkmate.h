#pragma once
#include "Moves.h"
#include "BaseF.h"

class Checkmate : public Moves {
private:

	int blackKingXpos;
	int blackKingYpos;

	int whiteKingXpos;
	int whiteKingYpos;

	bool isAttacked_RookQueen(int Xpos, int Ypos, BaseF* map, bool isLowercase);

	bool isAttacked_BishopQueen(int Xpos, int Ypos, BaseF* map, bool isLowercase);

	bool isAttacked_Knight(int Xpos, int Ypos, BaseF* map, bool isLowercase);

	bool isAttacked_Pawn(int Xpos, int Ypos, BaseF* map, bool isLowercase);

	bool kingIsAttacked(BaseF* map, bool isLowercase);

public:

	Checkmate() {};

	Checkmate(int blackXpos, int blackYpos, int whiteXpos, int whiteYpos);

	bool checkIsSet(BaseF* map);

	void setBlackKingPos(int x, int y);

	void setWhiteKingPos(int x, int y);

};