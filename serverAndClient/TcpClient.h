//
// Created by shon on 20.12.2019.
//

#ifndef EX3_1_SERVERANDCLIENT_TCPCLIENT_H_
#define EX3_1_SERVERANDCLIENT_TCPCLIENT_H_


#include <iostream>
#include <string.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <netdb.h>
#include <bits/basic_string.h>
#include <netinet/in.h>
#include <unistd.h>
#include <thread>


using namespace std;

class TcpClient {
 public:
  TcpClient() {
    _soc= -1;
  }

  bool setup(string ip, int port);

  bool send(string massage);
 private:
  int _soc;
  struct sockaddr_in server;

  void exit();
};

#endif //EX3_1_SERVERANDCLIENT_TCPCLIENT_H_
