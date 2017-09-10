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
