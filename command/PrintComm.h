//
// Created by shon on 22.12.2019.
//

#ifndef EX3_1_COMMAND_PRINTCOMM_H_
#define EX3_1_COMMAND_PRINTCOMM_H_

#include <iostream>
#include "Command.h"
using namespace std;


class PrintComm: public Command{
 public:
  PrintComm();
  ~PrintComm();

  int execute(vector<string> &lexer, int i,Data *d);

 private:
  Expression *_Exp;


};

#endif //EX3_1_COMMAND_PRINTCOMM_H_
