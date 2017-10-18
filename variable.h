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
  Variable(){}
  Variable(string s):_symbol(s){}
  string symbol()const{ return _symbol;}
  string value()const;
  bool match(Term &term);
  bool isAssignable();
  void setNonAssignable();
  string _symbol;
  string _value ="";
  string * _varPointer = &_container;
private:
  string _container = "";
  bool _assignable = true;
};

#endif
