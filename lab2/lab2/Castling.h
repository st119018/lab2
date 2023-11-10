#pragma once
#include "Moves.h"
#include "Checkmate.h"
#include "Map.h"

#include <vector>
#include <algorithm>


class Castling : public Moves {
private:

	int rookIndex = 0;
	int kingIndex = 0;
	std::vector <int> movedElements;   // vector of kings and rooks that have been moved at least once

public:

	bool isPossibleInput(char* input, char* map, int mapWidth);

	void addElement(int index);

	bool CastlingIsDone(Checkmate &checkmate, MAP &chessBoard, int mapWidth, int mapHeight);

 };
#pragma once

