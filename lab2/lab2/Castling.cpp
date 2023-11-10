#include "Castling.h"

bool Castling::isPossibleInput(char* input, char* map, int mapWidth)    // checks that player wants to move a king and a rook;                                                                         
{                                                                       // checks that figures wasn't moved yet
																		// checks if there is no figures between them
	// counting indexes of the king and rook
	kingIndex = ((int)input[1] - 49 + 1) * mapWidth + ((int)input[0] - 97 + 1); 
	rookIndex = ((int)input[3] - 49 + 1) * mapWidth + ((int)input[2] - 97 + 1);

	//checking that player wants to move a king and a rook
	if ((map[kingIndex] == 'k' && map[rookIndex] == 'r') || (map[kingIndex] == 'K' && map[rookIndex] == 'R')) {

		// checking that figures wasn't moved yet
		if (std::find(movedElements.begin(), movedElements.end(), kingIndex) == movedElements.end() &&
			std::find(movedElements.begin(), movedElements.end(), rookIndex) == movedElements.end() &&
		   (rookIndex == 12 || rookIndex == 19 || rookIndex == 89 || rookIndex == 96) &&
    	   (kingIndex == 15 || kingIndex == 92)) {

			// if player wants to move the right rook and there is no figures between them
			if (rookIndex > kingIndex && map[kingIndex + 1] == ' ' && map[kingIndex + 2] == ' ' && map[kingIndex + 3] == ' ') {

				return true;
			}
			// if player wants to move the left rook and there is no figures between them
			else if (rookIndex < kingIndex && map[kingIndex - 1] == ' ' && map[kingIndex - 2] == ' ') {

				return true;
			}
			else return false;
		}
		else return false;
	}
	else return false;

}


void Castling::addElement(int index) {

	if (index == 12 || index == 15 || index == 19 ||   //indexes of kings and rooks at the beginning of the game
		index == 89 || index == 92 || index == 96) {

		// if index wasn't found in elements (so the figure wasn't moved yet)
		if (std::find(movedElements.begin(), movedElements.end(), index) == movedElements.end()) { 
			movedElements.push_back(index);            // memorizing the index of moved figure

		}
	}
}


bool Castling::CastlingIsDone(Checkmate &checkmate, MAP &chessBoard, int mapWidth, int mapHeight)
{
	bool castlingIsDone = true;
	int x = 0;
	 
	if (rookIndex > kingIndex) {
	    x = 1;  // king will move to the right
	}
	else {
	    x = -1; // king will move to the left
	}
	 
	char* map = chessBoard.getMap();

	// checking if king is passing through the attacked fields
	chessBoard.changeMap(kingIndex, kingIndex + x);    // moving king
	checkmate.ChangeKingInd(kingIndex + x, &map[0]); // memorizing the current index of king
	 
	if (!checkmate.chessCheck(&map[0], mapWidth, mapHeight)) {      // determine whether the check is set
	 
		chessBoard.changeMap(kingIndex + x, kingIndex + 2 * x);  // moving king
	    checkmate.ChangeKingInd(kingIndex + 2 * x, &map[0]);   // memorizing the current index of king
	 
	    if (!checkmate.chessCheck(&map[0], mapWidth, mapHeight)) {  // determine whether the check is set
	 
			castlingIsDone = false;
			chessBoard.changeMap(rookIndex, kingIndex + x);      // moving rook
	    }
	    else {

			chessBoard.changeMap(kingIndex + 2 * x, kingIndex); // moving the king back
	        checkmate.ChangeKingInd(kingIndex, &map[0]);      // memorizing the current index of king
			castlingIsDone = true;
	    }
	}
	else {

		chessBoard.changeMap(kingIndex + x, kingIndex);  // moving the king back
	    checkmate.ChangeKingInd(kingIndex, &map[0]);   // memorizing the current index of king
		castlingIsDone = true;
	}



	return castlingIsDone;
}

