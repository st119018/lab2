#include "Castling.h"

Castling::Castling(int blackXpos, int blackYpos, int whiteXpos, int whiteYpos)
{
	setBlackKingPos(blackXpos, blackYpos);
	setWhiteKingPos(whiteXpos, whiteYpos);
}


void Castling::addElement(int index)
{
	if (index == 0 || index == 3 || index == 7 ||   //indexes of kings and rooks at the beginning of the game
		index == 56 || index == 59 || index == 63) {

		// if index wasn't found in elements (so the figure wasn't moved yet)
		if (std::find(movedElements.begin(), movedElements.end(), index) == movedElements.end()) {
			movedElements.push_back(index);            // memorizing the index of moved figure

		}
	}
}

bool Castling::pathIsClear(int rookIndex, int kingIndex, BaseF* map)
{

	//checking that player wants to move the king and rook
	if (map[kingIndex].getPieceType() == 'k' && map[rookIndex].getPieceType() == 'r' && map[kingIndex].getTeam() == map[rookIndex].getTeam()) {

		// checking that figures wasn't moved yet
		if (std::find(movedElements.begin(), movedElements.end(), kingIndex) == movedElements.end() &&
			std::find(movedElements.begin(), movedElements.end(), rookIndex) == movedElements.end() &&
			(kingIndex == 3 || kingIndex == 59) && (rookIndex == 0 || rookIndex == 7 || rookIndex == 56 || rookIndex == 63)) {
			
			// if player wants to move the right rook and there is no figures between them
			if (rookIndex > kingIndex && map[kingIndex + 1].getTeam() == 'n' && map[kingIndex + 2].getTeam() == 'n' && map[kingIndex + 3].getTeam() == 'n') {
				return true;

			}
			// if player wants to move the left rook and there is no figures between them
			else if (rookIndex < kingIndex && map[kingIndex - 1].getTeam() == 'n' && map[kingIndex - 2].getTeam() == 'n') {
				return true;

			}
			else return false;
		}
		else return false;
	}
	else return false;
}

bool Castling::CastlingIsPossible(Map &chessBoard, char* input)
{
	bool isPossible = false;

	int kingIndex = ((int)input[1] - 49) * 8 + ((int)input[0] - 97);
	int rookIndex = ((int)input[3] - 49) * 8 + ((int)input[2] - 97);

	BaseF *map = chessBoard.getMap();

	if (pathIsClear(rookIndex, kingIndex, map)) {

		int x = 0;
		if (rookIndex > kingIndex) {
			x = 1;  // king will move to the right
		}
		else {
			x = -1; // king will move to the left
		}

		// checking if king is passing through the attacked fields
		chessBoard.changeMap(kingIndex, kingIndex + x);   // moving king

		// memorizing the current positions of the kings
		if (kingIndex == 3) {
			setBlackKingPos(findXpos(kingIndex + x), findYpos(kingIndex + x));
		}
		else {
			setWhiteKingPos(findXpos(kingIndex + x), findYpos(kingIndex + x));
		}

		if (!checkIsSet(map)) {      // determine whether the check is set

			chessBoard.changeMap(kingIndex + x, kingIndex + 2 * x);  // moving king
			// memorizing the current positions of the kings
			if (kingIndex == 3) {
				setBlackKingPos(findXpos(kingIndex + 2 * x), findYpos(kingIndex + 2 * x));
			}
			else {
				setWhiteKingPos(findXpos(kingIndex + 2 * x), findYpos(kingIndex + 2 * x));
			}

			if (!checkIsSet(map)) {   // determine whether the check is set

				chessBoard.changeMap(kingIndex + 2 * x, kingIndex);  // return the king
				isPossible = true;
			}
			else {

				isPossible = false;
				chessBoard.changeMap(kingIndex + 2 * x, kingIndex);
				if (kingIndex == 3) {
					setBlackKingPos(findXpos(kingIndex), findYpos(kingIndex));
				}
				else {
					setWhiteKingPos(findXpos(kingIndex), findYpos(kingIndex));
				}
			}
		}
		else {
			isPossible = false;
			chessBoard.changeMap(kingIndex + x, kingIndex);
			if (kingIndex == 3) {
				setBlackKingPos(findXpos(kingIndex), findYpos(kingIndex));
			}
			else {
				setWhiteKingPos(findXpos(kingIndex), findYpos(kingIndex));
			}
		}
	}

	return isPossible;
}
