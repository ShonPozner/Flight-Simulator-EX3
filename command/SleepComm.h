//
// Created by shon on 23.12.2019.
//

#ifndef EX3_1_COMMAND_SLEEPCOMM_H_
#define EX3_1_COMMAND_SLEEPCOMM_H_

#include "Command.h"
class SleepComm : public Command{

 public:

  SleepComm();
  ~SleepComm();

  int execute(vector<string> &lexer, int i,Data *d);

 private:
  Expression *_Exp;

};

#endif //EX3_1_COMMAND_SLEEPCOMM_H_
