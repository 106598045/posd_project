#include "../include/number.h"

#include <string>
using namespace std;

Number::Number(int i){
  _value =  i;
  _symbol = to_string(i);
}

string Number::value(){
  return to_string(_value);
}

string Number::symbol(){
  return _symbol;
}

bool Number::match(Number n){
  return _value == n._value;
}

bool Number::match(Variable &var){

  if(var.isAssignable()){
    var.match(*this); 
    var.setNonAssignable();
    return true;
  }else{
    return to_string(_value) == var.value();
  }
}

bool Number::match(Atom a){
  return false;
}
