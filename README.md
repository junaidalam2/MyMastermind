# Welcome to My Mastermind
***

## Task
Mastermind is a game with 8 pieces with a distinct color. For this game, the pieces are represented by positive integers. A secret code is composed of 4 distinct integers which have have values from 0-7.

A player has a certain number attempts to find the secret code. After each input, the game indicates to the player the number of well placed pieces and the number of misplaced pieces.

## Description
main.c takes inputs from the user the initiated the game. If no code and no attempts are specified by the user, the applicaiton will generate values (see below) for these inputs.

The game will take guesses from the user and determine the number of well placed and misplaced pieces. If the player guesses correctly, the game ends. 

## Installation
The application uses a GCC compiler for C. 

## Usage
Run the following in zsh:

```
./my_mastermind -c [code] -t [attempts]
```
Where code is the secret code the player will try to guess and attempts is the number of attempts

-if a code is not inputted, the game will generate a random code
-if attempts is not inputted, the game will apply a default value of 10


### The Core Team
Junaid Alam
