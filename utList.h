#ifndef UTLIST_H
#define UTLIST_H

#include <string>
using std::string;

#include "list.h"
#include "struct.h"
#include "atom.h"
#include "number.h"
#include "variable.h"

// When create a new list without any item
// Then #symbol() of the list should return "[]"
TEST (List, constructor) {
  List L;
  EXPECT_EQ("[]",L.symbol());
}

// Given there are two perfect Numbers: 8128, 496
// When create a new list with the perfect Number
// Then #symbol() of the list should return "[496, 8128]"
TEST(List, Numbers) {
  Number n1(8128),n2(496);
  vector<Term *> args = {&n2, &n1};
  List L(args);
  EXPECT_EQ("[496, 8128]",L.symbol());
}

// Given there are two atoms: "terence_tao", "alan_mathison_turing"
// When create a new list with the Atoms
// Then #symbol() of the list should return "[terence_tao, alan_mathison_turing]"
TEST(List, Atoms) {
  Atom t("terence_tao"), a("alan_mathison_turing");
  vector<Term *> args = {&t, &a};
  List L(args);
  EXPECT_EQ("[terence_tao, alan_mathison_turing]",L.symbol());
}

// Given there are two variables: X, Y
// When create a new list with the variables
// Then #symbol() of the list should return "[X, Y]"
TEST(List, Vars) {
  Variable X("X"), Y("Y");
  vector<Term *> args = {&X, &Y};
  List L(args);
  EXPECT_EQ("[X, Y]",L.symbol());
}

// ?- tom = [496, X, terence_tao].
// false.
TEST(List, matchToAtomShouldFail) {
  Atom tom("tom");
  Variable X("X");
  Number num(496);
  Atom t("terence_tao");
  vector<Term *> args = {&num ,&X, &t};
  List L(args);
  EXPECT_FALSE(tom.match(L));
}

// ?- 8128 = [496, X, terence_tao].
// false.
TEST(List, matchToNumberShouldFail) {
  Variable X("X");
  Number num(496),num2(8128);
  Atom t("terence_tao");
  vector<Term *> args = {&num ,&X, &t};
  List L(args);
  EXPECT_FALSE(num2.match(L));
}

// ?- s(X) = [496, X, terence_tao].
// false.
TEST(List, matchToStructShouldFail) {
  Variable X("X");
  std::vector<Term *> v = {&X};
  Struct s(Atom("s"), v);

  Number num(496),num2(8128);
  Atom t("terence_tao");
  vector<Term *> args = {&num ,&X, &t};
  List L(args);

  EXPECT_FALSE(s.match(L));
}

// ?- Y = [496, X, terence_tao].
// Y = [496, X, terence_tao].
TEST(List, matchToVarShouldSucceed) {
  Variable Y("Y"),X("X");
  Number num(496);
  Atom t("terence_tao");
  vector<Term *> args = {&num ,&X, &t};
  List L(args);
  EXPECT_TRUE(L.match(Y));
}

// ?- X = [496, X, terence_tao].
// false.
TEST(List, matchToVarOccuredInListShouldFail) {
  Variable X("X");
  Number num(496);
  Atom t("terence_tao");
  vector<Term *> args = {&num ,&X, &t};
  List L(args);
  EXPECT_TRUE(X.match(L));
}

// ?- [496, X, terence_tao] = [496, X, terence_tao].
// true.
TEST(List, matchToSameListShouldSucceed) {
  Variable X("X");
  Number num(496);
  Atom t("terence_tao");
  vector<Term *> args = {&num ,&X, &t};
  List L(args),L2(args);
  EXPECT_TRUE(L.match(L2));
}

// ?- [496, X, terence_tao] = [496, Y, terence_tao].
// true. ****************
TEST(List, matchToSameListWithDiffVarNameShouldSucceed) {
  Variable Y("Y"),X("X");
  Number num(496);
  Atom t("terence_tao");
  vector<Term *> args = {&num ,&X, &t};
  vector<Term *> args2 = {&num ,&Y, &t};
  List L(args),L2(args2);
  EXPECT_TRUE(L.match(L2));
}

// ?- [496, X, terence_tao] = [496, 8128, terence_tao].
// X = 8128.
TEST(List, matchToVarToAtominListShouldSucceed) {
  Variable Y("Y"),X("X");
  Number num(496),num2(8128);
  Atom t("terence_tao");
  vector<Term *> args = {&num ,&X, &t};
  vector<Term *> args2 = {&num ,&num2, &t};
  List L(args),L2(args2);
  EXPECT_TRUE(L.match(L2));
  EXPECT_TRUE(X.match(num2));
}

// ?- Y = [496, X, terence_tao], X = alan_mathison_turing.
// Y = [496, alan_mathison_turing, terence_tao],
// X = alan_mathison_turing.
TEST(List, matchVarinListToAtomShouldSucceed) {
  Variable Y("Y"),X("X");
  Number num(496);
  Atom t("terence_tao"),a("alan_mathison_turing");
  vector<Term *> args = {&num ,&X, &t};
  List L(args);
  Y.match(L);
  X.match(a);
  EXPECT_EQ("alan_mathison_turing",X.value()); // ok
  EXPECT_EQ("[496, alan_mathison_turing, terence_tao]",Y.value());
}

// Example:
// ?- [first, second, third] = [H|T].
// H = first, T = [second, third].
TEST(List, headAndTailMatching1) {
  Atom f("first"), s("second"), t("third");
  vector<Term *> args = {&f, &s, &t};
  List l(args);

  EXPECT_EQ("first", l.head()->symbol());
  EXPECT_EQ("[second, third]", l.tail()->value());
}

// Example:
// ?- [first, second, third] = [first, H|T].
// H = second, T = [third].
TEST(List, headAndTailMatching2) {
  Atom f("first"), s("second"), t("third");
  vector<Term *> args = {&f, &s, &t};
  List l(args);
  EXPECT_EQ(string("second"), l.tail()->head()->value());
  EXPECT_EQ(string("[third]"), l.tail()->tail()->value());
}

// ?- [[first], second, third] = [H|T].
// H = [first], T = [second, third].
TEST(List, headAndTailMatching3) {
  Atom f("first"), s("second"), t("third");
  vector<Term *> inner_args = {&f};
  List inner_list(inner_args);
  vector<Term *> outer_args = {&inner_list, &s, &t};
  List outer_list(outer_args);
  EXPECT_EQ(string("second"), outer_list.tail()->head()->value());
  EXPECT_EQ(string("[third]"), outer_list.tail()->tail()->value());
}

// ?- [first, second, third] = [first, second, H|T].
// H = third, T = [].
TEST(List, headAndTailMatching4) {
  Atom f("first"), s("second"), t("third");
  vector<Term *> args = {&f, &s, &t};
  List l(args);
  EXPECT_EQ(string("third"), l.tail()->tail()->head()->value());
  EXPECT_EQ(string("[]"), l.tail()->tail()->tail()->value());
}

// Given there is a empty list
// When client still want to get the head of list
// Then it should throw a string: "Accessing head in an empty list" as an exception.
TEST (List, emptyExecptionOfHead) {
  List l;
  try{
     l.head()->value();
  }catch(string const & err) {
     EXPECT_EQ("Accessing head in an empty list",err);
  }
}

// Given there is a empty list
// When client still want to get the tail of list
// Then it should throw a string: "Accessing tail in an empty list" as an exception.
TEST (List, emptyExecptionOfTail) {
  List l;
  try{
     l.tail()->value();
  }catch(string const & err) {
     EXPECT_EQ("Accessing tail in an empty list",err);
  }
}

#endif
