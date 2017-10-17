#include "../include/variable.h"
#include <string>
#include <iostream>
using namespace std;

//string Variable::symbol() const{ return _symbol; }
string Variable::value() const{
  if(_varPointer){
    return *_varPointer;
  }
  return _value;
}

bool Variable::match(Atom atom){
  bool ret = _assignable;
  if(_assignable){
    _value = atom._symbol ;
    _assignable = false;
  }else{
    ret = (_value == atom.symbol());
  }
  return ret;
}

bool Variable::match(Number num){
  bool ret = _assignable;
  if(_assignable){
    _value = num.value() ;
    _assignable = false;
  }else{
    ret = (_value == num.value());
  }
  return ret;
}

bool Variable::match(Variable &var){
  bool ret = _assignable;
  _varPointer = &(var._value);
  return ret;
}

bool Variable::isAssignable(){
  return _assignable;
}

void Variable::setNonAssignable(){
  _assignable = false;
}
