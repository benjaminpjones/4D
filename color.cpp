#include "color.h"
#include <cstdint>

Color::Color(std::uint8_t r, std::uint8_t g, std::uint8_t b, std::uint8_t a) {
  red = r;
  green = g;
  blue = b;
  alpha = a;
}

std::uint8_t Color::getRed() { return red; }
std::uint8_t Color::getGreen() { return green; }
std::uint8_t Color::getBlue() { return blue; }
std::uint8_t Color::getAlpha() { return alpha; }