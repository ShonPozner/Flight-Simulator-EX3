//
// Created by shon on 27.12.2019.
//

#include "WhileComm.h"
int WhileComm::execute(vector<string> &lexer, int i,Data *d) {
  //set the fild in conditionParser
  i = i + setFild(lexer,i,d);
  int counter = 1;
  bool flage = false;
  // if condition true, execute all commands in sequence and loop back
  while (conditionTrue()) {
      counter = parser(lexer,i,d);
      flage = true;
    }
  if (flage) {
    return _paramter + counter + 1;
  } else {
    // Does not enter loop so we count until receiving }
    while (lexer[i] != "}") {
      i++;
      counter++;
    }
    return _paramter + counter;
  }
}
