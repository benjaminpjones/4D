#include <iostream>
#include "game.h"

int main( int argc, char* args[] ) {
  Game game;

  if (game.Initialize()) {
    game.Execute();
  }

  game.CleanUp();

  return 0;
}
