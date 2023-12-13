#pragma once
#include "BaseF.h"
#include <vector>
#include <iostream>

class Map {
private:

	BaseF map[64];

public:

	void createMap();

	void showMap();

	BaseF* getMap();

	void changeMap(int prevInd, int nextInd);

};