#ifndef VARIABLE_H
#define VARIABLE_H

#include <string>
#include "atom.h"
#include "term.h"
#include "number.h"

using std::string;
class Number;
class Atom;

class Variable : public Term{
public:
  //Variable(){}
  Variable(string s):_symbol(s),_value(s){}
  string _symbol;
  string symbol()const{ return _symbol;}
  //string value()const{ return _value; }
  string value()const;
  bool match(Atom atom);
  bool match(Number num);
  bool match(Variable & var);
  bool isAssignable();
  void setNonAssignable();
  bool hasPointer() const;
private:
  string _value;
  bool _assignable = true;
  Variable * _varPointer;
};

#endif
