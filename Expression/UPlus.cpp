/*********************************************
* UPlus class -
* Defining a operations of UPlus (Unary Operator).
**********************************************/

#include "UPlus.h"

// constructor
UPlus::UPlus(Expression *x1) {
  exp = x1;
}
// distructor
UPlus::~UPlus() {
  if (exp != nullptr) {
    delete exp;
  }
}

double UPlus::calculate() {
  double temp = exp->calculate();
  return temp;
}