//
// Created by shon on 27.12.2019.
//

#include <string>
#include <queue>
#include <stack>
#include "shuntingYard.h"
#include "../Expression/Value.h"
#include "../Expression/Div.h"
#include "../Expression/Plus.h"
#include "../Expression/Mul.h"
#include "../Expression/Minus.h"
#include "../Expression/UMinus.h"
#include "../data/Data.h"


/**
 *Functions that help to shuntingYard
 * */



bool isdigit(char c) {
  return c >= '0' && c <= '9';
}

bool isNumberOrColons(char c)
{
  return (c >= '0' && c <= '9') || c == '.';
}
bool isOperator(char c)
{
  return c == '/' || c == '*' || c == '+' || c == '-' || c == '@';
}
bool isOperatorOrOpenCloser(char c)
{
  return c == '(' || isOperator(c);
}
bool isEnglishOrUnderscore(char c)
{
  return (c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z') || c == '_';
}

bool isEnglishOrUnderscoreOrNumber(char c)
{
  return isEnglishOrUnderscore(c) || isdigit(c);
}

// check if operator1 is before operator2
bool isBefore(char operator1, char operator2)
{
  if (operator1 == '(') {
    return false;
  }
  if (operator1 == '@') {
    return true;
  }
  if (operator1 == '/' || operator1 == '*') {
    if (operator2 == '+' || operator2 == '-') {
      //operator1 is before operator2
      return true;
    }
  }
  return false;
}



// The Shunting Yard
Expression* shuntingYard::shunting(string s,Data *d) {
  queue<string> postfix;
  stack<char> operators;

  for (unsigned int i = 0; i < s.length(); i += 1) {
    //in case of number
    if (isdigit(s[i])) {
      string number = "";
      while (isNumberOrColons(s[i])) {
        number += s[i];
        i++;
      }
      i--;
      postfix.push(number);
    } else if (s[i] == '-' && (i == 0 || isOperatorOrOpenCloser(s[i - 1]))) {
      //unary minus
      operators.push('@');
    }
      //in case of / * + -
    else if (isOperator(s[i])) {
      while (!operators.empty()) {
        char c2 = operators.top();
        if (isBefore(c2, s[i])) {
          operators.pop();
          postfix.push(string(1, c2));
        } else {
          break;
        }
      }
      operators.push(s[i]);
    } else if (s[i] == '(') {
      operators.push('(');
    } else if (s[i] == ')') {
      while (!operators.empty()) {
        char c = operators.top();
        operators.pop();

        //done
        if (c == '(') {
          break;
        }
        //push to queue
        postfix.push(string(1, c));
      }
    }

      //in case of variable
    else if (isEnglishOrUnderscore(s[i])) {
      string var = "";
      while (isEnglishOrUnderscoreOrNumber(s[i])) {
        var += string(1, s[i]);
        i++;
      }
      i--;
      postfix.push(var);
    }
  }
  while (!operators.empty()) {
    char op = operators.top();
    operators.pop();

    postfix.push(string(1, op));
  }

  //Read Reversed Polish Notation
  stack<Expression *> st;

  while (!postfix.empty()) {
    char first = postfix.front()[0];
    string str = postfix.front();

    if (isdigit(first)) {
      //number
      st.push(new Value(postfix.front()));
      postfix.pop();
    } else if (isOperator(first)) {
      postfix.pop();

      Expression *a, *b;
      //operator
      switch (first) {
        case '/':
          a = st.top();
          st.pop();
          b = st.top();
          st.pop();
          st.push(new Div(b, a));
          break;
        case '*':
          a = st.top();
          st.pop();
          b = st.top();
          st.pop();
          st.push(new Mul(b, a));
          break;
        case '+':
          a = st.top();
          st.pop();
          b = st.top();
          st.pop();
          st.push(new Plus(a, b));
          break;
        case '-':
          a = st.top();
          st.pop();
          b = st.top();
          st.pop();
          st.push(new Minus(a, b));
          break;
        case '@':
          a = st.top();
          st.pop();
          st.push(new UMinus(a));
          break;
      }
    } else {
      //Variable
      if (d->isValidlVar(postfix.front())) {
        st.push( d->getVarFromMap(postfix.front()));
      }
      postfix.pop();
    }
  }
  if (!st.empty()) {
    Expression *p = st.top();
    st.pop();
    return p;
  }
  return nullptr;
}



