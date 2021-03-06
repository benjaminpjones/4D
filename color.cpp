/*
 *  Tessy - An Exploration in Four Dimensions
 *  color.cpp
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