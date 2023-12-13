#include "Moves.h"

int Moves::findFigureIndex(int x, int y)
{
	return (y - 1) * 8 + x;
}

int Moves::findXpos(int index)
{
	return index % 8 + 1;
}

int Moves::findYpos(int index)
{
	return index / 8 + 1;
}
