//
// Created by shon on 27.12.2019.
//

#ifndef EX3_1_EXPRESSION_EXPRESSION_H_
#define EX3_1_EXPRESSION_EXPRESSION_H_

using namespace std;
/**
 * Expression Interface
 */
class Expression {

 public:
  virtual double calculate() = 0;
  virtual ~Expression() {}
};

#endif //EX3_1_EXPRESSION_EXPRESSION_H_
