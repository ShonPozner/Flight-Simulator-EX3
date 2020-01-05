//
// Created by shon on 27.12.2019.
//

#ifndef EX3_1_EXPRESSION_UMINUS_H_
#define EX3_1_EXPRESSION_UMINUS_H_

/*********************************************
* UMinus class -
* Defining a operations of UMinus (Unary Operator).
**********************************************/

#ifndef EX_1_UMINUS_H
#define EX_1_UMINUS_H


#include "UnaryOperator.h"

class UMinus: public UnaryOperator {
 public:
  // constructor
  UMinus(Expression *x1);

  // destructor
  ~UMinus();

  double calculate();

};


#endif //EX_1_UMINUS_H
#endif //EX3_1_EXPRESSION_UMINUS_H_
