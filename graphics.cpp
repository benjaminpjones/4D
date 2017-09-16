/*
 *  Tessy - An Exploration in Four Dimensions
 *  graphics.cpp
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

#include <stdlib.h>
#include <utility>
#include <SDL2/SDL.h>
#include "graphics.h"

Graphics::Graphics(int screenWidth, int screenHeight)
  :
  screenWidth(screenWidth),
  screenHeight(screenHeight)
{
}

void Graphics::SetRenderer(SDL_Renderer* renderer)
{
  this->renderer = renderer;
}

void Graphics::ClearScreen()
{
  SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
  SDL_RenderClear(renderer);

}

void Graphics::DrawPixel(int x, int y, int r, int g, int b, int a)
{
  SDL_SetRenderDrawColor(renderer, r, g, b, a);
  SDL_RenderDrawPoint(renderer, x, y);
}

void Graphics::DrawPixel(Pixel pixel, Color c) {
  DrawPixel(pixel.x,
            pixel.y,
            c.getRed(),
            c.getGreen(),
            c.getBlue(),
            c.getAlpha());
}

// DrawLine draws line using naive drawing formula
// TODO: Implement Bresenham/Wu algorithms or utilize SDL framework

void Graphics::DrawLine(int x0, int y0, int x1, int y1,
                        int r, int g, int b, int a) const
{
  SDL_SetRenderDrawColor(renderer, r, g, b, a);
  int dx = x1 - x0;
  int dy = y1 - y0;
  if (abs(dx) > abs(dy)) {
    const double m = double(dy)/double(dx);
    const double b = y0 - m*x0;

    if (x0 > x1) std::swap(x0, x1);
    for (int x = x0; x < x1; x++) {
      SDL_RenderDrawPoint(renderer, x, m*x+b);
    }
  } else {
    const double m = double(dx)/double(dy);
    const double b = x0 - m*y0;

    if (y0 > y1) std::swap(y0, y1);
    for (int y = y0; y < y1; y++) {
      SDL_RenderDrawPoint(renderer, m*y+b, y);
    }
  }
}

void Graphics::DrawLine(Pixel px0, Pixel px1, Color c) const {
  DrawLine(px0.x, px0.y, px1.x, px1.y,
           c.getRed(), c.getGreen(), c.getBlue(), c.getAlpha());
}