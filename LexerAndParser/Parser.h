//
// Created by shon on 27.12.2019.
//

#ifndef EX3_1__PARSER_H_
#define EX3_1__PARSER_H_

#include "../command/Command.h"
#include "../serverAndClient/TcpServer.h"
class Parser {

 public:
  Parser();
  ~Parser();


 protected:
  unordered_map<string,Command*> _parser_map;
  Command* getACommand(string str);


  void fillMapConmm();
  void fillMapConmm(TcpClient *client, TcpServer *server);

};

#endif //EX3_1__PARSER_H_
