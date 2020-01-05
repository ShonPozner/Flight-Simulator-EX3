//
// Created by shon on 21.12.2019.
//

#include "Var.h"
Var::Var(string name) {

  _name = name;
  _value = 0;
  _adres = "";
  _mode = false;

}
void Var::setValue(double val) {
  _value = val;
}
double Var::getValue() {
  return _value;
}
string Var::getSim() {
  return _adres;
}
void Var::setSim(string sim) {
  _adres = sim;
}
bool Var::ifHaveSim() {
  return (_adres.empty());
}
string Var::getName() {
  return _name;
}
void Var::replace() {
  string temp =_name;
  _name = _adres;
  _adres = temp;
}
 void Var::setModeOn() {
  _mode = true;
}
bool Var::getMode() {
  return _mode;
}
double Var::calculate() {
  return getValue();
}


