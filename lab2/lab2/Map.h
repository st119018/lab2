#pragma once
#include <iostream>

class MAP {
private:
	int mapSize = 111;
	int mapWidth = 11;
	int mapHeight = 10;
	char map[111] =
		" ABCDEFGH \n"
		"1rnbkqbnr1\n"
		"2pppppppp2\n"
		"3        3\n"
		"4        4\n"
		"5        5\n"
		"6        6\n"
		"7PPPPPPPP7\n"
		"8RNBKQBNR8\n"
		" ABCDEFGH \n";

	// R, r � Rook(�����)
    // N, n - kNight(����)
    // B, b - Bishop(����)
	// K, k - King(������)
	// Q, q - Queen(��������)
	// P, p - Pawn(�����)

public:
	void showMap();

	void changeMap(int prevInd, int nextInd);

	char* getMap();

	int getMapWidth();

	int getMapHeight();

	int getMapSize();

};

#pragma once
