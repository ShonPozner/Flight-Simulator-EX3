//
// Created by shon on 20.12.2019.
//

#include "TcpClient.h"


/**
 * setup -
 * Creat a client get the ip and the port
 * and try to conect to the server 20 time if not work throw err
 * */
bool TcpClient::setup(string ip, int port) {
  cout << "Client setup!" << endl;
  if (_soc == -1) {
    _soc = socket(AF_INET, SOCK_STREAM, 0);
    if (_soc < 0) {
      perror("TcpClient->setup: ");
      ::exit(EXIT_FAILURE);
    }
  }
  if (inet_addr(ip.c_str()) == -1) {
    struct hostent *he;
    struct in_addr **addr_list;
    if ((he = gethostbyname(ip.c_str())) == NULL) {
      herror("gethostbyname");
      cout << "Failed to resolve hostname\n";
      return false;
    }
    addr_list = (struct in_addr **) he->h_addr_list;
    for (int i = 0; addr_list[i] != NULL; i++) {
      server.sin_addr = *addr_list[i];
      break;
    }
  } else {
    server.sin_addr.s_addr = inet_addr(ip.c_str());
  }
  server.sin_family = AF_INET;
  server.sin_port = htons(port);
  int connectRet;
  for (int j = 0; j <= 20; ++j) {
    connectRet = connect(_soc, (struct sockaddr *) &server, sizeof(server));
    if (connectRet < 0)
      sleep(1);
    else
      return true;
  }
  if (connectRet < 0) {
    perror("TcpClient->setup: ");
    throw runtime_error("Cannot connect to FlightGear, tried 20 times");
  }
  return true;
}


/**
 * send -
 * send a command to the server and get a reply to the massage
 * */
bool TcpClient::send(string massage) {
  cout << "Sending!" << endl;
  if (_soc != -1) {
    if (::send(_soc, massage.c_str(), strlen(massage.c_str()), 0) < 0) {
      cout << "Send failed :" << massage << endl;
      return false;
    } else {
      cout << "success to send!" << endl;
    }
  } else {
    cout << "Socket is not initialized" << endl;
    return false;
  }
  return true;
}

void TcpClient::exit() {
  shutdown(_soc,SHUT_RDWR);
  sleep(1);
  close(_soc);
}
