//
// Created by shon on 27.12.2019.
//

#ifndef EX3_1_COMMAND_CONDITIONPARSER_H_
#define EX3_1_COMMAND_CONDITIONPARSER_H_

#include "Command.h"
#include "../Expression/Expression.h"
#include "../LexerAndParser/LaxerAndParser.h"

using namespace std;

class ConditionParser : public Command,Parser{

 protected:
  Expression *_leftExp, *_rightExp;
  std::string _condition;

  public:
  ConditionParser();
  ~ConditionParser();

  virtual int execute(vector<string> &lexer, int i,Data *d) = 0;

  int setFild(vector<string> &lexer, int i,Data *d);
  int parser(vector<string> &lexer, int i, Data *d);
  bool conditionTrue();

};

#endif //EX3_1_COMMAND_CONDITIONPARSER_H_
