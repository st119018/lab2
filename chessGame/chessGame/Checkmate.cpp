#include "Checkmate.h"

Checkmate::Checkmate(int blackXpos, int blackYpos, int whiteXpos, int whiteYpos)
{
    blackKingXpos = blackXpos;
    blackKingYpos = blackYpos;
    whiteKingXpos = whiteXpos;
    whiteKingYpos = whiteYpos;
}

bool Checkmate::isAttacked_RookQueen(int Xpos, int Ypos, BaseF* map, bool isLowercase)
{
    char enemyTeam = 'w';
    
    if (isLowercase) {
        enemyTeam = 'w';
    }
    else {
        enemyTeam = 'b';
    }
    bool isAttacked = false;
    int i = Xpos;       // column number
    int j = Ypos;       // row number

    // horizontal
    // checking if king is attacked from the right

        while (i <= 7 && (map[findFigureIndex(i, j) - 1].getTeam() == 'n' || map[findFigureIndex(i, j) - 1].getPieceType() == 'k')) {
           
            if ((map[findFigureIndex(i + 1, j) - 1].getPieceType() == 'q' ||
                map[findFigureIndex(i + 1, j) - 1].getPieceType() == 'r') && map[findFigureIndex(i + 1, j) - 1].getTeam() == enemyTeam){
                isAttacked = true;
            }
            i++;
        }
    
    // checking if king is attacked from the left
    i = Xpos;
    j = Ypos;
        while (i >= 2 && (map[findFigureIndex(i, j) - 1].getTeam() == 'n' || map[findFigureIndex(i, j) - 1].getPieceType() == 'k')) {

            if ((map[findFigureIndex(i - 1, j) - 1].getPieceType() == 'q' ||
                map[findFigureIndex(i - 1, j) - 1].getPieceType() == 'r') && map[findFigureIndex(i - 1, j) - 1].getTeam() == enemyTeam) {
                isAttacked = true;
            }
            i--;
        }


    // vertical
    i = Xpos;
    j = Ypos;
    // checking if king is attacked from below
        while (j <= 7 && (map[findFigureIndex(i, j) - 1].getTeam() == 'n' || map[findFigureIndex(i, j) - 1].getPieceType() == 'k')) {
            
            if ((map[findFigureIndex(i, j + 1) - 1].getPieceType() == 'q' ||
                map[findFigureIndex(i, j + 1) - 1].getPieceType() == 'r') && map[findFigureIndex(i, j + 1) - 1].getTeam() == enemyTeam) {
                isAttacked = true;
            }
            j++;
        }
    

    i = Xpos;
    j = Ypos;
    // checking if king is attacked from above
        while (j >= 2 && (map[findFigureIndex(i, j) - 1].getTeam() == 'n' || map[findFigureIndex(i, j) - 1].getPieceType() == 'k')) {
            
            if ((map[findFigureIndex(i, j - 1) - 1].getPieceType() == 'q' ||
                map[findFigureIndex(i, j - 1) - 1].getPieceType() == 'r') && map[findFigureIndex(i, j - 1) - 1].getTeam() == enemyTeam) {
                isAttacked = true;
            }
            j--;
        }
    

    return isAttacked;
}

bool Checkmate::isAttacked_BishopQueen(int Xpos, int Ypos, BaseF* map, bool isLowercase)
{
    char enemyTeam = 'n';

    if (isLowercase) {
        enemyTeam = 'w';
    }
    else {
        enemyTeam = 'b';
    }
    bool isAttacked = false;

    int i = Xpos;
    int j = Ypos;
    // checking if king is attacked right and down diagonally
    if (i <= 8 && j <= 8) {

        while (i <= 7 && j <= 7 && (map[findFigureIndex(i, j) - 1].getTeam() == 'n' || map[findFigureIndex(i, j) - 1].getPieceType() == 'k')) {
            if ((map[findFigureIndex(i + 1, j + 1) - 1].getPieceType() == 'q' || 
                map[findFigureIndex(i + 1, j + 1) - 1].getPieceType() == 'b') && map[findFigureIndex(i + 1, j + 1) - 1].getTeam() == enemyTeam) {
                isAttacked = true;
            }
            i++;
            j++;
        }
    }
    // checking if king is attacked right and up diagonally
    i = Xpos;
    j = Ypos;
    if (i <= 8 && j >= 1) {
        while (i <= 7 && j >= 2 && (map[findFigureIndex(i, j) - 1].getTeam() == 'n' || map[findFigureIndex(i, j) - 1].getPieceType() == 'k')) {
            if ((map[findFigureIndex(i + 1, j - 1) - 1].getPieceType() == 'q' || 
                map[findFigureIndex(i + 1, j - 1) - 1].getPieceType() == 'b') && map[findFigureIndex(i + 1, j - 1) - 1].getTeam() == enemyTeam) {
                isAttacked = true;
            }
            i++;
            j--;
        }   
    }
    // checking if king is attacked left and up diagonally
    i = Xpos;
    j = Ypos;
    if (i >= 1 && j >= 1) {
        while (i >= 2 && j >= 2 && (map[findFigureIndex(i, j) - 1].getTeam() == 'n' || map[findFigureIndex(i, j) - 1].getPieceType() == 'k')) {
            if ((map[findFigureIndex(i - 1, j - 1) - 1].getPieceType() == 'q' ||
                map[findFigureIndex(i - 1, j - 1) - 1].getPieceType() == 'b') && map[findFigureIndex(i - 1, j - 1) - 1].getTeam() == enemyTeam) {
                isAttacked = true;
            }
            i--;
            j--;
        }
    }
    // checking if king is attacked left and down diagonally
    i = Xpos;
    j = Ypos;
    if (i >= 1 && j <= 8) {
        while (i >= 2 && j <= 7 && (map[findFigureIndex(i, j) - 1].getTeam() == 'n' || map[findFigureIndex(i, j) - 1].getPieceType() == 'k')) {
            if ((map[findFigureIndex(i - 1, j + 1) - 1].getPieceType() == 'q' || 
                map[findFigureIndex(i - 1, j + 1) - 1].getPieceType() == 'b') && map[findFigureIndex(i - 1, j + 1) - 1].getTeam() == enemyTeam) {
                isAttacked = true;
            }
            i--;
            j++;
        }
    }

    return isAttacked;
}

