//
// Created by shon on 23.12.2019.
//

#ifndef EX3_1_COMMAND_VALCOMM_H_
#define EX3_1_COMMAND_VALCOMM_H_

#include "Command.h"
class ValComm: public Command {
 public:

  ValComm();
  int execute(vector<string> &lexer, int i,Data *d);

  ~ValComm();

 private:
  Expression *_Exp;

};

#endif //EX3_1_COMMAND_VALCOMM_H_
