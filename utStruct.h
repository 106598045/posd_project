#include <vector>
#include "atom.h"
#include "struct.h"

TEST(Struct, hobby){
  Atom tom("tom");
  Atom chaseMouse("chaseMouse");
  std::vector<Term *> v = {&tom, &chaseMouse};
  Struct hobby(Atom("hobby"), v);
  ASSERT_EQ("hobby", hobby.name().symbol());
  ASSERT_EQ("tom", hobby.args(0)->symbol());
  ASSERT_EQ("chaseMouse", hobby.args(1)->symbol());
}

TEST(Struct,symbol){
  Atom tom("tom");
  Atom chaseMouse("chaseMouse");
  std::vector<Term *> v = {&tom, &chaseMouse};
  Struct hobby(Atom("hobby"), v);
  ASSERT_EQ("hobby(tom, chaseMouse)",hobby.symbol());
}

TEST(Struct,match1){
  Atom tom("tom");
  Atom chaseMouse("chaseMouse");
  std::vector<Term *> v = {&tom, &chaseMouse};
  Struct hobby(Atom("hobby"), v);
  Struct hobby2(Atom("hobby2"), v);
  EXPECT_FALSE(hobby.match(hobby2));
}
TEST(Struct,match2){
  Atom tom("tom");
  Atom chaseMouse("chaseMouse");
  std::vector<Term *> v = {&tom, &chaseMouse};
  Struct hobby(Atom("hobby"), v);
  std::vector<Term *> v1 = {&tom};
  Struct hobby2(Atom("hobby"), v1);
  EXPECT_FALSE(hobby.match(hobby2));
}
TEST(Struct,match3){
  Atom tom("tom");
  Atom chaseMouse("chaseMouse");
  std::vector<Term *> v = {&tom, &chaseMouse};
  Struct hobby(Atom("hobby"), v);
  std::vector<Term *> v1 = { &chaseMouse,&tom};
  Struct hobby2(Atom("hobby"), v1);
  EXPECT_FALSE(hobby.match(hobby2));
}
TEST(Struct,match4){
  Atom tom("tom");
  Atom chaseMouse("chaseMouse");
  std::vector<Term *> v = {&tom, &chaseMouse};
  Struct hobby(Atom("hobby"), v);
  Struct hobby2(Atom("hobby"), v);
  EXPECT_TRUE(hobby.match(hobby2));
}

TEST(Struct,match5){
  Atom tom("tom");
  Atom chaseMouse("chaseMouse");
  std::vector<Term *> v = {&tom, &chaseMouse};
  Struct hobby(Atom("hobby"), v);
  EXPECT_FALSE(hobby.match(tom));
}

// When Struct s contains a Variable X
// Then #symbol() should return "s(X)"
// and #value() should also return "s(X)"
TEST(Struct, var){
  Variable X("X");
  std::vector<Term *> v = {&X};
  Struct s(Atom("s"), v);
  ASSERT_EQ("s(X)",s.symbol());
  ASSERT_EQ("s(X)",s.value()); //override
}

// Given there is Struct s contains a Variable X
// When Variable X matches an Atom "tom"
// Then #symbol() should return "s(X)"
// and #value() should also return "s(tom)"
TEST(Struct, var_match_atom){
  Variable X("X");
  Atom tom("tom");
  X.match(tom);
  std::vector<Term *> v = {&X};
  Struct s(Atom("s"), v);
  ASSERT_EQ("s(X)",s.symbol());
  ASSERT_EQ("s(tom)",s.value()); //override
  /*  ok
   *  10/15 variable 的 value 沒有override 所以一直去call symbol
   *  改為const 就可以 override 但一直有問題
   */

}

// Given there are Struct s1 and Struct s2
// When Struct s1 contains Struct s2
// And Struct s2 contains a Variable X
// Then #symbol() of s1 should return "s1(s2(X))"
// and #value() of s1 should also return "s1(s2(X))"
TEST(Struct, nested_struct1){
  Variable X("X");
  std::vector<Term *> v_innerStruct = {&X};
  Struct innerStruct(Atom("s2"),v_innerStruct);
  std::vector<Term *> v_outerStruct = {&innerStruct};
  Struct outerStruct(Atom("s1"),v_outerStruct);

  ASSERT_EQ("s1(s2(X))",outerStruct.symbol());
  ASSERT_EQ("s1(s2(X))",outerStruct.value());
}

// Given there are Struct s1 contains Struct s2
// And Struct s2 contains Variable X
// When Variable X matches an Atom "tom"
// Then #symbol() of s1 should return "s1(s2(X))"
// and #value() of s1 should return "s1(s2(tom))"
TEST(Struct, nested_struct2){
  Variable X("X");
  Atom tom("tom");
  X.match(tom);
  std::vector<Term *> v_innerStruct = {&X};
  Struct innerStruct(Atom("s2"),v_innerStruct);
  std::vector<Term *> v_outerStruct = {&innerStruct};
  Struct outerStruct(Atom("s1"),v_outerStruct);

  ASSERT_EQ("s1(s2(X))",outerStruct.symbol());
  ASSERT_EQ("s1(s2(tom))",outerStruct.value());
}

// Given there are Struct s1 contains Struct s2
// And Struct s2 contains Variable X
// When Variable X matches an Number pi: 3.14
// Then #symbol() of s1 should return "s1(s2(X))"
// and #value() of s1 should return "s1(s2(3.14))"
TEST(Struct, nested_struct3){
  Variable X("X");
  Number num(3.14);
  X.match(num);
  std::vector<Term *> v_innerStruct = {&X};
  Struct innerStruct(Atom("s2"),v_innerStruct);
  std::vector<Term *> v_outerStruct = {&innerStruct};
  Struct outerStruct(Atom("s1"),v_outerStruct);

  ASSERT_EQ("s1(s2(X))",outerStruct.symbol());
  ASSERT_EQ("s1(s2(3.14))",outerStruct.value());
}

// Given there are Struct s1 contains Struct s2 and Variable X
// And Struct s2 contains Variable Y
// When Variable X matches Variable Y
// And Variable X matches Atom "kent_beck"
// Then #symbol() of s1 should return "s1(s2(Y), X)"
// and #value() of s1 should return "s1(s2(kent_beck), kent_beck)"
TEST(Struct, nested_struct_and_multiVariable){
  Variable X("X");
  Variable Y("Y");
  Atom kent_beck("kent_beck");
  std::vector<Term *> v_innerStruct = {&Y};
  Struct innerStruct(Atom("s2"),v_innerStruct);
  std::vector<Term *> v_outerStruct = {&innerStruct,&X};
  Struct outerStruct(Atom("s1"),v_outerStruct);
  X.match(kent_beck);
  Y.match(X);

  ASSERT_EQ("s1(s2(Y), X)",outerStruct.symbol());
  ASSERT_EQ("s1(s2(kent_beck), kent_beck)",outerStruct.value());
  // 10/16 還沒定義 var match var
}
