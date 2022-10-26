NAME = rush-02

SRC = $(wildcard *.c)

OBJ = $(SRC:.c=.o)

CFLAGS = -Wall -Wextra -Werror

CUR-DIR = $(shell pwd)


prog: $(OBJ)
	gcc -o $(NAME) $(CFLAGS) $(OBJ)

.PHONY: clean fclean

fclean: clean
	rm -f $(NAME)

clean:
	rm -f $(OBJ)
