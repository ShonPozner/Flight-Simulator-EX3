//
// Created by shon on 19.12.2019.
//
#include <iostream>
#include <thread>
#include <vector>

#ifndef EX3_1__OPENDATASERVERCOMM_H_
#define EX3_1__OPENDATASERVERCOMM_H_

#include "../serverAndClient/TcpServer.h"
#include "Command.h"
using namespace std;


class OpenDataServerComm: public Command
{
 public:
  OpenDataServerComm(TcpServer *server);
  virtual  ~OpenDataServerComm();

  int execute(vector<string> &lexer, int i,Data *d);



 private:
  Expression *_Exp;
  int _port;
  TcpServer *_server;
  thread _trhead;


};

#endif //EX3_1__OPENDATASERVERCOMM_H_
