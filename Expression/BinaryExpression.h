/*********************************************
* BinaryOperator class -
* Defining a Binary Operator abstract class.
**********************************************/

#ifndef EX3_1_EXPRESSION_BINARYEXPRESSION_H_
#define EX3_1_EXPRESSION_BINARYEXPRESSION_H_


#include "Expression.h"

class BinaryExpression: public Expression {
 protected:
  Expression *right;
  Expression *left;
};

#endif //EX3_1_EXPRESSION_BINARYEXPRESSION_H_
