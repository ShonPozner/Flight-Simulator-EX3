//
// Created by shon on 20.12.2019.
//

#ifndef EX3_1__TCPSERVER_H_
#define EX3_1__TCPSERVER_H_

#include <netinet/in.h>
#include <iostream>
#include <unistd.h>
#include <cstring>
#include <stdexcept>
#include <vector>
#include <fstream>
#include "../data/Data.h"
#include <cstring>
#include <stdexcept>
#include <vector>
#include <fstream>
#include "../other/xmlCommand.h"

#define MAXPACKETSIZE 500
using namespace std;


class TcpServer {
 public:
  TcpServer() = default;
  int setUp(int port);
  static void *taskS(int soct,Data *data);

 private:
  int _serverSocket;
  int _accVal;
  struct sockaddr_in _serverAddress;
  struct sockaddr_in _clientAddress;
};

typedef struct arg_struct_server {
  int arg1;
  Data *arg2;
} TcpStruct;

#endif //EX3_1__TCPSERVER_H_
