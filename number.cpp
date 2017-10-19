#include "number.h"

#include <string>
using namespace std;

string Number::value() const{
  return toString(_value);
}

Number::Number(double d){
  _value =  d;
  _symbol = toString(d);
}

string Number::symbol() const{
  return _symbol;
}

string Number::toString(double d) const{
  ostringstream targetItem;
  targetItem << d;
  string s = targetItem.str();
  return s;
}

bool Number::match(Term &term){
  bool ret = false;
  Variable *pt = dynamic_cast<Variable *>(&term);
  if(pt){
    if(pt->isAssignable()){
      pt->match(*this); //未解決
      pt->setNonAssignable();
      ret = true;
    }else{
      ret = (_symbol == term.symbol());
    }
  }else{
    ret = (_symbol == term.symbol());
  }
  return ret;
}
