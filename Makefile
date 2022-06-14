CC=g++
CFLAGS=-I. -std=c++14 -lSDL2
OBJ = game.o color.o geometry3d.o geometry4d.o graphics.o polychora.o main.o

%.o: %.cpp
	$(CC) -c -o $@ $< $(CFLAGS)

FourD: $(OBJ)
	$(CC) -o $@ $^ $(CFLAGS)

all: FourD
	echo compiled FourD!
