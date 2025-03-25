#include "../../../../QWorkFlow/include/SupportLibs/Message.hpp"

#include <iostream>

void check(str func, str get, str need) {
  cout << "***In_Test: " << func << ";";
  if (get == need) {
    cout << "***OK!" << endl << endl;
  } else {
    cout << "***NO!" << endl << endl;
  }
}

void check(str func, bool get, bool need) {
  cout << "***In_Test: " << func << ";";
  if (get == need) {
    cout << "***OK!" << endl << endl;
  } else {
    cout << "***NO!" << endl << endl;
  }
}

int main() {
  Message message("Test");

  check("placeList addStr", message.placeList.add("place1"), true);
  check("placeList IterAddStr", message.placeList.add(1, "place2"), true);
  check("placeList WIterAddStr", message.placeList.add(0, "place2"), false);

  check("placeList getIter", message.placeList.get(0), "place1");
  check("placeList getIter", message.placeList.get(1), "place2");
  check("placeList getWIter", message.placeList.get(6), "NA");
  check("placeList getWIter", message.placeList.get(-1), "NA");

  check("message printWIterWType", message.Print(6, "Hey", 5),
        "Invalid messageType: 5; In model: Test; In Place: NA; Got: Hey");
  check("message printIterWType", message.Print(1, "Hey", 5),
        "Invalid messageType: 5; In model: Test; In Place: place2; Got: Hey");
  check("message printIterTypeI", message.Print(1, "Hey", 1),
        "I: In model: Test; In Place: place2; Got: Hey");
  check("message printIterTypeW", message.Print(1, "Hey", 2),
        "W: In model: Test; In Place: place2; Got: Hey");
  check("message printIterTypeE", message.Print(1, "Hey", 3),
        "E: In model: Test; In Place: place2; Got: Hey");
}