#pragma once
#include <vector>
#include"Moves.h"

class BaseF: public Moves {
protected:

	int Xpos;
	int Ypos;
	char team; // w - white(large figures), b - black(small figures), n - nothing(empty)
	char pieceType; // k, ' ', q, r, b, n, p 

public:

	virtual bool isPossible(int prevInd, int nextInd, BaseF* map);

	virtual ~BaseF() {};

	void setXpos(int x);

	void setYpos(int y);

	void setTeam(char t);

	char getTeam();

	void setPieceType(char p);

	char getPieceType();
};