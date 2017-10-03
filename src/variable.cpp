#include "../include/variable.h"
#include <string>
using namespace std;
string Variable::value(){ return _value; }

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

bool Variable::isAssignable(){
  return _assignable;
}

void Variable::setNonAssignable(){
  _assignable = false;
}
