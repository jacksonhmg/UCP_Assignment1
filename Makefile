CC = gcc -g
CFLAGS = -Wall -pedantic -ansi
OBJ = main.o setup.o gameloop.c terminal.o
EXEC = prog

ifdef DEBUG
CFLAGS += -D DEBUG
DEBUG : clean $(EXEC)
endif

$(EXEC) : $(OBJ)
	$(CC) $(OBJ) -o $(EXEC)

main.o : main.c setup.h macros.h gameloop.h terminal.h
	$(CC) $(CFLAGS) -c main.c

setup.o : setup.c setup.h macros.h
	$(CC) $(CFLAGS) -c setup.c

gameloop.o : gameloop.c gameloop.h
	$(CC) $(CFLAGS) -c gameloop.c

terminal.o : terminal.c terminal.h
	$(CC) $(CFLAGS) -c terminal.c

clean:
	rm -f $(EXEC) $(OBJ)