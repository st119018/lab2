#pragma once
#include "Checkmate.h"
#include "Map.h"


class Castling : public Checkmate {
private:

	std::vector <int> movedElements;   // vector of kings and rooks that have been moved at least once

	bool pathIsClear(int rookIndex, int kingIndex, BaseF* map);

public:

	Castling(int blackXpos, int blackYpos, int whiteXpos, int whiteYpos);

	void addElement(int index);

	bool CastlingIsPossible(Map &chessBoard, char* input);
};