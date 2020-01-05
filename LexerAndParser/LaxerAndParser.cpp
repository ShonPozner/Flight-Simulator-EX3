//
// Created by shon on 20.12.2019.
//

#include "LaxerAndParser.h"
#include "../other/HelpString.h"
#include "../command/PrintComm.h"


LaxerAndParser::LaxerAndParser(string name,Data *data,TcpClient *client,TcpServer *server) {
  _txtName = name;
  _index = 0;
  fillMapConmm(client, server);
  _data = data;
}

void LaxerAndParser::getLexer() {
  ifstream in_s(_txtName);
  if (in_s) {
    string line;
    //split the txt to lines
    while (getline(in_s, line)) {
      //help to the lexer make the line be with space in the right place
      string normalStr = fixString(line);
      stringstream lineStream(normalStr);
      vector<string> token;
      //split the spacing and save the sting together in the same cell
      readRow(lineStream, token);
      _lexer.insert(end(_lexer), begin(token), end(token));
    }
    in_s.close();
  } else {
    cout << "Could not open: " + _txtName << std::endl;
  }
}

/**
 * fixString - g Getting a line,
 * And fixes it by adding profits after each expression.
 * Removes unimportant signs, and remove space in mathematical expressions.
 * Arranges logical conditions
 * */
string LaxerAndParser::fixString(string line) {
  string normalLine = line;
  bool flagFirst = true;

  for (unsigned int i = 0; i < normalLine.size(); i++) {
    //Arrange string expression together.
    if (normalLine[i] == '\"') {
      i++;
      while (normalLine[i] != '\"') {i++;}
      //Remove tab
    } else if(normalLine[i] == '\t') {
      normalLine.erase(i, 1);
      i--;
      //Separates curly brackets
    } else if(normalLine[i] == '{') {
      normalLine.insert(i, " ");
      i++;
    }
    //Arranges logical conditions
    else if (normalLine[i] == '=' || normalLine[i] == '<' || normalLine[i] == '>') {
      if (normalLine[i - 1] == '!' || normalLine[i - 1] == '=' || normalLine[i - 1] == '<' ||
          normalLine[i - 1] == '>') {
        normalLine.insert(i - 1, " ");
      } else if (normalLine[i - 1] == '-' && normalLine[i] == '>') {
        normalLine.insert(i - 1, " ");
      } else if (normalLine[i + 1] == '-' && normalLine[i] == '<' ) {
        normalLine.insert(i - 1, " ");
        normalLine.insert(i + 3, " ");
        i= i+2;
        continue;
      } else {
        normalLine.insert(i, " ");
      }
      i++;

      if (normalLine[i + 1] == '=') {
        normalLine.insert(i + 2, " ");
      } else {
        normalLine.insert(i + 1, " ");
      }
      i++;
    }


      // Remove spaces before and after arithmetic operators
    else if (normalLine[i] == '/' || normalLine[i] == '*' || normalLine[i] == '+' || normalLine[i] == '-') {
      // while there are no spaces
      while (normalLine[i - 1] == ' ' && normalLine[i - 2] != '=' && normalLine[i - 2] != '<' && normalLine[i - 2] != '>') {
        normalLine.erase(i - 1, 1);
        i--;
      }
      while (normalLine[i + 1] == ' ') {
        normalLine.erase(i + 1, 1);
        i--;
      }

    }
      // Check for close closer
    else if (normalLine[i] == ')') {
      while (normalLine[i - 1] == ' ') {
        normalLine.erase(i - 1, 1);
        i--;
      }
    }
      // Check for open closer
    else if (normalLine[i] == '(') {
      if (flagFirst) {
        normalLine.insert(i, " ");
        flagFirst = false;
      }
      while (normalLine[i + 1] == ' ') {
        normalLine.erase(i + 1, 1);
        i--;
      }
    }
      // Check for comma
    else if (normalLine[i] == ',') {
      normalLine.erase(i, 1);
      normalLine.insert(i, " ");
    }
  }
  // Finally, return normalized line
  return normalLine;
}


void LaxerAndParser::readRow(std::stringstream &lineStream, vector<string> &data)
{
  string cell;
  string save;
  string temp = "";
  bool flageFirst = false;
  bool flageLast = false;

      // Clear any previous data and get all elements on this row
  data.clear();
  while(std::getline(lineStream, cell, ' ')) {
    if (cell != " " && cell != "") {
      if (cell.at(0) == '(' && cell.at(cell.size()-1) != ')') {
        flageFirst = true;
        temp = cell;
        flageLast = true;
        save = cell;
        continue;
      } else if (flageFirst) {
        temp = temp + " " + cell;
        if (cell.at(cell.size()-1) != ')') {
          continue;
        } else {
          data.push_back(temp);
          flageLast = false;
          flageFirst = false;
        }
      } else {
        data.push_back(cell);
        flageFirst = false;
      }
    }
  }
  if (flageLast) {
    data.push_back(save);
  }
}

LaxerAndParser::~LaxerAndParser() {}





void LaxerAndParser::parser() {
  int counter = 0;
  while (_index < _lexer.size()) {
    Command *a;
    if (_data->isValidlVar(_lexer[_index])){
      a = _parser_map.find("varComm")->second;
    } else {
      a = _parser_map.find(_lexer[_index])->second;
    }
    counter = a->execute(_lexer, _index, _data);
    _index = _index + counter;
  }
}

