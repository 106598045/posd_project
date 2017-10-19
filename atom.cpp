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
    if(pt->isAssignable()){
      pt->match(*this); //未解決
      pt->setNonAssignable();
      ret = true;
    }else{
      ret = (_symbol == term.symbol());
    }
  }else{
    ret = (_symbol == term.symbol());
  }
  return ret;
}
