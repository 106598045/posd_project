#ifndef ITERATOR_H
#define ITERATOR_H

#include "struct.h"
#include "list.h"

class Iterator {
public:
  virtual void first() = 0;
  virtual void next() = 0;
  virtual Term* currentItem() const = 0;
  virtual bool isDone() const = 0;
};

class NullIterator :public Iterator{
public:
  NullIterator(Term *n){}
  void first(){}
  void next(){}
  Term * currentItem() const{
      return nullptr;
  }
  bool isDone() const{
    return true;
  }

};

class StructIterator :public Iterator {
public:
  friend class Struct;
  void first() {
    _index = 0;
  }

  Term* currentItem() const {
    return _s->args(_index);
  }

  bool isDone() const {
    return _index >= _s->arity();
  }

  void next() {
    _index++;
  }

private:
  StructIterator(Struct *s): _index(0), _s(s) {}
  int _index;
  Struct* _s;
};

class ListIterator :public Iterator {
public:
  ListIterator(List *list): _index(0), _list(list) {}

  void first() {
    _index = 0;
  }

  Term* currentItem() const {
    return _list->args(_index);
  }

  bool isDone() const {
    return _index >= _list->arity();
  }

  void next() {
    _index++;
  }
private:
  int _index;
  List* _list;
};

class DFSIterator :public Iterator {
  public:
    friend class Struct;
    void first() {
      _index = 0;
    }

    Term* currentItem() const {
      return _items[_index];
    }

    bool isDone() const {
      return _index >= _s->arity();
    }

    void next() {
      _index++;
    }

    void traverse(){
      while(!isDone()){
        Term * term =  _s->args(_index);
        Struct * s = dynamic_cast<Struct *>(term);
        if(s != nullptr){
          structTraverse(s);
        }else{
          _items.push_back(term);
        }
        next();
      }
      //printAllItem();
    }

    void structTraverse(Struct * s){
      for(int i=0;i<s->arity();i++){
        Struct * s2 = dynamic_cast<Struct *>(s->args(i));
        if(s2){
          structTraverse(s2);
        }else{
          _items.push_back(s->args(i));
        }
      }
    }

    void printAllItem(){
      for(int i=0;i<_items.size();i++){
        cout << _items[i]->symbol()<<endl;
      }
    }

  private:
    DFSIterator(Struct *s): _index(0), _s(s) {traverse();}
    int _index;
    Struct* _s;
    vector<Term*> _items;
  };
#endif
