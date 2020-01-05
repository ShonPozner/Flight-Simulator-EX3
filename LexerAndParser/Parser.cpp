//
// Created by shon on 27.12.2019.
//

#include "Parser.h"
#include "../command/DefineVarComm.h"
#include "../command/PrintComm.h"
#include "../command/ValComm.h"
#include "../command/SleepComm.h"
#include "../command/WhileComm.h"
#include "../command/IfComm.h"



Command *Parser::getACommand(string str) {
  return _parser_map.find(str)->second;
}
//set a map_command
void Parser::fillMapConmm() {
  _parser_map.emplace("var", new DefineVarComm());
  _parser_map.emplace("Print", new PrintComm());
  _parser_map.emplace("Sleep", new SleepComm());
  _parser_map.emplace("varComm", new ValComm());
  _parser_map.emplace("while", new WhileComm());
  _parser_map.emplace("if", new IfComm());

}


Parser::Parser() = default;

Parser::~Parser() {
  // check if the map isn't empty
  for (unordered_map<string,Command*>::iterator it = _parser_map.begin();
       it != _parser_map.end(); ++it) {
    //delete map and place null pointer;
    delete it->second;
  }
}
//set a map_command
void Parser::fillMapConmm(TcpClient *client, TcpServer *server) {
  _parser_map.emplace("openDataServer",new OpenDataServerComm(server));
  _parser_map.emplace("connectControlClient", new ConnectControlClientComm(client));
  fillMapConmm();
}



