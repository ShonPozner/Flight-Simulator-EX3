/*********************************************
* Div class -
* Defining a division operation.
**********************************************/
#include <iostream>
#include "Value.h"
#include "Div.h"
using namespace std;
// constructor
Div::Div(Expression *x1, Expression *x2) {
  right = x1;
  left = x2;
}
// destructor
Div::~Div(){
  if (right != nullptr) {
    delete right;
  }
  if (left != nullptr) {
    delete left;
  }}

double Div::calculate() {
  double tempR = right->calculate();
  double tempL = left->calculate();
  // test if division by zero
  try
  {
    if (tempL == 0) {
      throw "division by zero";
    }
    return tempR / tempL;
  }
  catch(int ex)
  {
    return 0;
  }
}

