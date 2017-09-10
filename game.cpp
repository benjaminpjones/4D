#include <iostream>
#include <SDL2/SDL.h>
#include "game.h"
#include "graphics.h"
#include "color.h"
#include "assert.h"

Game::Game()
  :
  graphics(800, 600),
  tess(),
  offset(0,0,0,0)
{
  window = NULL;
  renderer = NULL;
  running = true;
}

bool Game::Initialize() {
  if (SDL_Init(SDL_INIT_EVERYTHING) < 0) {
    std::cout << "Could not initialize SDL." << std::endl;
    return false;
  }

  window = SDL_CreateWindow("4D Stuff",
                            SDL_WINDOWPOS_CENTERED,
                            SDL_WINDOWPOS_CENTERED,
                            graphics.screenWidth,
                            graphics.screenHeight,
                            0);

  if (window == NULL) {
    std::cout << "Could not create window." << std::endl;
    return false;
  }

  renderer = SDL_CreateRenderer(window, -1, 0);

  if (renderer == NULL) {
    std::cout << "Could not create renderer." << std::endl;
    return false;
  }

  graphics.SetRenderer(renderer);

  return true;
}

void Game::Execute() {

  SDL_Event event;

  while (running) {
    ProcessEvents(event);
    Update();
    Render();
  }
}

void Game::ProcessEvents(SDL_Event& event) {
  offset = {0,0,0,0};
  while (SDL_PollEvent(&event)) {
    switch (event.type) {
      case SDL_QUIT:
        running = false;
        break;
      case SDL_KEYDOWN:
        switch(event.key.keysym.sym) {
          case SDLK_UP:
            offset += {0, 0, -DELTA, 0};
            break;
          case SDLK_DOWN:
            offset += {0, 0, DELTA, 0};
            break;
          case SDLK_LEFT:
            tess.Transform({{{ 0.9987502604, 0, 0.04997916927, 0 },
                            { 0, 1, 0, 0 },
                            { -0.04997916927, 0, 0.9987502604, 0 },
                            { 0, 0, 0, 1 }}});
            break;
          case SDLK_RIGHT:
            tess.Transform({{{ 0.9987502604, 0, -0.04997916927, 0 },
                            { 0, 1, 0, 0 },
                            { 0.04997916927, 0, 0.9987502604  , 0 },
                            { 0, 0, 0, 1 }}});
            break;
          case SDLK_COMMA:
            tess.Transform({{{ 1, 0, 0, 0 },
                            { 0, 1, 0, 0 },
                            { 0, 0, 0.9999500004, -0.009999833334 },
                            { 0 , 0, 0.009999833334, 0.9999500004 }}});
            break;
          case SDLK_PERIOD:
            tess.Transform({{{ 1, 0, 0, 0 },
                            { 0, 1, 0, 0 },
                            { 0, 0, 0.9999500004, 0.009999833334 },
                            { 0 , 0, -0.009999833334, 0.9999500004 }}});
            break;
          case SDLK_w:
            offset += {0, 0, -DELTA, 0};
            break;
          case SDLK_s:
            offset += {0, 0, DELTA, 0};
            break;
          case SDLK_a:
            offset += {DELTA, 0, 0, 0};
            break;
          case SDLK_d:
            offset += {-DELTA, 0, 0, 0};
            break;
          case SDLK_q:
            offset += {0,0,0, 0.1*DELTA};
            break;
          case SDLK_e:
            offset += {0,0,0, -0.1*DELTA};
            break;
        }
    }
  }
}

void Game::Update() {
  tess.Shift(offset);
}

void Game::Render() {
  graphics.ClearScreen();

  tess.DrawWireFrame(graphics);
  graphics.DrawLine({10,10},{100,100},Colors::Green);
  graphics.DrawPixel(10,10,150,150,150,255);
  
  SDL_RenderPresent(renderer);
}

void Game::CleanUp() {
  SDL_Quit();
}
