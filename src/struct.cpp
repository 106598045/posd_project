#include "../include/struct.h"

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
