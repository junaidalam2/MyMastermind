#include "mastermind.h"


char *random_code_generator()
{

    char *code = malloc(sizeof(char)*CODE_LENGTH);  // array populated with random integers; no duplicate integers
    code[CODE_LENGTH] = '\0';
    int code_random[CODE_LENGTH];  // array populated below with random integers; no duplicate integers

    int integers[8]; // array of integers
    time_t t;

    // populate code_random with -1 => -1 is used below in while loop as entry condition
    for(int i = 0; i < CODE_LENGTH; i++){
        code_random[i] = -1;
    }
    code_random[CODE_LENGTH] = '\0';

    // populate array of integers 0 to 7
    for(int i = 0; i < 8; i++){
        integers[i] = i;
    }

    srand((unsigned) time(&t));

    // populate array code_random with integers and avoid duplicate integers
    for(int i = 0; i < CODE_LENGTH; i++){
        while(code_random[i] == -1){
            int index = rand() % 8;
            code_random[i] = integers[index];
            integers[index] = -1;
        }
    }

    // convert int to char
    for(int i = 0; i < CODE_LENGTH; i++){
        code[i] = code_random[i] + '0';
    }

    return code;
}
