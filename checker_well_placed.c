#include "mastermind.h"


int checker_well_placed(char *code, char *guess)
{

    int counter_well_placed = 0;

    for(int i = 0; code[i] != '\0'; i++){
        if (code[i] == guess[i]) {
            counter_well_placed++;
        }
    }

    return counter_well_placed;

}
