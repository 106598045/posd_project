#ifndef ATOM_H
#define ATOM_H

#include "variable.h"
#include "number.h"
#include "term.h"
#include <string>

using std::string;

class Variable;
class Number;
class Atom : public Term{
public:
  Atom (string s):_symbol(s){}
  string symbol() const;
  bool match(Term & term);
  string _symbol;
};

#endif
