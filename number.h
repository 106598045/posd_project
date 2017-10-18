#ifndef NUMBER_H_INCLUDED
#define NUMBER_H_INCLUDED
#include "atom.h"
#include "variable.h"
#include "term.h"
#include <string>

using namespace std;
//class Atom;
class Variable;

class Number: public Term{
public:
  Number(){}
  Number(double i);
  string value() const;
  string symbol() const;
  bool match(Number n);
  bool match(Variable &var);

private:
  double _value =0;
  string _symbol = "";
};
#endif
