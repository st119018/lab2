#pragma once
#include "Moves.h"
#include "Bishop.h"
#include "Knight.h"
#include "Queen.h"
#include "Rook.h"

#include <string>
#include <iostream>

class ChangePawn : public Moves {
private:

	char Figure = 0;

public:

	void updateIndex(int index, Queen &queen, Rook &rook, Knight &knight, Bishop &bishop);

	char* findChessBoardPos(int index, int mapWidth, char* pos);

	bool changed(int index, int mapWidth, char* map);
	
};
