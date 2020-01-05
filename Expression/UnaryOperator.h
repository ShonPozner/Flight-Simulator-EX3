/*********************************************
* UnaryOperator class -
* Defining a UnaryOperator abstract class.
**********************************************/

#ifndef EX3_1_EXPRESSION_UNARYOPERATOR_H_
#define EX3_1_EXPRESSION_UNARYOPERATOR_H_

#include "Expression.h"

class UnaryOperator: public Expression {
 protected:
  Expression *exp;
};

#endif //EX3_1_EXPRESSION_UNARYOPERATOR_H_
