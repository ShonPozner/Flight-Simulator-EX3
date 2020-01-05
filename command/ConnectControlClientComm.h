//
// Created by shon on 19.12.2019.
//

#ifndef EX3_1__CONNECTCONTROLCLIENTCOMM_H_
#define EX3_1__CONNECTCONTROLCLIENTCOMM_H_
#include "Command.h"
#include "../serverAndClient/TcpClient.h"
#include <iostream>
#include <vector>
using namespace std;

class ConnectControlClientComm: public Command
{
 public:
  ConnectControlClientComm(TcpClient *client);
  virtual ~ConnectControlClientComm();

  int execute(vector<string> &lexer, int i,Data *d);

 private:
  Expression *_Exp;
  TcpClient* _client;


};
#endif //EX3_1__CONNECTCONTROLCLIENTCOMM_H_
