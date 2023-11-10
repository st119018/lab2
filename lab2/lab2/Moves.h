#pragma once

class Moves {
	
public:

	int findXpos(int index, int mapWidth);

	int findYpos(int index, int mapWidth);

	int findFigureIndex(int Xpos, int Ypos);

	virtual ~Moves() {};
	
};

#pragma once