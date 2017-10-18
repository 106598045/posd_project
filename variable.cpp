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

/*bool Variable::match(Atom atom){
  bool ret = _assignable;
  if(_assignable){
    _value = atom._symbol ;
    _container = atom._symbol;
    *_varPointer = atom._symbol;
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
    _container =  num.value() ;
    *_varPointer = num.value();
    _assignable = false;
  }else{
    ret = (_value == num.value());
  }
  return ret;
}

bool Variable::match(Variable &var){
  bool ret = _assignable;
  var._varPointer = _varPointer;
  return ret;
}*/

bool Variable::match(Term &term){
  bool ret = _assignable;
  Variable *pt = dynamic_cast<Variable *>(&term);
  if(pt){
    if( *(pt->_varPointer) != ""){

      _varPointer = pt->_varPointer;
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
