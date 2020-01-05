//
// Created by shon on 23.12.2019.
//

#include "ValComm.h"
#include "../other/HelpString.h"
#include "../other/shuntingYard.h"
ValComm::ValComm(): Command(1) {}

/**
 * execute -
 * Finding the variable in the variables
 * If there is = insertion value of the expression to the variable
 * */
int ValComm::execute(vector<string> &lexer, int i, Data *d) {
  Var *var = d->getVarFromMap(lexer[i]);
  string str = lexer[i+1];
  if (str == "=") {
    string val = lexer[i+2];
    _Exp = shuntingYard::shunting(val, d);
    var->setValue(_Exp->calculate());
    d->sendFromClient(var->getSim(),var->getValue());
    return 3;
  }
  return 0;
}
ValComm::~ValComm() {
  delete _Exp;
}

