#include <iostream>
#include "command/OpenDataServerComm.h"
#include "LexerAndParser/LaxerAndParser.h"
#include <vector>
#include <unordered_map>

using namespace std;


/**
 * start - get the file from the command
 * Initialization of the data and the lexer.
 * executing lexer and parser  */

void start(int argc, char *argv[]) {
  if (argc > 1) {
    string fileName = argv[1];
    TcpClient *client = new TcpClient();
    Data *data = new Data(client);
    TcpServer *server = new TcpServer();
    LaxerAndParser *lax = new LaxerAndParser(fileName, data, client, server);
    lax->getLexer();
    lax->parser();

  } else {
    cout<<"File name not received, please try again"<<endl;
  }

}


int main(int argc, char *argv[]) {
  start(argc,argv);
  return 0;
}


