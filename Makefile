CC=gcc
CFLAGS=-I.
OBJ = game.o color.o geometry3d.o geometry4d.o graphics.o polychora.o 

%.o: %.cpp
	$(CC) -c -o $@ $< $(CFLAGS)

FourD: $(OBJ)
	$(CC) -o $@ $^ $(CFLAGS)

all: FourD
	echo compiled FourD!
