#pragma once
#include"BaseF.h"

class Queen : public BaseF {

public:

	Queen(char t);

	virtual bool isPossible(int prevInd, int nextInd, BaseF* map);

	bool pathIsClear(int prevX, int prevY, int nextX, int nextY, BaseF* map);

};