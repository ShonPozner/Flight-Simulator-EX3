//
// Created by shon on 27.12.2019.
//

#ifndef EX3_1_EXPRESSION_VARIABLE_H_
#define EX3_1_EXPRESSION_VARIABLE_H_

#include <string>
#include "Expression.h"

using  namespace std;

class Variable: public Expression {
  string name;
  double value;


 public:
  // constructor
  Variable(string name1, double value1);
  // constructor 2
  Variable(double value1, string name1);
  // constructor
  Variable(string name1);
  // destructor
  ~Variable();

  // Define prefix increment operator
  Variable& operator ++();

  // Define profix increment operator
  Variable& operator ++(int);

  // Define prefix decrement operator
  Variable& operator --();

  // Define profix decrement operator
  Variable& operator --(int);

  Variable& operator +=(double);

  Variable& operator -=(double);

  double calculate();


};

#endif //EX3_1_EXPRESSION_VARIABLE_H_
