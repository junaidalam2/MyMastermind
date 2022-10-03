#ifndef MASTERMIND_H_INCLUDED
#define MASTERMIND_H_INCLUDED

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <io.h> // <unistd.h>

#define CODE_LENGTH 4

char *random_code_generator();
char *obtain_guesses(int attempts);
int checker_well_placed(char *code, char *guess);
int checker_misplaced(char *code, char *guess);

#endif // MASTERMIND_H_INCLUDED
