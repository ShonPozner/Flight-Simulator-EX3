//
// Created by shon on 21.12.2019.
//

#include <algorithm>
#include "HelpString.h"
double HelpString::fromStrToNum(string &str, const string &type) {
  try {
    if (type.compare("int") == 0)
      return stoi(str);
    if (type.compare("double") == 0)
      return stod(str);
  } catch (exception &e) {
    printf("OpenDataServerCommand->fromStringToNum: %s", e.what());
    exit(EXIT_FAILURE);
  }
  return 0;
}

string HelpString::RemoveSlash(string path) {
  if(path.at(0) == '/')
  path.erase(path.begin());
  return path;
}

string HelpString::RemoveQuotationMark(string path) {
  path.erase(remove(path.begin(), path.end(), '\"'), path.end());
  return path;
}

string HelpString::RemoveSlashAndQuo(string path) {
  string result = RemoveQuotationMark(path);
  return RemoveSlash(result);
}

string HelpString::RemoveBrackets(string path) {
  if ((path.at(0) == '(') && ((path.at(path.size()-1) = ')'))) {
    path = path.substr(1,path.size()-2);
  }
  return path;
}

string HelpString::RemoveSlashAndQuoAndBrack(string path) {
  path = RemoveBrackets(path);
  return RemoveSlashAndQuo(path);
}

