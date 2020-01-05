//
// Created by shon on 20.12.2019.
//

#ifndef EX3_1__LAXERANDPARSER_H_
#define EX3_1__LAXERANDPARSER_H_
#include "../command/OpenDataServerComm.h"
#include "../command/ConnectControlClientComm.h"
#include "../command/DefineVarComm.h"
#include "Parser.h"
#include <iostream>
#include <fstream>
#include <iostream>
#include <vector>
#include <regex>
#include <unordered_map>
using namespace std;

class LaxerAndParser: public Parser {

 public:
  explicit LaxerAndParser(string name,Data *data,TcpClient *client,TcpServer *server) ;
  ~LaxerAndParser();


  //Divide the text into words
  void getLexer();

  //help to the lexer make the line be with space in the right place
  string fixString(string line);
  //split the spacing and save the sting together in the same cell
  void readRow(stringstream &lineStream, vector<string> &data);

  //Match word to command with the map
  void parser();

 private:
  string _txtName;
  vector<string> _lexer;
  unsigned int _index;
  Data *_data;

};

#endif //EX3_1__LAXERANDPARSER_H_
