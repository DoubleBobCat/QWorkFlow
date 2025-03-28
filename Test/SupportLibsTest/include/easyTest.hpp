#ifndef EASYTEST_HPP
#define EASYTEST_HPP

#include "../../../QWorkFlow/include/SupportLibs/publicDefine.h"

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

#endif