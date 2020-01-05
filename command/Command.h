//
// Created by shon on 19.12.2019.
//

#ifndef EX3_1__COMMAND_H_
#define EX3_1__COMMAND_H_
#include <iostream>
#include <fstream>
#include <iostream>
#include <vector>
#include "../data/Data.h"


class Command{
 protected:
  int _paramter;

 public:
  virtual ~Command() = default;
  virtual int execute(vector<std::string> &lexer, int i,Data *d)=0;

  int getParmeter() {
    return _paramter;
  }

  Command(int num) {
    _paramter = num;
  }
};


#endif //EX3_1__COMMAND_H_
