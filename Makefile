CC = gcc
SRC = $(wildcard *.c)
OBJ = $(SRC:.c=.o)
EXE = clox

$(EXE):$(OBJ)
	@$(CC) $^ -O3 -o $@

$(OBJ):%.o:%.c
	@$(CC) -c $< -o $@

run:$(EXE)
	@./$< ||:

clean:
	@rm -rf *.o *.exe; clear