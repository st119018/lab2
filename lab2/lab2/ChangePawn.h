#pragma once
#include "Moves.h"

#include <string>
#include <iostream>

class ChangePawn : public Moves {
public:

	char* findChessBoardPos(int index, int mapWidth, char* pos);

	void change(int index, int mapWidth, char* map);
	
};
