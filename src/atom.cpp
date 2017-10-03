#include "../include/atom.h"

bool Atom::match(Number num){
  return num.symbol() == _symbol;
}

string Atom::symbol(){
  return  _symbol;
}

bool Atom::match(Variable &var){
  if(var.isAssignable()){
    var.match(*this); //未解決
    var.setNonAssignable();
    return true;
  }else{
    return _symbol == var.value(); //value function return string type
  }
}
