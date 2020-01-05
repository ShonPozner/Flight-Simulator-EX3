//
// Created by shon on 21.12.2019.
//

#ifndef EX3_1_COMMAND_DEFINEVARCOMM_H_
#define EX3_1_COMMAND_DEFINEVARCOMM_H_
#include "Command.h"
#include <iostream>
#include <vector>
using namespace std;

class DefineVarComm: public Command {
 public:
  int execute(vector<string> &lexer, int i,Data *d);

  DefineVarComm():Command(1){};

  ~DefineVarComm();

 private:
  Expression *_Exp;


};

#endif //EX3_1_COMMAND_DEFINEVARCOMM_H_
