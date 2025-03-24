#include "../../../../QWorkFlow/include/SupportLibs/Message.hpp"

#include <iostream>

#ifndef cout
#define cout std::cout
#endif

#ifndef endl
#define endl std::endl
#endif

int main() {
  Message message("Test");

  cout << message.placeList.add("place1") << endl;
  cout << message.placeList.add(0, "place2") << endl;
  cout << message.placeList.add(1, "place2") << endl;
  cout << message.placeList.get(0) << endl;
  cout << message.placeList.get(1) << endl;
  cout << message.placeList.get(6) << endl;
  message.Print(6, "Hey", 5);
  message.Print(1, "Hey", 5);
  message.Print(1, "Hey", 1);
  message.Print(1, "Hey", 2);
  message.Print(1, "Hey", 3);
}