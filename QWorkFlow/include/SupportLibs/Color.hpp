#ifndef COLOR_HPP
#define COLOR_HPP

#include <iostream>

class Color {
  typedef struct _RGB {
    int R, G, B;
  } RGB;

 public:
  Color(int R, int G, int B);
  RGB Hex2RGB(std::string hex) {
    if ((hex.size() == 7) && (hex[0] == '#')) {
      RGB callback;
      callback.R = int(hex[1]) * 16 + int(hex[2]);
      callback.G = int(hex[3]) * 16 + int(hex[4]);
      callback.B = int(hex[5]) * 16 + int(hex[6]);
    }
  }
};

#endif