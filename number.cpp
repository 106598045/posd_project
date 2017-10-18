#include "number.h"

#include <string>
using namespace std;

Number::Number(double d){
  _value =  d;
  _symbol = toString(d);
}

string Number::value() const{
  return toString(_value);
}

string Number::symbol() const{
  return _symbol;
}

bool Number::match(Number n){
  return _value == n._value;
}

bool Number::match(Variable &var){
  if(var.isAssignable()){
    var.match(*this);
    var.setNonAssignable();
    return true;
  }else{
    return toString(_value) == var.value();
  }
}
