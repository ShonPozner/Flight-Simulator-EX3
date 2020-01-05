//
// Created by shon on 22.12.2019.
//

#include "PrintComm.h"
#include "../other/HelpString.h"
#include "../other/shuntingYard.h"
PrintComm::PrintComm(): Command(1){
}

/**
 * execute -
 * Gets the variable after the remove brackets
 * And check for any quotation marks and then removed them and print the string
 * If not than turn the input into a expression, calculate it and prints
 * */
int PrintComm::execute(vector<string> &lexer, int i, Data *d) {
  string str = lexer[i+1];
  if (str.at(0) == '(') {
    str = HelpString::RemoveBrackets(str);
    if (str.at(0) == '\"') {
      str = HelpString::RemoveQuotationMark(str);
      cout<<str<<endl;
    } else {
      _Exp = shuntingYard::shunting(str, d);
      cout << _Exp->calculate() << endl;
    }
  }
  return this->_paramter + 1;

}
PrintComm::~PrintComm() {
  delete _Exp;
}


