/*********************************************
* Variable class -
* Defining a variable and its basic operations.
**********************************************/

#include "Variable.h"
using namespace std;

// constructor
Variable::Variable(string name1, double value1) {
  name = name1;
  value = value1;
}
// constructor 2
Variable::Variable(double value1, string name1) {
  name = name1;
  value = value1;
}
// destructor
Variable::~Variable() = default;

// Define prefix increment operator
Variable& Variable::operator ++() {
  value++;
  return *this;
}
// Define profix increment operator
Variable& Variable::operator ++(int) {
  value++;
  return *this;
}
// Define prefix decrement operator

Variable& Variable::operator --() {
  value--;
  return *this;
}
// Define profix decrement operator
Variable& Variable::operator --(int) {
  value--;
  return *this;
}
// Define + and sum;
Variable& Variable::operator +=(double d) {
  value = value + (d);
  return *this;
}
// Define - and sum;
Variable& Variable::operator -=(double d) {
  value = value - (d);
  return *this;
}
// return value (number);
double Variable::calculate() {
  return value;
}
Variable::Variable(string name1) {
  name = name1;

}
