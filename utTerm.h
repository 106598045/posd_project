#ifndef UTTERM_H
#define UTTERM_H

#include "number.h"
#include "atom.h"
#include "variable.h"
#include <gtest/gtest.h>
#include <string>

using namespace std;
//test Number.vale()
TEST (Number,ctor) {
  Number num(10);
  ASSERT_EQ("10",num.value());
}
//test Number.symbol()
TEST (Number, symbol) {
  Number num(0);
  ASSERT_EQ("0",num.symbol());
}
//?- 25=25.
//true.
TEST (Number, matchSuccess) {
  Number num_A(25);
  Number num_B(25);
  ASSERT_TRUE(num_A.match(num_B));
}
//?- 25=0.
//false.
TEST (Number, matchFailureDiffValue) {
  Number num_A(25);
  Number num_B(0);
  ASSERT_FALSE(num_A.match(num_B));
}

//?- 25=tom.
//false.
TEST (Number, matchFailureDiffConstant) {
  Atom a("tom");
  Number num(11);
  ASSERT_FALSE(num.match(a));
}

//?- 25=X.
//true.
TEST (Number, matchSuccessToVar) {
  Variable X("X");
  Number num(25);
  ASSERT_TRUE(num.match(X));
}

//?- tom=25.
//false.
TEST (Atom, matchFailureDiffConstant) {
  Atom a("tom");
  Number num(25);
  ASSERT_FALSE(a.match(num));
}
// ?- tom = X.
// X = tom.
TEST (Atom, matchSuccessToVar) {
  Atom tom("tom");
  Variable X("X");
  ASSERT_TRUE(tom.match(X));
}

// ?- X=tom, tom=X.
// X = tom.
TEST (Atom, matchSuccessToVarInstantedToDiffConstant) {
  Atom tom("tom");
  Variable X("X");
  ASSERT_TRUE(X.match(tom));
  ASSERT_TRUE(tom.match(X));
}

// ?- X=jerry, tom=X.
// false.
TEST (Atom, matchFailureToVarInstantedToDiffConstant) {
  Atom jerry("jerry");
  Atom tom("tom");
  Variable X("X");
  ASSERT_TRUE(X.match(jerry));
  ASSERT_FALSE(tom.match(X));
}
/*---------------------完成----------------------*/
// ?- X = 5.
// X = 5.
TEST (Var, matchSuccessToNumber) {
  Number five(5);
  Variable X("X");
  ASSERT_TRUE(X.match(five));
}


TEST (Var, matchFailureToTwoDiffNumbers) {
  Number a(25);
  Number b(100);
  Variable X("X");
  X.match(a);
  ASSERT_FALSE(X.match(b));
}

// ?- X=tom, X= 25.
// false.
TEST (Var, matchSuccessToAtomThenFailureToNumber) {
  Number a(25);
  Atom tom("tom");
  Variable X("X");
  X.match(tom);
  ASSERT_FALSE(X.match(a));
}
//?- tom=X, 25=X.
//false.
TEST (Var, matchSuccessToAtomThenFailureToNumber2) {
  Number a(25);
  Atom tom("tom");
  Variable X("X");
  tom.match(X);
  ASSERT_FALSE(a.match(X));
}
//?- X=tom, X=tom.
//true.
TEST(Var, reAssignTheSameAtom){
  Atom tom("tom");
  Variable X("X");
  X.match(tom);
  ASSERT_TRUE(X.match(tom));
}
#endif
