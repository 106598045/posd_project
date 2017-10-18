#ifndef TERM_H
#define TERM_H
#include <string>
#include <sstream>

using namespace std;

class Term{
public:
  virtual string symbol() const = 0;
  virtual string value() const{return symbol();};
  virtual bool match(Term & term) {
    return symbol() == term.symbol();
  }
  /**不加const會出現錯誤 原因為value是const**/
  virtual string toString(double d) const{
    ostringstream targetItem;
    targetItem << d;
    string s = targetItem.str();
    return s;
  }
};

#endif
