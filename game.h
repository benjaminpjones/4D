#ifndef GAME_H
#define GAME_H

#include <SDL2/SDL.h>
#include "graphics.h"
#include "polychora.h"
#include "geometry4d.h"


class Game {
  public:
    Game();
    bool Initialize();
    void Execute();
    void CleanUp();
  private:
    void ProcessEvents(SDL_Event& event);
    void Update();
    void Render();

    bool running;
    SDL_Window* window;
    SDL_Renderer* renderer;

    Graphics graphics;

    // Game Objects
    Tesseract tess;
    Point4D offset;
    static constexpr double DELTA = 0.1;
};

#endif
