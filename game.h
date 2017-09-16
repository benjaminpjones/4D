/*
 *  Tessy - An Exploration in Four Dimensions
 *  game.h
 *  Copyright (C) 2017  Benjamin P. Jones
 *
 *  This program is free software: you can redistribute it and/or modify
 *  it under the terms of the GNU General Public License as published by
 *  the Free Software Foundation, either version 3 of the License, or
 *  (at your option) any later version.
 *
 *  This program is distributed in the hope that it will be useful,
 *  but WITHOUT ANY WARRANTY; without even the implied warranty of
 *  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 *  GNU General Public License for more details.
 *
 *  You should have received a copy of the GNU General Public License
 *  along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */

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
