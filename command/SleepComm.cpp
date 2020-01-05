//
// Created by shon on 23.12.2019.
//

#include "SleepComm.h"
#include "../other/HelpString.h"
#include "../other/shuntingYard.h"

/**
 * execute -
 * Gets the variable after remove brackets
 * turn the input into a expression, calculate it execute sleep command ro this thread
 * */
int SleepComm::execute(vector<string> &lexer, int i, Data *d) {
  string str = lexer[i + 1];
  str = HelpString::RemoveBrackets(str);
  _Exp = shuntingYard::shunting(str, d);
  int sleepTime = (int)(_Exp->calculate() + 0.5);
  this_thread::sleep_for(chrono::milliseconds(sleepTime));
  usleep(sleepTime);
  return _paramter + 1;
}

SleepComm::SleepComm():Command(1) {
}

SleepComm::~SleepComm() {
  delete _Exp;
}
