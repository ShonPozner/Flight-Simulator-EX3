//
// Created by shon on 27.12.2019.
//

#ifndef EX3_1_EXPRESSION_UPLUS_H_
#define EX3_1_EXPRESSION_UPLUS_H_

#include "UnaryOperator.h"

class UPlus: public UnaryOperator {
 public:
  // constructor
  UPlus(Expression *x1);

  // destructor
  ~UPlus();

  double calculate();

};

#endif //EX3_1_EXPRESSION_UPLUS_H_
