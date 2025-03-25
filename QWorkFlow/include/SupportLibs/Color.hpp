#ifndef COLOR_HPP
#define COLOR_HPP

#include <iostream>

#include "publicDefine.h"

/// @brief A class for store& covert color.
class Color {
  typedef struct _RGB {
    int R, G, B;
  } RGB;

 private:
  int cover16t10(char a, char b);
  str cover10t16(int a);

 public:
  RGB color;
  Color(int R, int G, int B);
  Color(str hex);
  RGB Hex2RGB(str hex);
  str RGB2Hex(RGB rgb);
};

/// @brief Init Color class as RGB.
/// @param R Red.
/// @param G Green.
/// @param B Blue.
Color::Color(int R, int G, int B) {
  if (max(max(R, G), B) <= 255 && max(max(R, G), B) >= 0) color.R = R;
  color.G = G;
  color.B = B;
}

/// @brief Init Color class as RGB.
/// @param hex A str Hex Code.
Color::Color(str hex) { color = Hex2RGB(hex); }

/// @brief Cover num from 16 to 10.
/// @param a char a.
/// @param b char b.
/// @return A int 10 num.
int Color::cover16t10(char a, char b) {
  return int(a - '0') * 16 + int(b - '0');
}

/// @brief Cover num from 10 to 16.
/// @param a A int 10 num.
/// @return A str 16 num.
str Color::cover10t16(int a) {
  str callback = "";
  callback += to_string(a / 16);
  callback += to_string(a % 16);
  return callback;
}

/// @brief Cover color from Hex to RGB.
/// @param hex A str Hex code.
/// @return A RGB code.
Color::RGB Color::Hex2RGB(str hex) {
  if ((hex.size() == 7) && (hex[0] == '#')) {
    RGB callback;
    callback.R = cover16t10(hex[1], hex[2]);
    callback.G = cover16t10(hex[3], hex[4]);
    callback.B = cover16t10(hex[5], hex[6]);
    return callback;
  } else {
    RGB callback = {255, 255, 255};
    return callback;
  }
}

/// @brief Cover color from RGB to Hex.
/// @param rgb A RGB code.
/// @return A str Hex code.
str Color::RGB2Hex(RGB rgb) {
  str callback = "#";
  callback += cover10t16(rgb.R);
  callback += cover10t16(rgb.G);
  callback += cover10t16(rgb.B);
  return callback;
}

#endif