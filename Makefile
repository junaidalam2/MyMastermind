TARGET = my_mastermind
FILES = main random_code_generator obtain_guesses checker_well_placed checker_misplaced
SRC = $(addsuffix .c, $(FILES))
OBJ = $(addsuffix .o, $(FILES))
CFLAGS += -Wall -Wextra -Werror

all: $(TARGET)

$(TARGET): $(OBJ)
	gcc -o $(TARGET) $(OBJ) 

$(OBJ): $(SRC)
	gcc $(CFLAGS) -c $(SRC)

run : all
	./$(TARGET)

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(TARGET)

re: fclean all

.PHONY: all clean fclean re

