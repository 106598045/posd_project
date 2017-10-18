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
  return _value;
}

bool Variable::match(Atom atom){
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
  /*if(var.symbol() != symbol()){
    Variable *v = new Variable();
    v = &var;
    _varPointer = v;
  }*/
  return ret;
}

bool Variable::match(Term &term){
  bool ret = _assignable;
  
  return ret;
}

/*bool match(Struct &str){
  return true;
}*/

bool Variable::isAssignable(){
  return _assignable;
}

void Variable::setNonAssignable(){
  _assignable = false;
}
