//
// Created by shon on 31.12.2019.
//

#ifndef EX3_1_COMMAND_IFCOMM_H_
#define EX3_1_COMMAND_IFCOMM_H_

#include "ConditionParser.h"
class IfComm: public ConditionParser {
  using ConditionParser::ConditionParser;

 public:
  int execute(vector<std::string> &lexer, int i, Data *d);

};

#endif //EX3_1_COMMAND_IFCOMM_H_
