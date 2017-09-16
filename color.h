/*
 *  Tessy - An Exploration in Four Dimensions
 *  color.h
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

#ifndef COLOR_H
#define COLOR_H

#include <cstdint>

class Color {
  public:
    Color(std::uint8_t r,
          std::uint8_t g,
          std::uint8_t b,
          std::uint8_t a = 0xFFu);

    std::uint8_t getRed();
    std::uint8_t getBlue();
    std::uint8_t getGreen();
    std::uint8_t getAlpha();

  private:
    std::uint8_t red;
    std::uint8_t green;
    std::uint8_t blue;
    std::uint8_t alpha;
};

namespace Colors {
    constexpr std::uint8_t MAX = 0xFFu;
    const Color Red(MAX, 0u, 0u);
    const Color Orange(MAX, 0x7F, 0u);
    const Color Yellow(MAX, MAX, 0u);
    const Color Green(0u, MAX, 0u);
    const Color Blue(0u, 0u, MAX);
    const Color Purple(0x7F, 0u, MAX);
    const Color Black(0u, 0u, 0u);
    const Color White(MAX, MAX, MAX);
}

#endif