/*
 *  Tessy - An Exploration in Four Dimensions
 *  graphics.h
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

#ifndef GRAPHICS_H
#define GRAPHICS_H

#include <SDL2/SDL.h>
#include "color.h"

struct Pixel {
    int x;
    int y;
};

class Graphics { 
  public:
    Graphics(int screenWidth, int screenHeigth);

    void SetRenderer(SDL_Renderer* renderer);
    void ClearScreen();
    void DrawPixel(int x, int y, int r, int g, int b, int a);
    void DrawPixel(Pixel pixel, Color c);
    void DrawLine(int x0, int y0, int x1, int y1,
                  int r, int g, int b, int a) const;
    void DrawLine(Pixel px0, Pixel px1, Color c) const;

    const int screenWidth;
    const int screenHeight;
  private:
    SDL_Renderer* renderer;
};

#endif
