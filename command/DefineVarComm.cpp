//
// Created by shon on 21.12.2019.
//

#include "DefineVarComm.h"
#include "../other/HelpString.h"
#include "../other/shuntingYard.h"

/**
 * execute -
 * Preparing a new variable by its name we received
 * Cover of the address that has been found, if any
 * Makes value entry if needed
 * */
int DefineVarComm::execute(vector<string> &lexer, int i, Data *d) {
  string name = lexer[i+1];
  Var *var = nullptr;
  //checking if there is this name in the data
  if(!d->isValidlVar(name)) {
    Var *temp = new Var(name);
    var = temp;
  } else {
    var = d->getVarFromMap(name);
  }
  try {
    //Cover of the address that has been found, if any
    string tester = lexer[i+2];
    if ((tester == "->" || tester == "<-") &&(lexer[i + 3] == "sim")) {
      string temp = lexer[i + 4];
      string nameSim = HelpString::RemoveSlashAndQuoAndBrack(temp);
      var->setSim(nameSim);
      if (tester == "->") {
        var->setModeOn();
        d->addVar(var,name);
      } else{
        d->addVar(var,name);
        d->addSim(var);
      }
      return 5;

      //if id = than set the value \ exp in the var
    } else if (tester == "=") {
      _Exp = shuntingYard::shunting(lexer[i+3], d);
      var->setValue(_Exp->calculate());
      d->addVar(var);
      return 4;
    } else {
      throw "problem at DefineVarComm the line not valid\n";
    }
  } catch (int ex) {
    return 4;
  }
}

DefineVarComm::~DefineVarComm() {
  delete _Exp;
}
