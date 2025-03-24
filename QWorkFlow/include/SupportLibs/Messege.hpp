#ifndef MESSEAGE_HPP
#define MESSEAGE_HPP

#include <iostream>
#include <map>

#define str std::string

/// @brief A class for print message.
class Message {
 private:
  str str_modelName;

 public:
  Message(str str_modelName);
  ~Message();
  bool Print(str str_place, str str_message, int int_messageType);
  bool Print(int int_place, str str_message, int int_messageType);

  /// @brief A class for store and get the function place list.
  class PlaceList {
   private:
    std::map<int, std::string> map_placeList;

   public:
    PlaceList();
    ~PlaceList();
    bool add(int int_place, str str_place);
    bool add(str str_place);
    str get(int int_place);
  };

  PlaceList placeList;
};

// Message src site
Message::Message(str str_modelName) { Message::str_modelName = str_modelName; }
Message::~Message() {}

bool Message::Print(str str_place, str str_message, int int_messageType) {
  switch (int_messageType) {
    case 1: {
      std::cout << "I:";
      break;
    }
    case 2: {
      std::cout << "W:";
      break;
    }
    case 3: {
      std::cout << "E:";
      break;
    }
    default:
      std::cerr << "Invalid message type: "
                << static_cast<int>(int_messageType);
      break;
  }
  std::cout << "In model:" << Message::str_modelName << ";";
  std::cout << "In Place:" << str_place << ";";
  std::cout << "Got:" << str_message << "\n";
}
bool Message::Print(int int_place, str str_message, int int_messageType) {
  Message::Print(placeList.get(int_place), str_message, int_messageType);
}

// Message::PlaceList src site
Message::PlaceList::PlaceList() {}
Message::PlaceList::~PlaceList() {}
bool Message::PlaceList::add(int int_place, str str_place) {}
bool Message::PlaceList::add(str str_place) {}
str Message::PlaceList::get(int int_place) {}

#endif