#ifndef UTVARIABLE_H
#define UTVARIABLE_H
#include "include/variable.h"
#include "include/number.h"

TEST(Variable, constructor){
  Variable X("X");
  ASSERT_EQ("X", X._symbol);
}

TEST(Variable , matching){
  Atom tom("tom");
  Variable X("X");
  X.match(tom);
  ASSERT_EQ( "tom", X.value());
}
TEST (Variable , haveValue){
  Atom tom ("tom");
  Atom jerry ("jerry");
  Variable X("X");
  ASSERT_TRUE(X.match(tom));
  ASSERT_FALSE(X.match(jerry));
}

// ?- X=2.7182.
// X=2.7182
TEST(Variable , numE_to_varX){
  Variable X("X");
  Number num(2.7182);
  X.match(num);
  ASSERT_EQ("2.718200", X.value());
}

// ?- X=Y, X=1.
// Y=1
TEST (Variable, varY_to_varX_and_num1_to_varX) {
  Variable X("X");
  Variable Y("Y");
  X.match(Y);
  Number num(1);
  X.match(num);
  ASSERT_EQ("1.000000", Y.value());
}

// ?- X=Y, Y=1.
// X=1
TEST (Variable, varY_to_varX_and_num1_to_varY) {
  Variable X("X");
  Variable Y("Y");
  X.match(Y);
  Number num(1);
  X.match(num);
  ASSERT_EQ("1.000000", X.value());
}

// ?- X=X, X=1.
// X=1
TEST (Variable, varX_match_varX_and_num1_to_varX) {
  Variable X("X");
  X.match(X);
  Number num(1);
  X.match(num);
  ASSERT_EQ("1.000000", X.value());
}

// ?- Y=1, X=Y.
// X=1
TEST (Variable, num1_to_varY_and_varX_match_varY) {
  Variable Y("Y");
  Number num(1);
  Y.match(num);
  Variable X("X");
  Y.match(X);
  ASSERT_EQ("1.000000", X.value());
}

// ?- X=Y, Y=Z, Z=1
// X=1, Y=1, Z=1
TEST (Variable, num1_to_varZ_to_varY_to_varX) {
  Variable X("X");
  Variable Y("Y");
  Variable Z("Z");
  X.match(Y);
  Y.match(Z);
  Number num(1);
  Z.match(num);
  ASSERT_EQ("1.000000", X.value());
  ASSERT_EQ("1.000000", Y.value());
  ASSERT_EQ("1.000000", Z.value());
}

// ?- X=Y, X=Z, Z=1
// X=1, Y=1, Z=1
TEST (Variable, num1_to_varZ_to_varX_and_varY_to_varX) {
  Variable X("X");
  Variable Y("Y");
  Variable Z("Z");
  X.match(Y);
  X.match(Z);
  Number num(1);
  Z.match(num);
  ASSERT_EQ("1.000000", X.value());
  ASSERT_EQ("1.000000", Y.value());
  ASSERT_EQ("1.000000", Z.value());
}

// Give there is a Struct s contains Variable X
// And another Variable Y
// When Y matches Struct s
// Then #symbol() of Y should return "Y"
// And #value() of Y should return "s(X)"
TEST (Variable, Struct1) {

}

// Give there is a Struct s contains Variable X
// And another Variable Y
// When Y matches Struct s
// And X matches Atom "teddy"
// Then #symbol() of Y should return "Y"
// And #value() of Y should return "s(teddy)"
TEST (Variable, Struct2) {

}


#endif
