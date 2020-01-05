//
// Created by shon on 27.12.2019.
//

#ifndef EX3_1_EXPRESSION_VALUE_H_
#define EX3_1_EXPRESSION_VALUE_H_

#include "Expression.h"

using namespace std;


class Value: public Expression {
 private:
  double value;

 public:
  // constructor
  Value(double val);

  Value(string x);

  // destructor
  ~Value();

  double calculate();

};

#endif //EX3_1_EXPRESSION_VALUE_H_
