//
// Created by shon on 20.12.2019.
//

#include "Data.h"
#include "../other/xmlCommand.h"
#include "../other/HelpString.h"
#include "../command/OpenDataServerComm.h"


Data::Data(TcpClient *client) {
  _client =client;
  creatGenericMap();
}
void Data::creatGenericMap() {
  this->_genericSmall.emplace("instrumentation/airspeed-indicator/indicated-speed-kt", 0);
  this->_genericSmall.emplace("sim/time/warp", 0);
  this->_genericSmall.emplace("controls/switches/magnetos", 0);
  this->_genericSmall.emplace("instrumentation/heading-indicator/offset-deg", 0);
  this->_genericSmall.emplace("instrumentation/altimeter/indicated-altitude-ft", 0);
  this->_genericSmall.emplace("instrumentation/altimeter/pressure-alt-ft", 0);
  this->_genericSmall.emplace("instrumentation/attitude-indicator/indicated-pitch-deg", 0);
  this->_genericSmall.emplace("instrumentation/attitude-indicator/indicated-roll-deg", 0);
  this->_genericSmall.emplace("instrumentation/attitude-indicator/internal-pitch-deg", 0);
  this->_genericSmall.emplace("instrumentation/attitude-indicator/internal-roll-deg", 0);
  this->_genericSmall.emplace("instrumentation/encoder/indicated-altitude-ft", 0);
  this->_genericSmall.emplace("instrumentation/encoder/pressure-alt-ft", 0);
  this->_genericSmall.emplace("instrumentation/gps/indicated-altitude-ft", 0);
  this->_genericSmall.emplace("instrumentation/gps/indicated-ground-speed-kt", 0);
  this->_genericSmall.emplace("instrumentation/gps/indicated-vertical-speed", 0);
  this->_genericSmall.emplace("instrumentation/heading-indicator/indicated-heading-deg", 0);
  this->_genericSmall.emplace("instrumentation/magnetic-compass/indicated-heading-deg", 0);
  this->_genericSmall.emplace("instrumentation/slip-skid-ball/indicated-slip-skid", 0);
  this->_genericSmall.emplace("instrumentation/turn-indicator/indicated-turn-rate", 0);
  this->_genericSmall.emplace("instrumentation/vertical-speed-indicator/indicated-speed-fpm", 0);
  this->_genericSmall.emplace("controls/flight/aileron", 0);
  this->_genericSmall.emplace("controls/flight/elevato", 0);
  this->_genericSmall.emplace("controls/flight/rudder", 0);
  this->_genericSmall.emplace("controls/flight/flaps", 0);
  this->_genericSmall.emplace("controls/engines/engine/throttle", 0);
  this->_genericSmall.emplace("controls/engines/current-engine/throttle", 0);
  this->_genericSmall.emplace("controls/switches/master-avionics", 0);
  this->_genericSmall.emplace("controls/switches/starter", 0);
  this->_genericSmall.emplace("engines/active-engine/auto-start", 0);
  this->_genericSmall.emplace("controls/flight/speedbrake", 0);
  this->_genericSmall.emplace("sim/model/c172p/brake-parking", 0);
  this->_genericSmall.emplace("controls/engines/engine/primer", 0);
  this->_genericSmall.emplace("controls/engines/current-engine/mixture", 0);
  this->_genericSmall.emplace("controls/switches/master-bat", 0);
  this->_genericSmall.emplace("controls/switches/master-alt", 0);
  this->_genericSmall.emplace("engines/engine/rpm", 0);
}

/**
 * addToGenericMap -
 * Receive buf with all aircraft data
 * loop over all the command in the xml
 * split the buf in "," and update the value
 * */
void Data::addToGenericMap(string buf) {
  auto it = VectorXml.begin();
  size_t pos = 0;
  while (!buf.empty()) {
    if (it == VectorXml.end())
      break;
    pos = buf.find(',');
    string splitted = buf.substr(0, pos);
    //get the pair that go in the map, and make the string to double.
    pair<string, double> p = make_pair(*it, HelpString::fromStrToNum(splitted, "double"));
    addToMapsFromServer(p);
    buf.erase(0, pos + 1);
    it++;
  }
}
/**
 * addToMapsFromServer -
 * Split the pair into command and value
 * Lock the thard and update the simTable and symbolTable
 * */
void Data::addToMapsFromServer(pair<string, double> pairIn) {
  string xmlComm = pairIn.first;
  double val = pairIn.second;
  unique_lock<mutex> lock(_locker);
  if (isXmlComm(xmlComm)) {
    _genericSmall[xmlComm] = val;
  }
  if (_simTable.count(xmlComm) > 0) {
    _simTable[xmlComm]->setValue(val);
    string adress= _simTable.find(xmlComm)->second->getName();
    if (_symbolTable.count(adress) > 0) {
      _symbolTable[adress]->setValue(val);
    }
  }
  lock.unlock();
}

bool Data::isXmlComm(const string &str) {
  return (_genericSmall.count(str) > 0);
}

bool Data::isValidlVar(const string &var) {
  return (_symbolTable.count(var) > 0);
}

Data::~Data() {
  for (auto & it : _symbolTable) {
    if (it.second != nullptr) {
      delete (it.second);
      it.second = nullptr;
    }
  }
  for (auto & it : _simTable) {
    if (it.second != nullptr) {
      delete (it.second);
      it.second = nullptr;
    }
  }
}

/**
 * add to symbole table name and var
 * lock the thread..
 * @param var  the var (allocated from VarCommand)
 * @param name  name of the var
 */
void Data::addVar(Var *var, string name) {
  unique_lock<mutex> lock(_locker);
  _symbolTable.emplace(name,var);
  lock.unlock();
}


/**
 * get a var from the symbolTable
 * lock the thread..
 * @param name  name of the var
 * @return temp *var
 */
Var* Data::getVarFromMap(const string &name) {
  unique_lock<mutex> lock(_locker);
  Var* temp = _symbolTable.at(name);
  lock.unlock();
  return temp;

}

void Data::sendFromClient(const string &name, double value) {
  if (name != "") {
    string message = "set /" + name + " " + to_string(value) + "\r\n";
    cout << message << endl;
    _client->send(message);
  }
}

/**
 * add path and var
 * @param var
 * @param path
 */
void Data::addSimAndVar(Var *var, string sim) {
  unique_lock<mutex> lock(_locker);
  _simTable.emplace(sim, var);
  _genericSmall[sim] = var->getValue();
  sendFromClient(sim, var->getValue());
  lock.unlock();
}
/**
 * add path and var
 * @param var
 */
void Data::addSim(Var *var) {
  unique_lock<mutex> lock(_locker);
  _simTable.emplace(var->getSim(),var);
  lock.unlock();
}
void Data::addVar(Var *var) {
  unique_lock<mutex> lock(_locker);
  _symbolTable.emplace(var->getName(),var);
  lock.unlock();
}
