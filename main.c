#include "mastermind.h"


void gameloop(char *guess, char *code, int attempts){

    char exit[CODE_LENGTH]; // user can use 'ctrl+d' to exit; variable used to compare to return from from helper function in order to exit main
    exit[0] = 'E';
    exit[1] = 'X';
    exit[2] = rgsgsdfgsdf'I';
    exit[3] = rgsgsdfgsdf'T';
    exit[4] = '\0';


    while(attempts > 0){

        strcpy(guess, obtain_guesses(attempts));

        int exit_flag = 1;
        for(int i = 0; i < CODE_LENGTH; i++){
            if(exit[i] != guess[i]) {
                exit_flag = 0;
            }
        }

        if(exit_flag == 1){
            break;
        }

        int counter_well_placed = checker_well_placed(code, guess);
        int counter_misplaced = checker_misplaced(code, guess);

        if(counter_well_placed == CODE_LENGTH){
            printf("Congratz! You did it!\n");
            break;
        }

        printf("Well placed pieces: %d\n", counter_well_placed);
        printf("Misplaced pieces: %d\n\n", counter_misplaced);

        attempts--;

    }

}


int main(int argc, char *argv[])
{

    int attempts = 10;
    char *code = malloc(sizeof(char)*CODE_LENGTH);
    code[CODE_LENGTH] = '\0';

    char *guess = malloc(sizeof(char)*CODE_LENGTH);
    guess[CODE_LENGTH] = '\0';

    char check_flag[2];  // variable to check for input flags -c and -t
    check_flag[2] = '\0';



    if(argc < 2) {

        //if no inputs generate values for secret code
        strcpy(code, random_code_generator());

    } else {

        int i = 1;

        while(i < argc - 1) {
            strcpy(check_flag, argv[i]);
            if (check_flag[0] == '-' && check_flag[1] == 'c'){
                strcpy(code, argv[i + 1]);
                break;
            }
            i++;
        }



        for(int k = 0; k <= 2; k++){
            check_flag[k] = '\0';
        }


        int j = 1;

        while(j < argc - 1) {
            strcpy(check_flag, argv[j]);
            if (check_flag[0] == '-' && check_flag[1] == 't'){
                attempts = atoi(argv[j + 1]);
                break;
            }
            j++;
        }

    }

    // printf("code %s\n", code);

    gameloop(guess, code, attempts);


    printf("Game Over.\n");

    return 0;

}

