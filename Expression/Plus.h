/*********************************************
* Plus class -
* Defining a pluse operation.
**********************************************/

#ifndef EX3_1_EXPRESSION_PLUS_H_
#define EX3_1_EXPRESSION_PLUS_H_
#include "Expression.h"
#include "BinaryExpression.h"

class Plus: public BinaryExpression {

 public:
  // constructor
  Plus(Expression *right, Expression *left);

  // destructor
  ~Plus();

  double calculate();


};

#endif //EX3_1_EXPRESSION_PLUS_H_
