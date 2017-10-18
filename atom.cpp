#include "atom.h"

string Atom::symbol() const{
  return  _symbol;
}

bool Atom::match(Term &term){
  bool ret = false;
  Variable *pt = dynamic_cast<Variable *>(&term);
  if(pt){
    if(pt->isAssignable()){
      pt->match(*this); //未解決
      pt->setNonAssignable();
      return true;
    }else{
      ret = (_symbol == term.symbol());
    }
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
