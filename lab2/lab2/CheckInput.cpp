#include "CheckInput.h"

// checks if the figures have different register
bool CheckingInput::isDifferentRegister(int prevInd, int nextInd, char* map)
{
    if (map[prevInd] <= 'Z' && map[nextInd] >= 'a' ||
        map[prevInd] >= 'a' && map[nextInd] <= 'Z' || map[nextInd] == ' ') {

        return true;
    }
    else return false;
}

bool CheckingInput::isCorrectInput(char* input, char* map)
{
    if (input[0] >= 'A' && input[0] <= 'H') { // changing the case of the entered string
        input[0] = input[0] + 'a' - 'A';
    }

    if (input[2] >= 'A' && input[2] <= 'H') { // changing the case of the entered string
        input[2] = input[2] + 'a' - 'A';
    }

    int mapWidth = 11;
    int mapHeight = 10;
    // checking the correctness of the input
    if ((input[0] >= 'a' && input[0] <= 'h') && (input[2] >= 'a' && input[2] <= 'h') && 
        (input[1] >= '1' && input[1] <= '8') && (input[3] >= '1' && input[3] <= '8')) {
 
        int prevMapIndex = ((int)input[1] - 49 + 1) * mapWidth + ((int)input[0] - 97 + 1); // '1' = 49;
        int nextMapIndex = ((int)input[3] - 49 + 1) * mapWidth + ((int)input[2] - 97 + 1); // 'a' = 97;

        bool differentRegister = isDifferentRegister(prevMapIndex, nextMapIndex, &map[0]);

        if (map[prevMapIndex] != ' ' && prevMapIndex != nextMapIndex && differentRegister){ 
            return true;
        }
        else return false;
    } 
    else return false;
}


