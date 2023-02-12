CC=g++
CFLAGS=-I. -std=c++14
OBJ = game.o color.o geometry3d.o geometry4d.o graphics.o polychora.o main.o

all: FourD
	echo compiled FourD!

%.o: %.cpp
	$(CC) -c -o $@ $< $(CFLAGS)

FourD: $(OBJ)
	$(CC) -o $@ $^ $(CFLAGS) -lSDL2

clean:
	rm *.o FourD
