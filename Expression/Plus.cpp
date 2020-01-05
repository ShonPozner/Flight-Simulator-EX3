/*********************************************
* Plus class -
* Defining a pluse operation.
**********************************************/
#include "Plus.h"

// constructor
Plus::Plus(Expression *x1, Expression *x2) {
  right = x1;
  left = x2;
}
// destructor
Plus::~Plus(){
  if (right != nullptr) {
    delete right;
  }
  if (left != nullptr) {
    delete left;
  }}

double Plus::calculate() {
  double temp = right->calculate() + left->calculate();
  return temp;
}

