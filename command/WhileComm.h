//
// Created by shon on 27.12.2019.
//

#ifndef EX3_1_COMMAND_WHILECOMM_H_
#define EX3_1_COMMAND_WHILECOMM_H_

#include "ConditionParser.h"

class WhileComm: public ConditionParser {
  // Inherit constructor from ConditionParser
  using ConditionParser::ConditionParser;

 public:
  int execute(vector<std::string> &lexer, int i, Data *d);
};


#endif //EX3_1_COMMAND_WHILECOMM_H_
