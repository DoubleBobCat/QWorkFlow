#include <../../../QWorkFlow/include/SupportLibs/Message.hpp>

int main() {
  Message message = Message("Test");
  message.placeList.add("place1");
  message.placeList.add(0, "place2");
  message.placeList.add(1, "place2");
  message.placeList.get(1);
  message.placeList.get(6);
}