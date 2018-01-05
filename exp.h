#ifndef EXP_H
#define EXP_H
#include "atom.h"

using namespace std;

class Exp {
public:
  virtual bool evaluate() = 0;
  virtual string getExpressionResult() = 0;
};

class MatchExp : public Exp {
public:
  MatchExp(Term* left, Term* right): _left(left), _right(right){}

  bool evaluate(){
    return _left->match(*_right);
  }

  string getExpressionResult() {
    if(evaluate()) {
      if( _left->symbol() == _right->symbol()) {
        return "true";
      }
      return _left->symbol() + " = " + _right->value();
    }
    else {
      return "false";
    }
  }

private:
  Term* _left;
  Term* _right;
};

class ConjExp : public Exp {
public:

  ConjExp(Exp *left, Exp *right) : _left(left), _right(right) {}
  bool evaluate() {
    return (_left->evaluate() && _right->evaluate());
  }

  string getExpressionResult() {
    bool res = evaluate();
    //cout << _left->getExpressionResult() << endl;
    if (res && _left->getExpressionResult() == "true" && _right->getExpressionResult() == "true"){
        return "true";
    }

    if (res && _left->getExpressionResult() ==  _right->getExpressionResult()){
      return _left->getExpressionResult();
    }

    if (res && _left->getExpressionResult().find( _right->getExpressionResult()) != string::npos ){
      return _left->getExpressionResult();
    }

    if (res && _left->getExpressionResult() == "true" ){
      return _right->getExpressionResult();
    }

    if (res && _right->getExpressionResult() == "true" ){
      return _left->getExpressionResult();
    }

    if(!res){
      return "false";
    }
    return _left->getExpressionResult() + ", " + _right->getExpressionResult();
  }
private:
  Exp * _left;
  Exp * _right;
};

class DisjExp : public Exp {
public:
  DisjExp(Exp *left, Exp *right) : _left(left), _right(right) {

  }

  bool evaluate() {
    return (_left->evaluate() || _right->evaluate());
  }

  string getExpressionResult() {
    evaluate();
    if ( _left->getExpressionResult() == "true" || _left->getExpressionResult() == "false" ){
      return _right->getExpressionResult();
    }else if ( _right->getExpressionResult() == "true" || _right->getExpressionResult() == "false" )
      return _left->getExpressionResult();
    else{
      return _left->getExpressionResult() + "; " + _right->getExpressionResult();
    }
  }

private:
  Exp * _left;
  Exp * _right;
};
#endif
