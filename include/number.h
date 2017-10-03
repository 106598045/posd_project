#ifndef NUMBER_H_INCLUDED
#define NUMBER_H_INCLUDED
#include "atom.h"
#include "variable.h"
#include <string>

using namespace std;

class Variable;
class Atom;
class Number{
public:
  Number(){}
  Number(int i);
  string value();
  string symbol();
  bool match(Number n);
  bool match(Atom a);
  bool match(Variable &var);

private:
  int  _value =0;
  string _symbol = "";
};
#endif
