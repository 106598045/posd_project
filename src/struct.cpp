#include "../include/struct.h"

#include <string>
using namespace std;

Term * Struct::args(int index) {
  return _args[index];
}

Atom const & Struct::name(){
  return _name;
}

string Struct::symbol() const{
  string ret =_name.symbol() + "(";
  for(int i = 0; i < _args.size() - 1 ; i++){
    ret += _args[i]-> symbol() + ", ";
  }
  ret += _args[_args.size()-1]-> symbol() + ")";
  return  ret;
}

string Struct::value() const{
  string ret =_name.value() + "(";
  for(int i = 0; i < _args.size() - 1 ; i++){
    ret += _args[i]-> value() + ", ";
  }
  ret += _args[_args.size()-1]-> value() + ")";
  return  ret;
}

bool Struct::match(Term &term){
  Struct * ps = dynamic_cast<Struct *>(&term);
  if (ps){
    if (!_name.match(ps->_name))
      return false;
    if(_args.size()!= ps->_args.size())
      return false;
    for(int i=0;i<_args.size();i++){
      if(_args[i]->symbol() != ps->_args[i]->symbol())
          return false;
    }
    return true;
  }
  return false;
}