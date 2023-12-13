#pragma once
#include "BaseF.h"

class King: public BaseF {

public:

	King(char t);

	virtual bool isPossible(int prevInd, int nextInd, BaseF* map);

	int getXpos();

	int getYpos();

};