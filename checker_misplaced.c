#include "mastermind.h"


int checker_misplaced(char *code, char *guess)
{

    int counter_misplaced = 0;

    for(int i = 0; code[i] != '\0'; i++){
        for(int j = 0; guess[j] != '\0'; j++){
            if (code[i] == guess[j] && i != j) {
                counter_misplaced++;
            }
        }
    }

    return counter_misplaced;

}
