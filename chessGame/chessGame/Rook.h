#pragma once
#include"BaseF.h"
#include <string>

class Rook : public BaseF {

public:

	Rook(char t, std::string side);

	virtual bool isPossible(int prevInd, int nextInd, BaseF* map);

	bool pathIsClear(int prevX, int prevY, int nextX, int nextY, BaseF* map);

};