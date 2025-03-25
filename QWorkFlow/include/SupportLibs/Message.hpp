#ifndef MESSEAGE_HPP
#define MESSEAGE_HPP

#include <iostream>
#include <map>

#include "publicDefine.h"

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

// ##### Message src site #####

/// @brief Init Message class.
/// @param str_modelName A string as the model name.
Message::Message(str str_modelName) { Message::str_modelName = str_modelName; }
Message::~Message() {}

/// @brief Print Message to console.
/// @param str_place A string as function place.
/// @param str_message A string as the message need to print.
/// @param int_messageType A int as the Message type.
/// @return A boolen as if this function run sucessful.
bool Message::Print(str str_place, str str_message, int int_messageType) {
  try {
    switch (int_messageType) {
      case 1: {
        cout << "I: ";
        break;
      }
      case 2: {
        cout << "W: ";
        break;
      }
      case 3: {
        cout << "E: ";
        break;
      }
      default:
        std::cerr << "Invalid messageType: "
                  << static_cast<int>(int_messageType) << "; ";
        break;
    }
    cout << "In model: " << Message::str_modelName << "; ";
    cout << "In Place: " << str_place << "; ";
    cout << "Got: " << str_message << "\n";
    return true;
  } catch (const char* msg) {
    std::cerr << msg << endl;
    return false;
  }
}

/// @brief Print Message to console.
/// @param int_place A int as function place iter.
/// @param str_message A string as the message need to print.
/// @param int_messageType A int as the Message type.
/// @return A boolen as if this function run sucessful.
bool Message::Print(int int_place, str str_message, int int_messageType) {
  return Message::Print(placeList.get(int_place), str_message, int_messageType);
}

// ##### Message::PlaceList src site #####
Message::PlaceList::PlaceList() {}
Message::PlaceList::~PlaceList() {}

/// @brief Add a int as key, and a string as value to Placelist.
/// @param int_place A int as function place iter.
/// @param str_place A string as function place.
/// @return A boolen as if this function run sucessful.
bool Message::PlaceList::add(int int_place, str str_place) {
  if (Message::PlaceList::get(int_place) == "NA") {
    try {
      map_placeList.insert(std::pair<int, std::string>(int_place, str_place));
    } catch (const char* msg) {
      std::cerr << msg << endl;
      return false;
    }
    return true;
  } else {
    return false;
  }
}

/// @brief Add a string as value to Placelist, the int iter will followed by the
/// last one.
/// @param str_place A string as function place.
/// @return A boolen as if this function run sucessful.
bool Message::PlaceList::add(str str_place) {
  std::size_t size_placeListSize = map_placeList.size();
  return Message::PlaceList::add(size_placeListSize, str_place);
}

/// @brief Get the string function place for the int itter.
/// @param int_place  A int as function place iter.
/// @return A boolen as if this function run sucessful.
str Message::PlaceList::get(int int_place) {
  auto it = map_placeList.find(int_place);
  if (it != map_placeList.end()) {
    return it->second;
  } else {
    return "NA";
  }
}

#endif