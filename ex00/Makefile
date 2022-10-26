NAME = rush-02

SRC = $(wildcard *.c)

OBJ = main.o input_process.o comb_nubr_name.o comb_nubr_name2.o locate.o locate2.o toolkit.o

CFLAGS = -Wall -Wextra -Werror

CUR-DIR = $(shell pwd)


prog: $(OBJ)
	gcc $(FLAGS) $(OBJ) -o $(NAME)

.PHONY: clean fclean

fclean: clean
	rm -f $(NAME)

clean:
	rm -f $(OBJ)

main.o: main.c
	gcc -c main.c

input_process.o: input_process.c
	gcc -c input_process.c

comb_nubr_name.o: comb_nubr_name.c
	gcc -c comb_nubr_name.c

comb_nubr_name2.o: comb_nubr_name2.c
	gcc -c comb_nubr_name2.c

locate.o: locate.c
	gcc -c locate.c

locate2.o: locate2.c
	gcc -c locate2.c

toolkit.o: toolkit.c
	gcc -c toolkit.c
