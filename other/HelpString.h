//
// Created by shon on 21.12.2019.
//

#ifndef EX3_1_OTHER_HELPSTRING_H_
#define EX3_1_OTHER_HELPSTRING_H_
#include <iostream>
#include <fstream>
using namespace std;


class HelpString {
 public:
  static double  fromStrToNum(string &str, const string &type);

  static string RemoveQuotationMark(string path);
  static string RemoveSlash(string path);
  static string RemoveSlashAndQuo(string path);
  static string RemoveBrackets(string path);
  static string RemoveSlashAndQuoAndBrack(string path);

};

#endif //EX3_1_OTHER_HELPSTRING_H_
