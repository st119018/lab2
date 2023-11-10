#include "Checkmate.h"

// memorizes the current index of kings
void Checkmate::ChangeKingInd(int index, char* map)
{
    if (map[index] == 'k') {
        smallKingMapIndex = index;

    }
    else if (map[index] == 'K') {
        largeKingMapIndex = index;

    }

}

bool Checkmate::isAttacked_RookQueen(int Xpos, int Ypos, int mapWidth, int mapHeight, char* map, bool isLowercase)
{
    bool isAttacked = false;
    int i = Xpos;   // column number
    int j = Ypos;   // row number


    if (isLowercase) { // small king
        // horizontal

        i = Xpos + 1;
        j = Ypos;
        // checking if king is attacked from the right
        while (i <= mapWidth - 3 && map[findFigureIndex(i, j)] <= 'Z') {

            if (map[findFigureIndex(i, j)] == 'Q' || map[findFigureIndex(i, j)] == 'R') {
                isAttacked = true;
            }
            i++;
        }

        i = Xpos - 1;
       // checking if king is attacked from the left
        while (i >= 1 && map[findFigureIndex(i, j)] <= 'Z') {

            if (map[findFigureIndex(i, j)] == 'Q' || map[findFigureIndex(i, j)] == 'R') {
                isAttacked = true;
            }
            i--;
        }

        // vertical

        i = Xpos;
        j = Ypos + 1;
        // checking if king is attacked from below
        while (j <= mapHeight - 2 && map[findFigureIndex(i, j)] <= 'Z') { 

            if (map[findFigureIndex(i, j)] == 'Q' || map[findFigureIndex(i, j)] == 'R') {
                isAttacked = true;
            }
            j++;
        }

        i = Xpos;
        j = Ypos - 1;
        // checking if king is attacked from above
        while (j >= 1 && map[findFigureIndex(i, j)] <= 'Z') {

            if (map[findFigureIndex(i, j)] == 'Q' || map[findFigureIndex(i, j)] == 'R') {
                isAttacked = true;
            }
            j--;
        }
        return isAttacked;
    }




    else {  // large king
        // horizontal
        

        i = Xpos;
        j = Ypos;
        // checking if king is attacked from the right
        while ((i <= mapWidth - 4) && (map[findFigureIndex(i, j)] == ' ' || map[findFigureIndex(i, j)] == 'K')) {

            if (map[findFigureIndex(i + 1, j)] == 'q' || map[findFigureIndex(i + 1, j)] == 'r') {
                isAttacked = true;
            }
            i++;
        }

        i = Xpos;
        j = Ypos;
        // checking if king is attacked from the left
        while ((i >= 2) && (map[findFigureIndex(i, j)] == ' ' || map[findFigureIndex(i, j)] == 'K')) {

            if (map[findFigureIndex(i - 1, j)] == 'q' || map[findFigureIndex(i - 1, j)] == 'r') {
                isAttacked = true;
            }
            i--;
        }

        // vertical

        i = Xpos;
        j = Ypos;
        // checking if king is attacked from below
        while ((j <= mapHeight - 3) && (map[findFigureIndex(i, j)] == ' ' || map[findFigureIndex(i, j)] == 'K')) {

            if (map[findFigureIndex(i, j + 1)] == 'q' || map[findFigureIndex(i, j + 1)] == 'r') {
                isAttacked = true;
            }
            j++;
        }

        i = Xpos;
        j = Ypos;
        // checking if king is attacked from above
        while ((j >= 2) && (map[findFigureIndex(i, j)] == ' ' || map[findFigureIndex(i, j)] == 'K')) {

            if (map[findFigureIndex(i, j - 1)] == 'q' || map[findFigureIndex(i, j - 1)] == 'r') {
                isAttacked = true;
            }
            j--;
        }

        return isAttacked;
    }


    return isAttacked;

}

