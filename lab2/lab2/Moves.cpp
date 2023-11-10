#include "Moves.h"


// finds the position on the chessboard, i.e. 1 <= x <= 8
int Moves::findXpos(int index, int mapWidth)
{
	int x = index % mapWidth;

	return x;
}

// finds the position on the chessboard, i.e. 1 <= y <= 8
int Moves::findYpos(int index, int mapWidth)
{
	int y = index / mapWidth;

	return y;
}

// finds the index
int Moves::findFigureIndex(int Xpos, int Ypos)
{
	int mapWidth = 11;
	int index = Ypos * mapWidth + Xpos;

	return index;
}
