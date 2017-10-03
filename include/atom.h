#ifndef ATOM_H
#define ATOM_H

#include "variable.h"
#include "number.h"
#include <string>

using std::string;

class Variable;
class Number;
class Atom {
public:
  Atom (string s):_symbol(s) {}
  string symbol();
  bool operator ==(Atom a) {return _symbol == a._symbol;}
  bool match(Number num);
  bool match(Variable &var);
  string _symbol;
};

#endif
