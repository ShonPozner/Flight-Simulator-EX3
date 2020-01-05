//
// Created by shon on 20.12.2019.
//

#include "TcpServer.h"
/**
 * Inilaize server how listen to port (5400)
 * and wait for connection.
 * @param port
 * @return _accVal
 */
int TcpServer::setUp(int port) {

  int opt = 1;
  struct sockaddr_in server, client;


  // Creating socket file descriptor
  if ((_serverSocket = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP)) == 0) {
    perror("socket failed");
    exit(EXIT_FAILURE);
  }

  if (setsockopt(_serverSocket, SOL_SOCKET, SO_REUSEADDR, &opt,sizeof(opt))) {
    perror("setsockopt");
    exit(EXIT_FAILURE);
  }
  server.sin_family = AF_INET;
  server.sin_addr.s_addr = INADDR_ANY;
  server.sin_port = htons(port);

  // Forcefully attaching socket to the port 8080
  if (bind(_serverSocket, (struct sockaddr *) &server, sizeof(server)) < 0) {
    perror("bind failed");
    exit(EXIT_FAILURE);
  }


  if (listen(_serverSocket, 5) < 0) {
    perror("listen");
    exit(EXIT_FAILURE);
  }

  //Accept and incoming connection
  puts("Waiting for incoming connections...");
  socklen_t addrlen = sizeof(sockaddr_in);
  _accVal = accept(_serverSocket, (struct sockaddr *) &client, &addrlen);
  if (_accVal < 0) {
    cout << "Error!" << endl;
  } else
    cout << "Connection accepted, starting listener thread" << endl;
  char buf[MAXPACKETSIZE];
  memset(buf, 0, MAXPACKETSIZE);
  read(_accVal, &buf, 1);
  return _accVal;
}


/**
 * Read line by line from the port
 * and put it on the map (Data)
 *
 * @param soct @param data
*/
void *TcpServer::taskS(int soct,Data *data) {
  int newSockfd = soct;
  int n;
  char msg[MAXPACKETSIZE];
  while (true) {
    memset(msg, 0, MAXPACKETSIZE);
    n = read(newSockfd, msg, MAXPACKETSIZE);
    data->addToGenericMap(string(msg));
    if (n == 0) {
      close(newSockfd);
      break;
    }
  }
  pthread_exit(0);
}