bool Checkmate::isAttacked_BishopQueen(int Xpos, int Ypos, int mapWidth, int mapHeight, char* map, bool isLowercase)
{

    bool isAttacked = false;
    int i = Xpos;  // column number
    int j = Ypos;  // row number



    if (isLowercase) { // small king

        i = Xpos;
        j = Ypos;
        // checking if king is attacked right and down diagonally
        while ((i <= mapWidth - 4) && (j <= mapHeight - 3) && (map[findFigureIndex(i, j)] == ' ' || map[findFigureIndex(i, j)] == 'k')) {

            if (map[findFigureIndex(i + 1, j + 1)] == 'Q' || map[findFigureIndex(i + 1, j + 1)] == 'B') {
                isAttacked = true;
            }

            i++;
            j++;
        }

        // checking if king is attacked right and up diagonally
        i = Xpos;
        j = Ypos;
        while ((i <= mapWidth - 4) && (j >= 2) && (map[findFigureIndex(i, j)] == ' ' || map[findFigureIndex(i, j)] == 'k')) {

            if (map[findFigureIndex(i + 1, j - 1)] == 'Q' || map[findFigureIndex(i + 1, j - 1)] == 'B') {
                isAttacked = true;
            }

            i++;
            j--;
        }

        // checking if king is attacked left and up diagonally
        i = Xpos;
        j = Ypos;
        while ((i >= 2) && (j >= 2) && (map[findFigureIndex(i, j)] == ' ' || map[findFigureIndex(i, j)] == 'k')) {

            if (map[findFigureIndex(i - 1, j - 1)] == 'Q' || map[findFigureIndex(i - 1, j - 1)] == 'B') {
                isAttacked = true;
            }

            i--;
            j--;
        }

        i = Xpos;
        j = Ypos;
        // checking if king is attacked left and down diagonally
        while ((i >= 2) && (j <= mapHeight - 3) && (map[findFigureIndex(i, j)] == ' ' || map[findFigureIndex(i, j)] == 'k')) {

            if (map[findFigureIndex(i - 1, j + 1)] == 'Q' || map[findFigureIndex(i - 1, j + 1)] == 'B') {
                isAttacked = true;
            }

            i--;
            j++;
        }

        return isAttacked;

    }

    else { // large king

        i = Xpos;
        j = Ypos;
        // checking if king is attacked right and down diagonally
        while ((i <= mapWidth - 4) && (j <= mapHeight - 3) && (map[findFigureIndex(i, j)] == ' ' || map[findFigureIndex(i, j)] == 'K')) {

            if (map[findFigureIndex(i + 1, j + 1)] == 'q' || map[findFigureIndex(i + 1, j + 1)] == 'b') {
                isAttacked = true;
            }

            i++;
            j++;
        }

        // checking if king is attacked right and up diagonally
        i = Xpos;
        j = Ypos;
        while ((i <= mapWidth - 4) && (j >= 2) && (map[findFigureIndex(i, j)] == ' ' || map[findFigureIndex(i, j)] == 'K')) {

            if (map[findFigureIndex(i + 1, j - 1)] == 'q' || map[findFigureIndex(i + 1, j - 1)] == 'b') {
                isAttacked = true;
            }

            i++;
            j--;
        }

        // checking if king is attacked left and up diagonally
        i = Xpos;
        j = Ypos;
        while ((i >= 2) && (j >= 2) && (map[findFigureIndex(i, j)] == ' ' || map[findFigureIndex(i, j)] == 'K')) {

            if (map[findFigureIndex(i - 1, j - 1)] == 'q' || map[findFigureIndex(i - 1, j - 1)] == 'b') {
                isAttacked = true;
            }

            i--;
            j--;
        }

        i = Xpos;
        j = Ypos;
        // checking if king is attacked left and down diagonally
        while ((i >= 2) && (j <= mapHeight - 3) && (map[findFigureIndex(i, j)] == ' ' || map[findFigureIndex(i, j)] == 'K')) {

            if (map[findFigureIndex(i - 1, j + 1)] == 'q' || map[findFigureIndex(i - 1, j + 1)] == 'b') {
                isAttacked = true;
            }

            i--;
            j++;
        }
        return isAttacked;
    }

    return isAttacked;
}

