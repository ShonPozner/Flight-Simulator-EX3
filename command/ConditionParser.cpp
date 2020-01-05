//
// Created by shon on 27.12.2019.
//

#include "ConditionParser.h"
#include "../other/shuntingYard.h"
#include "../LexerAndParser/LaxerAndParser.h"
#include "../LexerAndParser/Parser.h"


ConditionParser::ConditionParser():Command(4){
}

//Check if the condition is met
bool ConditionParser::conditionTrue() {
  double leftValue = _leftExp->calculate();
  double rightValue = _rightExp->calculate();

  try {
    if (_condition.at(0) == '<') {
      if (_condition.size() == 1) {
        return (leftValue < rightValue);
      } else {
        return (leftValue <= rightValue);
      }
    } else if (_condition.at(0) == '>') {
      if (_condition.size() == 1) {
        return (leftValue > rightValue);
      } else {
        return (leftValue >= rightValue);
      }
    } else if (_condition == "==") {
      double temp = leftValue - rightValue;
      return temp <= 0.000001 && temp >= -0.000001;
    } else {
      throw "ConditionParser - condition we get not valid\n";
    }
  } catch(int ex) {
    return false;
  }
}

//Initialize the class fields
int ConditionParser::setFild(vector<string> &lexer, int i, Data *d) {
  _leftExp = shuntingYard::shunting(lexer[i + 1], d);
  _condition = lexer[i + 2];
  _rightExp = shuntingYard::shunting(lexer[i + 3], d);
  return _paramter;
}

//Presser of the conditions
int ConditionParser::parser(vector<string> &lexer, int i,Data *d) {
  if (lexer[i] == "{") {
    int index = i+1;
    int count = 0;
    fillMapConmm();
    while (lexer[index] != "}") {
      int j = 1;
      Command *a;
      if (d->isValidlVar(lexer[index])) {
        a = getACommand("varComm");
      } else {
        a =getACommand(lexer[index]);
      }
      j = a->execute(lexer, index, d);
      index = index + j;
      count = count + j;
    }
    return count + 1;
  } else {
    cout<<"we dont get a { in a condition\n";
    return 1;
  }
}



ConditionParser::~ConditionParser() {
  delete _leftExp;
  delete _rightExp;
}