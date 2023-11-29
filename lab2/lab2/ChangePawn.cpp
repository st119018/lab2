#include "ChangePawn.h"

void ChangePawn::updateIndex(int index, Queen& queen, Rook& rook, Knight& knight, Bishop& bishop)
{
	// adding the new index to a relevant class
	if (Figure == 'q') {
		queen.addSmallInd(index);
	}
	else if (Figure == 'r') {
		rook.addSmallInd(index);
	}
	else if (Figure == 'n') {
		knight.addSmallInd(index);
	}
	else if (Figure == 'b') {
		bishop.addSmallInd(index);
	}
	else if (Figure == 'Q') {
		queen.addLargeInd(index);
	}
	else if (Figure == 'R') {
		rook.addLargeInd(index);
	}
	else if (Figure == 'N') {
		knight.addLargeInd(index);
	}
	else if (Figure == 'B') {
		bishop.addLargeInd(index);
	}
}

char* ChangePawn::findChessBoardPos(int index, int mapWidth, char* pos)
{

	int Xpos = findXpos(index, mapWidth);
	int Ypos = findYpos(index, mapWidth);

	pos[0] = 'A' + Xpos - 1;
	pos[1] = '1' + Ypos - 1;

	return &pos[0]; // returns position (A8, G8, B1, etc)
}

bool ChangePawn::changed(int index, int mapWidth, char* map)
{

	int Ypos = findYpos(index, mapWidth);
	char boardPos[3]{};
	char* pos = findChessBoardPos(index, mapWidth, &boardPos[0]);

	// if a small pawn has reached the opposite edge of the chess board
	if (Ypos == 8 && map[index] == 'p') {

		std::cout << "The pawn on " << pos[0] << pos[1] << " has reached the opposite edge.\n";
		std::cout << "A pawn can become a queen, a rook, a knight or a bishop. Choose what figure it will become.";

		std::string strFigure;
		//char charFigure = 0;

		do {
			std::cout << "\nEnter the symbol of this figure: ";
			std::cin >> strFigure;
			Figure = strFigure[0];
		} while (strFigure.length() != 1 || (Figure != 'q' && Figure != 'r' && Figure != 'n' && Figure != 'b'));

		map[index] = Figure; // changing pawn
		return true;
	}
	// if a large pawn has reached the opposite edge of the chess board
	else if (Ypos == 1 && map[index] == 'P') {

		std::cout << "The pawn on " << pos[0] << pos[1] << " has reached the opposite edge.\n";
		std::cout << "The pawn can become a queen, a rook, a knight or a bishop. Choose what figure it will become.";

		std::string strFigure;
		//char charFigure = 0;

		do {
			std::cout << "\nEnter the symbol of this figure: ";
			std::cin >> strFigure;
			Figure = strFigure[0];
		} while (strFigure.length() != 1 || (Figure != 'Q' && Figure != 'R' && Figure != 'N' && Figure != 'B'));

		map[index] = Figure; // changing pawn
		return true;
	}
	else return false;
}