bool Checkmate::isAttacked_Knight(int Xpos, int Ypos, BaseF* map, bool isLowercase)
{
    char enemyTeam = 'n';

    if (isLowercase) {
        enemyTeam = 'w';
    }
    else {
        enemyTeam = 'b';
    }
    bool isAttacked = false;

    int i = Xpos + 2;
    int j = Ypos + 1;

    while (i >= Xpos - 2) {                                       
        while (j >= Ypos - 1) {
            if (i >= 1 && i <= 8 && j >= 1 && j <= 8) {
                if (map[findFigureIndex(i, j) - 1].getPieceType() == 'n' && 
                    map[findFigureIndex(i, j) - 1].getTeam() == enemyTeam) {
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
                if (map[findFigureIndex(i, j) - 1].getPieceType() == 'n' &&
                    map[findFigureIndex(i, j) - 1].getTeam() == enemyTeam) {
                    return true;
                }
            }
            i = i - 2;
        }
        j = j - 4;
        i = Xpos + 1;
    }

    return false;
}

bool Checkmate::isAttacked_Pawn(int Xpos, int Ypos, BaseF* map, bool isLowercase)
{

    if (isLowercase) {
        if (map[findFigureIndex(Xpos + 1, Ypos + 1) - 1].getPieceType() == 'p' && map[findFigureIndex(Xpos + 1, Ypos + 1) - 1].getTeam() == 'w' ||
            map[findFigureIndex(Xpos - 1, Ypos + 1) - 1].getPieceType() == 'p' && map[findFigureIndex(Xpos - 1, Ypos + 1) - 1].getTeam() == 'w') {
            return true;
        }
    }
    else {
        if (map[findFigureIndex(Xpos + 1, Ypos - 1) - 1].getPieceType() == 'p' && map[findFigureIndex(Xpos + 1, Ypos - 1) - 1].getTeam() == 'b' ||
            map[findFigureIndex(Xpos - 1, Ypos - 1) - 1].getPieceType() == 'p' && map[findFigureIndex(Xpos - 1, Ypos - 1) - 1].getTeam() == 'b') {
            return true;
        }
    }
    return false;
}

bool Checkmate::kingIsAttacked(BaseF* map, bool isLowercase)
{
    int Xpos = blackKingXpos, Ypos = blackKingYpos;
    if (isLowercase) {
        Xpos = blackKingXpos;
        Ypos = blackKingYpos;
    }
    else {
        Xpos = whiteKingXpos;
        Ypos = whiteKingYpos;
    }

    if (isAttacked_RookQueen(Xpos, Ypos, map, isLowercase)) {
        return true;

    }
    else if (isAttacked_BishopQueen(Xpos, Ypos, map, isLowercase)) {
        return true;
    }
    
    else if (isAttacked_Knight(Xpos, Ypos, map, isLowercase)) {
        return true;
    } 
    else if (isAttacked_Pawn(Xpos, Ypos, map, isLowercase)) {
        return true;
    }

    else return false;
}

bool Checkmate::checkIsSet(BaseF* map)
{

    if (kingIsAttacked(map, true)) {
        return true;
    }

    if (kingIsAttacked(map, false)) {
        return true;
    }
    
    return false; // if any of kings aren't attacked
    
}

void Checkmate::setBlackKingPos(int x, int y)
{
    blackKingXpos = x;
    blackKingYpos = y;
}

void Checkmate::setWhiteKingPos(int x, int y)
{
    whiteKingXpos = x;
    whiteKingYpos = y;
}
