//
// Created by shon on 20.12.2019.
//

#include "OpenDataServerComm.h"
#include "../other/HelpString.h"
#include "../other/shuntingYard.h"


/**
 * execute -
 * Removes brackets from the expressions
 * Insert the filds into a server startup command
 * Calls for another thread who samples flight data
 * */
int OpenDataServerComm::execute(vector<string> &lexer, int i, Data *d) {
  string str = HelpString::RemoveBrackets(lexer[i+1]);
  _Exp = shuntingYard::shunting(str, d);
  _port = _Exp->calculate();
  int soctfd = _server->setUp(_port);
  thread dataServer(TcpServer::taskS, soctfd, d);
  dataServer.detach();
  return this->_paramter + 1;
}

OpenDataServerComm::OpenDataServerComm(TcpServer *server): Command(1){
  _server = server;
}

OpenDataServerComm::~OpenDataServerComm() {
  delete _Exp;
  delete  _server;

}

