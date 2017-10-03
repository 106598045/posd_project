#ifndef VARIABLE_H
#define VARIABLE_H

#include "atom.h"
#include "number.h"
#include <string>

using std::string;
class Atom;
class Number;
class Variable{
public:
  Variable(string s):_symbol(s){}
  string const _symbol;
  string value();
  bool match(Atom atom);
  bool match(Number num);
  bool isAssignable();
  void setNonAssignable();
private:
  string _value;
  bool _assignable = true;
};

#endif
