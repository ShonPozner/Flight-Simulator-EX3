/*********************************************
* UMinus class -
* Defining a operations of UMinus (Unary Operator).
**********************************************/

#include "UMinus.h"

// constructor
UMinus::UMinus(Expression *x1) {
  exp = x1;
}
// destructor
UMinus::~UMinus() {
  if (exp != nullptr) {
    delete exp;
  }
}

double UMinus::calculate() {
  double temp = exp->calculate();
  return (-1 *temp);
}