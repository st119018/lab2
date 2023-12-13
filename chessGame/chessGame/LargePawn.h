#pragma once
#include "BaseF.h"

class LargePawn : public BaseF {

public:

	LargePawn(int column);

	virtual bool isPossible(int prevInd, int nextInd, BaseF* map);

};