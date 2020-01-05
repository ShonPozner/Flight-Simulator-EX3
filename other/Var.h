//
// Created by shon on 21.12.2019.
//

#ifndef EX3_1_OTHER_VAR_H_
#define EX3_1_OTHER_VAR_H_
#include <string>
#include "../Expression/Expression.h"
using namespace std;


class Var :public Expression {

 public:
  explicit Var(string name);
  ~Var(){};

  virtual double calculate();

  //setrs
  void setValue(double val);
  void setSim(string sim);
  void replace();
  void setModeOn();

  //gets
  double getValue();
  string getSim();
  string getName();
  bool ifHaveSim();
  bool getMode();


 private:
 string _name;
 double _value;
 string _adres;
 //true send
 bool _mode;

};

#endif //EX3_1_OTHER_VAR_H_