bool Checkmate::isAttacked_Knight(int Xpos, int Ypos, int mapWidth, int mapHeight, char* map, bool isLowercase)
{

    int i = 0;  // column number
    int j = 0;  // row number

    if (isLowercase) {  // small king

        i = Xpos + 2;
        j = Ypos + 1;

        while (i >= Xpos - 2) {                                       //
            while (j >= Ypos - 1) {                                   //         #         #
                if (i >= 1 && i <= 8 && j >= 1 && j <= 8) {           //              k    
                    if (map[findFigureIndex(i, j)] == 'N') {          //         #         #
                        return true;                                  //
                    }
                }
                j = j - 2;
            }
            i = i - 4;
            j = Ypos + 1;
        }



        i = Xpos + 1;
        j = Ypos + 2;

        while (j >= Ypos - 2) {                                       //           #     #  
            while (i >= Xpos - 1) {                                   //         
                if (i >= 1 && i <= 8 && j >= 1 && j <= 8) {           //              k
                    if (map[findFigureIndex(i, j)] == 'N') {          //         
                        return true;                                  //           #     #
                    }
                }
                i = i - 2;
            }
            j = j - 4;
            i = Xpos + 1;
        }



    }
    else {   // large king
        i = Xpos + 2;
        j = Ypos + 1;

        while (i >= Xpos - 2) {
            while (j >= Ypos - 1) {
                if (i >= 1 && i <= 8 && j >= 1 && j <= 8) {
                    if (map[findFigureIndex(i, j)] == 'n') {
                        return true;
                    }
                }
                j = j - 2;
            }
            i = i - 4;
            j = Ypos + 1;
        }

        i = Xpos + 1;
        j = Ypos + 2;

        while (j >= Ypos - 2) {
            while (i >= Xpos - 1) {
                if (i >= 1 && i <= 8 && j >= 1 && j <= 8) {
                    if (map[findFigureIndex(i, j)] == 'n') {
                        return true;
                    }
                }
                i = i - 2;
            }
            j = j - 4;
            i = Xpos + 1;
        }

    }

    return false; // if any of kings was not attacked 
}

bool Checkmate::isAttacked_Pawn(int Xpos, int Ypos, char* map, bool isLowercase)
{

    if (isLowercase) {  // small king

        if (map[findFigureIndex(Xpos + 1, Ypos + 1)] == 'P' || 
            map[findFigureIndex(Xpos - 1, Ypos + 1)] == 'P') {
            return true;
        }

    }
    else {    // large king

        if (map[findFigureIndex(Xpos + 1, Ypos - 1)] == 'p' || 
            map[findFigureIndex(Xpos - 1, Ypos - 1)] == 'p') {
            return true;
        }

    }

    return false; // if any of kings was not attacked 
}




bool Checkmate::kingIsAttacked(int kingIndex, int mapWidth, int mapHeight, char* map, bool isLowercase)
{
    int Xpos = findXpos(kingIndex, mapWidth);
    int Ypos = findYpos(kingIndex, mapWidth);

    // if king is attacked by rook or queen
    if (isAttacked_RookQueen(Xpos, Ypos, mapWidth, mapHeight, &map[0], isLowercase)) {
        return true;
    }
    // if king is attacked by bishop or queen
    else if (isAttacked_BishopQueen(Xpos, Ypos, mapWidth, mapHeight, &map[0], isLowercase)) {
        return true;
    }
    // if king is attacked by knight
    else if (isAttacked_Knight(Xpos, Ypos, mapWidth, mapHeight, &map[0], isLowercase)) {
        return true;
    }
    // if king is attacked by pawn
    else if (isAttacked_Pawn(Xpos, Ypos, &map[0], isLowercase)) {
        return true;
    }

    else return false; // if any of kings was not attacked 
}



//function that determines whether the check was set
bool Checkmate::chessCheck(char* map, int mapWidth, int mapHeight)
{
 
    if (kingIsAttacked(smallKingMapIndex, mapWidth, mapHeight, &map[0], true)) {
            return true;
    } 

    if (kingIsAttacked(largeKingMapIndex, mapWidth, mapHeight, &map[0], false)) {
            return true;
    }

    return false; // if any of kings aren't attacked
}
