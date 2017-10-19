#include "variable.h"
#include <string>
#include <iostream>
using namespace std;

//string Variable::symbol() const{ return _symbol; }
string Variable::value() const{
  if(*_varPointer != ""){
    return *_varPointer;
    //return _varPointer->value();
  }
  return _symbol;
}

bool Variable::match(Term &term){
  bool ret = _assignable;
  Variable *pt = dynamic_cast<Variable *>(&term);
  if(pt){
    //可能是Atom、variable錯
    if( *(pt->_varPointer) != ""){
      _varPointer = pt->_varPointer;
      setNonAssignable();
    }else{
      pt->_varPointer = _varPointer;
    }
  }else{
    if(_assignable){
      _value = term.symbol();
      _container = term.symbol();
      *_varPointer = term.symbol();
      setNonAssignable();
    }else{
      ret = (_value == term.symbol());
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
