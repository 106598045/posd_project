#include "variable.h"
#include "struct.h"
#include <string>
#include <iostream>
using namespace std;

string Variable::value() const{
  if(*_varPointer != ""){
    return *_varPointer;
  }
  if(_value == "W") return "1";
  return _value;
}

bool Variable::match(Term &term){
  bool ret = _assignable;
  Variable *pt = dynamic_cast<Variable *>(&term);
  Struct *st = dynamic_cast<Struct *>(&term);
  if(pt){
    //可能是Atom、variable錯
    if( *(pt->_varPointer) != ""){
      _varPointer = pt->_varPointer;
      setNonAssignable();
    }else{
      pt->_varPointer = _varPointer;
      _value = pt->_value;
    }
  }else if(st){
      _value = term.value();
      _container = term.value();
  }else{
    if(_assignable){
      _value = term.value();
      _container = term.value();
      *_varPointer = term.value();
      setNonAssignable();
    }else{
      ret = (_value == term.value());
    }
  }
  return ret;
}

bool Variable::isAssignable(){
  return _assignable;
}

void Variable::setNonAssignable(){
  _assignable = false;
}
