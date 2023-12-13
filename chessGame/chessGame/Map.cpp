#include "Map.h"

void Map::createMap()
{
	for (int i = 0; i < 8; i++) {
		for (int j = 0; j < 8; j++) {

			map[i * 8 + j].setXpos(j + 1);
			map[i * 8 + j].setYpos(i + 1);

			if ((i + 1) <= 2) {
				map[i * 8 + j].setTeam('b');
			}
			else if ((i + 1) >= 3 && (i + 1) <= 6) {
				map[i * 8 + j].setTeam('n');
			}
			else {
				map[i * 8 + j].setTeam('w');
			}

			if ((j + 1 == 1 || j + 1 == 8) && (i + 1 == 1 || i + 1 == 8)) {
				map[i * 8 + j].setPieceType('r');
			}
			else if ((j + 1 == 2 || j + 1 == 7) && (i + 1 == 1 || i + 1 == 8)) {
				map[i * 8 + j].setPieceType('n');
			}
			else if ((j + 1 == 3 || j + 1 == 6) && (i + 1 == 1 || i + 1 == 8)) {
				map[i * 8 + j].setPieceType('b');
			}
			else if (j + 1 == 4  && (i + 1 == 1 || i + 1 == 8)) {
				map[i * 8 + j].setPieceType('k');
			}
			else if (j + 1 == 5 && (i + 1 == 1 || i + 1 == 8)) {
				map[i * 8 + j].setPieceType('q');
			}
			else if (i + 1 == 2 || i + 1 == 7) {
				map[i * 8 + j].setPieceType('p');
			}
			else {
				map[i * 8 + j].setPieceType(' ');
			}
		}
	}
}

void Map::showMap()
{
	std::cout << "\n   A B C D E F G H \n";
	for (int i = 0; i < 8; i++) {
		std::cout << " " << i + 1;
		for (int j = 0; j < 8; j++) {

			int index = i * 8 + j;
			if (map[index].getTeam() == 'b') {
				std::cout <<  " " << map[index].getPieceType();
			}
			else if (map[index].getTeam() == 'n') {
				std::cout << "  ";
			}
			else {
				char temp = map[index].getPieceType() - 'a' + 'A';
				std::cout << " " << temp;
			}
			
		}
		std::cout << " " << i + 1 << std::endl;
	}
	std::cout << "   A B C D E F G H \n";

}

BaseF* Map::getMap()
{
	return &map[0];
}

void Map::changeMap(int prevInd, int nextInd)
{
	char team = map[prevInd].getTeam();
	map[nextInd].setTeam(team);

	char piece = map[prevInd].getPieceType();
	map[nextInd].setPieceType(piece);

	map[prevInd].setTeam('n');
	map[prevInd].setPieceType(' ');
}