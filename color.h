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