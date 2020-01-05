//
// Created by shon on 20.12.2019.
//

#include <sstream>
#include "ConnectControlClientComm.h"
#include "../other/HelpString.h"
#include "../other/shuntingYard.h"

/**
 * execute - get the file from the command
 * Removes brackets from the expressions
 * Separation of data (separated by space)
 * Insert the separated data into a client startup command
 * */
int ConnectControlClientComm::execute(vector<string> &lexer, int i,Data *d) {
  string str = lexer[i+1];
  vector<string> token;
  //Removes brackets from the expressions
  if (str.at(0) == '(') {
    str = HelpString::RemoveBrackets(str);
  }
  //Separation of data (separated by space)
  stringstream lineStream(str);
  string cell;
  while(std::getline(lineStream, cell, ' ')) {
    if (cell.at(0) == '\"') {
      cell = HelpString::RemoveQuotationMark(cell);
    }
    token.push_back(cell);
  }
  string ip = token[0];
  _Exp =  shuntingYard::shunting(token[1], d);
  _client->setup(ip,(int)_Exp->calculate());
  cout<<"ConnectCommand!"<<endl;
  return this->_paramter + 1;
}


ConnectControlClientComm::ConnectControlClientComm(TcpClient *client):Command(1) {
    _client = client;
  }
ConnectControlClientComm::~ConnectControlClientComm() {
  delete _client;
  delete _Exp;
}



