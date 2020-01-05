/*********************************************
* Mul class -
* Defining a mult operation.
**********************************************/

#include "Mul.h"

// constructor
Mul::Mul(Expression *x1, Expression *x2) {
  right = x1;
  left = x2;
}
// destructor
Mul::~Mul(){
  if (right != nullptr) {
    delete right;
  }
  if (left != nullptr) {
    delete left;
  }
}


double Mul::calculate() {
  double temp = right->calculate() * left->calculate();
  return temp;
}

