CC=gcc
CFLAGS=-Wall -Wextra
SRC= $(wildcard *.c)
OBJ= $(SRC:.c=.o)
EXEC=main

all: $(EXEC) clean

$(EXEC): $(OBJ)
	$(CC) -o $@ $^

main.o: affichage.h tris.h comparaison.h

%.o: %.c
	@$(CC) -o $@ -c $< $(CFLAGS)

#.PHONY: clean

clean:
	@rm -rf *.o

#mrproper: clean
#	@rm -rf $(EXEC)
