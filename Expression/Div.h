
/*********************************************
* Div class -
* Defining a division operation.
**********************************************/
#ifndef EX3_1_EXPRESSION_DIV_H_
#define EX3_1_EXPRESSION_DIV_H_

#include "Expression.h"
#include "BinaryExpression.h"

class Div: public BinaryExpression {
 public:
  // constructor
  Div(Expression *right, Expression *left);

  // destructor
  ~Div();

  double calculate();

};

#endif //EX3_1_EXPRESSION_DIV_H_
