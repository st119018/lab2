#include "Map.h"
#include "King.h"
#include "Bishop.h"
#include "Knight.h"
#include "LargePawn.h"
#include "Queen.h"
#include "Rook.h"
#include "SmallPawn.h"
#include "Checkmate.h"
#include "Castling.h"

#include <iostream>
#include <string>


bool isCorrectInput(char input[5]);

int main()
{
	setlocale(LC_ALL, "Russian");

	Map chessBoard{};
	King blackKing('b'), whiteKing('w');
	Queen blackQueen('b'), whiteQueen('w');
	Bishop blackRightBishop('b', "right"), blackLeftBishop('b', "left"), whiteRightBishop('w', "right"), whiteLeftBishop('w', "left");
	Knight blackRightKnight('b', "right"), blackLeftKnight('b', "left"), whiteRightKnight('w', "right"), whiteLeftKnight('w', "left");
	Rook blackRightRook('b', "right"), blackLeftRook('b', "left"), whiteRightRook('w', "right"), whiteLeftRook('w', "left");
	Checkmate checkmate(blackKing.getXpos(), blackKing.getYpos(), whiteKing.getXpos(), whiteKing.getYpos());
	Castling castling(blackKing.getXpos(), blackKing.getYpos(), whiteKing.getXpos(), whiteKing.getYpos());

	BaseF* blackPawns[8]{};
	BaseF* whitePawns[8]{};
	for (int i = 1; i <= 8; i++) {

		blackPawns[i - 1] = new SmallPawn(i);

		whitePawns[i - 1] = new LargePawn(i);
	}

	chessBoard.createMap();

	BaseF* board = chessBoard.getMap();

	std::cout << std::endl << "Player, make a move and enter 4 characters. Input example: а7а6 or A7A6.\n";
    std::cout << "The first 2 symbols determine the previous position of the figure, the second - the next position.\n";

	std::cout << "To perform castling, enter 'castling'.\n" << "To finish the game, enter 'end'.\n";

	bool isVictory = false;

	while (!isVictory) {
		chessBoard.showMap();

		if (checkmate.checkIsSet(board)) {
			std::cout << "\nThe check has been made! Castling cannot be performed.\n";
		}
		else {
			std::cout << "\nThe check has not been set.\n";
		}

		char input[5]{};
		std::string move;

		do {
			std::cout << "\nInput: ";
			std::cin >> move;

			for (auto symbol : move) {
				// converting letters to lowercase
				if (symbol <= 'Z' && symbol >= 'A') {
					symbol = symbol - 'A' + 'a';
				}
			}

			for (int i = 0; i < move.length() && i < 4; i++) {
				input[i] = move[i];
			}

		} while (move != "end" && move != "castling" && !isCorrectInput(input));

		// castling
		if (move == "castling" && !checkmate.checkIsSet(board)) {

			std::cout << "\nEnter first position of king, then position of rook that will be used.";
			std::cout << "\nTo cancel castling, enter 'end'.";

			std::string castlingMove;

			do {
				std::cout << "\nInput: ";
				std::cin >> castlingMove;

				for (auto symbol : castlingMove) {
					// converting letters to lowercase
					if (symbol <= 'Z' && symbol >= 'A') {
						symbol = symbol - 'A' + 'a';
					}
				}

				for (int i = 0; i < castlingMove.length() && i < 4; i++) {
					input[i] = castlingMove[i];
				}

			} while (castlingMove != "end" && !isCorrectInput(input));


			if (castlingMove != "end") { 

				if (castling.CastlingIsPossible(chessBoard, input)) {
					int kingBoardIndex = ((int)input[1] - 49) * 8 + ((int)input[0] - 97);
					int rookBoardIndex = ((int)input[3] - 49) * 8 + ((int)input[2] - 97);

					// changing positions of the figures
					int x = 0;
					if (rookBoardIndex > kingBoardIndex) {
						x = 1;  // king will move to the right
					}
					else {
						x = -1; // king will move to the left
					}

					if (board[kingBoardIndex].getTeam() == 'b') {
						int blackKingXpos = blackKing.getXpos();

						blackKing.setXpos(blackKingXpos + 2 * x);
						checkmate.setBlackKingPos(blackKing.getXpos(), blackKing.getYpos());

						if (board[rookBoardIndex].findXpos(rookBoardIndex) == 8) {
							blackRightRook.setXpos(5);
						}
						else {
							blackLeftRook.setXpos(3);
						}
					}
					else {

						int whiteKingXpos = whiteKing.getXpos();
						whiteKing.setXpos(whiteKingXpos + 2 * x);
						checkmate.setWhiteKingPos(whiteKing.getXpos(), whiteKing.getYpos());
						if (board[rookBoardIndex].findXpos(rookBoardIndex) == 8) {
							whiteRightRook.setXpos(5);
						}
						else {
							whiteLeftRook.setXpos(3);
						}
					}
					chessBoard.changeMap(kingBoardIndex, kingBoardIndex + 2 * x);
					chessBoard.changeMap(rookBoardIndex, kingBoardIndex + x);
				}
			}
		} // end of castling


		else if (move != "end" && move != "castling") {

			int prevBoardIndex = ((int)input[1] - 49) * 8 + ((int)input[0] - 97);
			int nextBoardIndex = ((int)input[3] - 49) * 8 + ((int)input[2] - 97);

			// checking if we do not attack our figures and address to a figure
			if (board[prevBoardIndex].isPossible(prevBoardIndex, nextBoardIndex, &board[0])) {

				if (blackKing.isPossible(prevBoardIndex, nextBoardIndex, board)) {

					chessBoard.changeMap(prevBoardIndex, nextBoardIndex);
					checkmate.setBlackKingPos(blackKing.getXpos(), blackKing.getYpos());
					castling.setBlackKingPos(blackKing.getXpos(), blackKing.getYpos());
					castling.addElement(prevBoardIndex);
				}

				else if (whiteKing.isPossible(prevBoardIndex, nextBoardIndex, board)) {

					chessBoard.changeMap(prevBoardIndex, nextBoardIndex);
					checkmate.setWhiteKingPos(whiteKing.getXpos(), whiteKing.getYpos());
					castling.setWhiteKingPos(whiteKing.getXpos(), whiteKing.getYpos());
					castling.addElement(prevBoardIndex);    // memorizing the moved figures for castling
				}

				else if (blackRightRook.isPossible(prevBoardIndex, nextBoardIndex, board) ||
					blackLeftRook.isPossible(prevBoardIndex, nextBoardIndex, board) ||
					whiteRightRook.isPossible(prevBoardIndex, nextBoardIndex, board) ||
					whiteLeftRook.isPossible(prevBoardIndex, nextBoardIndex, board)) 
				{
					chessBoard.changeMap(prevBoardIndex, nextBoardIndex);
					castling.addElement(prevBoardIndex);    // memorizing the moved figures for castling
				}

				else if (blackQueen.isPossible(prevBoardIndex, nextBoardIndex, board) ||
					whiteQueen.isPossible(prevBoardIndex, nextBoardIndex, board) ||
					blackRightBishop.isPossible(prevBoardIndex, nextBoardIndex, board) ||
					blackLeftBishop.isPossible(prevBoardIndex, nextBoardIndex, board) ||
					whiteRightBishop.isPossible(prevBoardIndex, nextBoardIndex, board) ||
					whiteLeftBishop.isPossible(prevBoardIndex, nextBoardIndex, board) ||
					blackRightKnight.isPossible(prevBoardIndex, nextBoardIndex, board) ||
					blackLeftKnight.isPossible(prevBoardIndex, nextBoardIndex, board) ||
					whiteRightKnight.isPossible(prevBoardIndex, nextBoardIndex, board) ||
					whiteLeftKnight.isPossible(prevBoardIndex, nextBoardIndex, board)) 
				{
					chessBoard.changeMap(prevBoardIndex, nextBoardIndex);
				}
				else if (board[prevBoardIndex].getPieceType() == 'p') 
				{
					for (int i = 0; i < 8; i++) {
						if (blackPawns[i]->isPossible(prevBoardIndex, nextBoardIndex, board) ||
							whitePawns[i]->isPossible(prevBoardIndex, nextBoardIndex, board)) {

							chessBoard.changeMap(prevBoardIndex, nextBoardIndex);
						}
					}
				}
				else {
					std::cout << "Impossible move\n";
				}

			}
			else {
				std::cout << "Impossible move\n";
			}
		}
		
		else {
			isVictory = true;
		}
	}


	for (int i = 0; i < 8; i++) {
		delete blackPawns[i];
		delete whitePawns[i];
	}
}


bool isCorrectInput(char input[5])
{
	if ((input[0] >= 'a' && input[0] <= 'h') && (input[2] >= 'a' && input[2] <= 'h') &&
		(input[1] >= '1' && input[1] <= '8') && (input[3] >= '1' && input[3] <= '8')) {
		return true;
	}
	else return false;

}


