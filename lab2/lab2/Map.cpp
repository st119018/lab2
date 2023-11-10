#pragma once
#include "Map.h"

void MAP::showMap()
{
	for (int i = 0; i < mapSize; i++) {
		std::cout << " " << map[i];
	};
}

void MAP::changeMap(int prevInd, int nextInd)
{
	map[nextInd] = map[prevInd];
	map[prevInd] = ' ';
}

char* MAP::getMap()
{
	return &map[0];
}

int MAP::getMapWidth()
{
	return mapWidth;
}

int MAP::getMapHeight()
{
	return mapHeight;
}

int MAP::getMapSize()
{
	return mapSize;
}

#pragma once
