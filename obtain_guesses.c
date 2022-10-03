#include "mastermind.h"
#define BUFSIZE 1024


char *obtain_guesses(int attempts)
{

    printf("Will you find the secret code?\n");

    char *guess = malloc(sizeof(char)*CODE_LENGTH);  // variable to record user's guesses
    guess[CODE_LENGTH] = '\0';


    char *exit = malloc(sizeof(char)*CODE_LENGTH); // user can use 'ctrl+d' to exit; variable returned to main so that main exits
    exit[0] = 'E';
    exit[1] = 'X';
    exit[2] = 'I';
    exit[3] = 'T';
    exit[4] = '\0';


    char buff[BUFSIZE];  // array to store STDIN
    buff[BUFSIZE] = '\0';

    int input_flag = 0;  // if input meets requirements, while loop exits by changing input_flag value

    while (input_flag == 0){

        // clear array guess
        for(int i = 0; i < CODE_LENGTH; i++){
            guess[i] = '\0';
        }

        // clear array buff
        for(int i = 0; i < BUFSIZE; i++){
            buff[i] = '\0';
        }

        printf("Please enter a valid guess\nYou have %d guesses\n", attempts);

        int bytes = 0;  // variable to record ctrl+d (i.e. STDIN = 0)

        while((bytes = read(0, &buff, BUFSIZE)) >= 0) {

            // if user inputs ctrl+d exit
            if (bytes == 0) {
                printf("Read EOF!\n");
                return exit;
            }
            else {

                // obtain user input and change from int to char
                for(int i = 0; i < CODE_LENGTH; i++){
                    guess[i] = buff[i] + '0';
                    guess[i] = guess[i] - 48;

                }

                for(int i = 0; i < BUFSIZE; i++){ // clear buff array
                    buff[i] = '\0';
                }

                break;

            }
        }

       // check if input is outside 0 to 7; if outside, input flag changed to 0
        input_flag = 1;
        for(int i = 0; i < CODE_LENGTH; i++){
            if(guess[i] < 48 || guess[i] > 55) {
                input_flag = 0;
            }
        }

        // exit loop if input flag = 1
        if(input_flag == 1){

            break;

        } else {
            printf("Wrong input!\n");
            printf("Please enter 4 single-digit integers from 0-7\n");
        }

    }

    return guess;

}
