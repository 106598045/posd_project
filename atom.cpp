#include "atom.h"
#include <iostream>
using namespace std;

string Atom::symbol() const{
  return  _symbol;
}

bool Atom::match(Term &term){
  bool ret = false;
  Variable *pt = dynamic_cast<Variable *>(&term);
  if(pt){
    pt->match(*this); //未解決
    pt->setNonAssignable();
    ret = true;
  }else{
    ret = (_symbol == term.symbol());
  }
  return ret;
}

/*bool Atom::match(Variable &var){
  if(var.isAssignable()){
    var.match(*this); //未解決
    var.setNonAssignable();
    return true;
  }else{
    return _symbol == var.value(); //value function return string type
  }
}

bool Atom::match(Number num){
  return num.symbol() == _symbol;
}

bool Atom::match(Atom atom){
  return _symbol == atom._symbol;
}*/
