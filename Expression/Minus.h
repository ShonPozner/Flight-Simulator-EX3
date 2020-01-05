/*********************************************
* Minus class -
* Defining a Minus operation.
**********************************************/
#ifndef EX3_1_EXPRESSION_MINUS_H_
#define EX3_1_EXPRESSION_MINUS_H_


#include "Expression.h"
#include "BinaryExpression.h"

  class Minus:public BinaryExpression {

   public:
    // constructor
    Minus(Expression *right, Expression *left);

    // destructor
    ~Minus();

    double calculate();

  };

#endif //EX3_1_EXPRESSION_MINUS_H_
