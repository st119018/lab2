#include "Map.h"
#include "CheckInput.h"
#include "Moves.h"
#include "King.h"
#include "Rook.h"
#include "Bishop.h"
#include "Knight.h"
#include "Queen.h"
#include "SmallPawn.h"
#include "LargePawn.h"
#include "Checkmate.h"
#include "Castling.h"
#include "ChangePawn.h"

#include <string>



//castling can be performed if:
//    1)the king and rook weren't moved yet
//    2)there is no figures between them
//    3)the check is not set
//    4)king is not passing through the attacked fields


int main()
{
    setlocale(LC_ALL, "Russian");
    MAP chessBoard;
    CheckingInput inputCheck;
    King king;
    Rook rook;
    Bishop bishop;
    Knight knight; 
    Queen queen;
    SmallPawn smallPawn;
    LargePawn largePawn;
    Checkmate checkmate;  // checkmate, check - 'шах'
    Castling castling;    // castling - 'рокировка'
    ChangePawn changePawn;

    char* board = chessBoard.getMap();

    int boardSize = chessBoard.getMapSize();

    int boardWidth = chessBoard.getMapWidth();
    int boardHeight = chessBoard.getMapHeight();

    bool isVictory = false;

    while (!isVictory) {
        system("cls"); // cleaning the console

        std::cout << "        CHESS\n\n";

        chessBoard.showMap(); // display the current position of the figures

        std::cout << std::endl << "Player, make a move and enter 4 characters. Input example: а7а6 or A7A6.\n"
                  << "The first 2 symbols determine the previous position of the figure, the second - the next position.\n";

        std::cout << "To performe castling, enter 'castling'.\n" << "To finish the game, enter 'end'.\n";

        if (checkmate.chessCheck(&board[0], boardWidth, boardHeight)) {
            std::cout << "\nThe check has been made! Castling cannot be performed.\n";
        }
        else {
            std::cout << "\nThe check has not been set.\n";
        }

        //
        std::string move;
        std::string move2;
        char input[5] = "0000";

        // checking what player enters
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

        } while (!inputCheck.isCorrectInput(&input[0], &board[0]) && move != "end" && move != "castling" );


        if (move == "end") {
            isVictory = true;
        }

        // castling
        else if (move == "castling" && !checkmate.chessCheck(&board[0], boardWidth, boardHeight)) { 

            std::cout << "\nEnter first position of king, then position of rook that will be used.";
            std::cout << "\nTo cancel castling, enter 'end'.";

            // checking what positions player enters
            do {
                std::cout << "\nInput: ";
                std::cin >> move2;

                for (auto symbol : move2) {
                    // converting letters to lowercase
                    if (symbol <= 'Z' && symbol >= 'A') {
                        symbol = symbol - 'A' + 'a';
                    }
                }

                for (int i = 0; i < move2.length() && i < 4; i++) {
                    input[i] = move2[i];
                }

            } while (!castling.isPossibleInput(&input[0], &board[0], boardWidth) && move2 != "end");

            if (castling.isPossibleInput(&input[0], &board[0], boardWidth) && move2 != "end") {

                int kingIndex = ((int)input[1] - 49 + 1) * boardWidth + ((int)input[0] - 97 + 1);
                int rookIndex = ((int)input[3] - 49 + 1) * boardWidth + ((int)input[2] - 97 + 1);

                if (castling.CastlingIsDone(checkmate, chessBoard, boardWidth, boardHeight)) {
                    std::cout << "Castling was done.\n";
                }
                else {
                    std::cout << "Castling was not done.\n";
                }
            }

            else {
                std::cout<< "Castling was not done.\n";
            }
        } // end of castling
        

        // checking the input
        else if (move != "end" || move2 == "end") {
            for (int i = 0; i < move.length() && i < 4; i++) {
                input[i] = move[i];
            }

            while (!inputCheck.isCorrectInput(&input[0], &board[0])) {

                std::cout << "\nInput: ";
                std::cin >> move;
                for (int i = 0; i < move.length() && i < 4; i++) {
                    input[i] = move[i];
                }
            }
        }



        // we change map if we haven't finished the game and did not perform castling
        if (!isVictory && move != "castling") {

            // calculating the indexes of the previous and next positions of the figure
            int prevBoardIndex = ((int)input[1] - 49 + 1) * boardWidth + ((int)input[0] - 97 + 1);
            int nextBoardIndex = ((int)input[3] - 49 + 1) * boardWidth + ((int)input[2] - 97 + 1);
            
            // move the figure
            if (board[prevBoardIndex] == 'k' || board[prevBoardIndex] == 'K') {       // moving the king
                if (king.isPossibleForKing(prevBoardIndex, nextBoardIndex, boardWidth)) {
                    chessBoard.changeMap(prevBoardIndex, nextBoardIndex);        // change map
                    checkmate.ChangeKingInd(nextBoardIndex, &board[0]);          // memorizing the current index of king
                    castling.addElement(prevBoardIndex);                         // memorizing the moved figures for castling
                }
            }
            else if (board[prevBoardIndex] == 'r' || board[prevBoardIndex] == 'R') {  // moving the rook
                if (rook.isPossibleForRook(prevBoardIndex, nextBoardIndex, boardWidth, boardHeight, &board[0])) {
                    chessBoard.changeMap(prevBoardIndex, nextBoardIndex);
                    castling.addElement(prevBoardIndex);                         // memorizing the moved figures for castling
                }
            }
            else if (board[prevBoardIndex] == 'b' || board[prevBoardIndex] == 'B') {  // moving the bishop
                if (bishop.isPossibleForBishop(prevBoardIndex, nextBoardIndex, boardWidth, boardHeight, &board[0])) {
                    chessBoard.changeMap(prevBoardIndex, nextBoardIndex);
                }
            }
            else if (board[prevBoardIndex] == 'n' || board[prevBoardIndex] == 'N') {  // moving the knight
                if (knight.isPossibleForKnight(prevBoardIndex, nextBoardIndex, boardWidth, &board[0])) {
                    chessBoard.changeMap(prevBoardIndex, nextBoardIndex);
                }
            }
            else if (board[prevBoardIndex] == 'q' || board[prevBoardIndex] == 'Q') {  // moving the queen
                if (queen.isPossibleForQueen(prevBoardIndex, nextBoardIndex, boardWidth, boardHeight, &board[0])) {
                    chessBoard.changeMap(prevBoardIndex, nextBoardIndex);
                }
            }
            else if (board[prevBoardIndex] == 'p') {                                  // moving the small pawn
                if (smallPawn.isPossibleForSmallPawn(prevBoardIndex, nextBoardIndex, boardWidth, &board[0])) {
                    chessBoard.changeMap(prevBoardIndex, nextBoardIndex);
                    changePawn.change(nextBoardIndex, boardWidth, &board[0]);         // changing pawn to another figure if it
                }                                                                     // has reached the opposite edge of the board
            }
            else if (board[prevBoardIndex] == 'P') {                                  // moving the large pawn
                if (largePawn.isPossibleForLargePawn(prevBoardIndex, nextBoardIndex, boardWidth, &board[0])) {
                    chessBoard.changeMap(prevBoardIndex, nextBoardIndex);
                    changePawn.change(nextBoardIndex, boardWidth, &board[0]);         // changing pawn to another figure if it
                }                                                                     // has reached the opposite edge of the board
            }
            else {
                std::cout << "\nImpossible move.";
            }
        }
    }

    return 0;
};