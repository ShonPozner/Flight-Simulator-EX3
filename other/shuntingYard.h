//
// Created by shon on 27.12.2019.
//

#ifndef EX3_1_OTHER_SHUNTINGYARD_H_
#define EX3_1_OTHER_SHUNTINGYARD_H_

#include "../Expression/Expression.h"
#include "../data/Data.h"
class shuntingYard {
 public:
  static Expression *shunting(string s, Data *d);
};

#endif //EX3_1_OTHER_SHUNTINGYARD_H_
