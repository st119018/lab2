#pragma once
#include "BaseF.h"

class SmallPawn : public BaseF {

public:

	SmallPawn(int column);

	virtual bool isPossible(int prevInd, int nextInd, BaseF* map);

};