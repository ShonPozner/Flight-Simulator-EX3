/*********************************************
* Mul class -
* Defining a mult operation.
**********************************************/

#ifndef EX3_1_EXPRESSION_MUL_H_
#define EX3_1_EXPRESSION_MUL_H_

#include "Expression.h"
#include "BinaryExpression.h"

class Mul: public BinaryExpression {

 public:
  // constructor
  Mul(Expression *right, Expression *left);

  // destructor
  ~Mul();

  double calculate();

};

#endif //EX3_1_EXPRESSION_MUL_H_
