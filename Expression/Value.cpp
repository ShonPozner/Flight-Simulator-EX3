/*********************************************
* Value class -
* Defining a Value.
**********************************************/

#include <string>
#include "Value.h"

// constructor
Value::Value(double val) {
  value = val;
}

Value::Value(string x) {
  value = stod(x);
}

// destructor
Value::~Value() = default;

double Value::calculate() {
  return value;
}


