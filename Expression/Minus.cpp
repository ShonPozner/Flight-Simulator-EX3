/*********************************************
* Minus class -
* Defining a Minus operation.
**********************************************/

#include "Minus.h"
// constructor
Minus::Minus(Expression *x1, Expression *x2) {
  right = x1;
  left = x2;
}
// destructor
Minus::~Minus(){
  if (right != nullptr) {
    delete right;
  }
  if (left != nullptr) {
    delete left;
  }}

double Minus::calculate() {
  double temp = left->calculate() - right->calculate();
  return temp;
}

