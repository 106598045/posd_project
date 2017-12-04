#ifndef STRUCT_H
#define STRUCT_H

#include "atom.h"
#include <vector>

class Struct:public Term{
public:
  Struct(Atom const & name, std::vector<Term *> args):_name(name), _args(args) {}
  Term * args(int index);
  int arity();
  Atom const & name();
  string symbol() const;
  string value() const;
  Iterator * createIterator();
  //bool match(Term &term); TA的struct沒有override match
  Iterator * createDFSIterator();
  //Iterator * createDFSIterator();
private:
  Atom _name;
  std::vector<Term *> _args;
};

#endif
