//
// Created by shon on 20.12.2019.
//

#ifndef EX3_1_DATA_DATA_H_
#define EX3_1_DATA_DATA_H_

#include <mutex>

#include <unordered_map>
#include "../serverAndClient/TcpClient.h"
#include "../other/Var.h"

using namespace std;


class Data {
 public:
  Data(TcpClient *client);
  ~Data();


  void addToGenericMap(string buf);

  void addVar(Var *var ,string name);
  void addVar(Var *var);

  bool isValidlVar(const string &var);
  Var* getVarFromMap(const string &name);

  void addSimAndVar(Var *var, string path);
  void sendFromClient(const string &name, double value);
  void addSim(Var *var);



 private:
  unordered_map<string, double> _genericSmall;
  unordered_map<string, Var *> _symbolTable;
  unordered_map<string, Var *> _simTable;
  TcpClient *_client;
  mutex _locker;

  void creatGenericMap();
  void addToMapsFromServer(pair<string, double> pair);
  bool isXmlComm(const string &str);


};
#endif //EX3_1_DATA_DATA_H_
