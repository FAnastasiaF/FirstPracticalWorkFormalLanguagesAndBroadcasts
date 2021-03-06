//
// Created by 2ToThe10th
//

#include <gmock/gmock.h>
#include <gtest/gtest.h>
#include "ClassForTest.h"

TEST(OneLetter, A) {
  ClassForTest test("a*", "aaaaa");
  EXPECT_EQ(test.Do(), 5);
}
TEST(OneLetter, B) {
  ClassForTest test("b*", "bbbb");
  EXPECT_EQ(test.Do(), 4);
}
TEST(OneLetter, C) {
  ClassForTest test("c*", "cccccc");
  EXPECT_EQ(test.Do(), 6);
}
TEST(Middle, First) {
  ClassForTest test("c*bb..", "cccacccbb");
  EXPECT_EQ(test.Do(), 5);
}
TEST(Middle, Second) {
  ClassForTest test("a*b.a*.", "aaabaaabaa");
  EXPECT_EQ(test.Do(), 6);
}
TEST(Middle, Third) {
  ClassForTest test("ab.*", "ababbbbbabcabababa");
  EXPECT_EQ(test.Do(), 0);
}
TEST(Middle, Forth) {
  ClassForTest test("ab.*", "ababbbbbabcbababab");
  EXPECT_EQ(test.Do(), 7);
}
TEST(Middle, Fifth) {
  ClassForTest test("ab+*", "aacbcabacabbaababb");
  EXPECT_EQ(test.Do(), 9);
}
TEST(Middle, Sixth) {
  ClassForTest test("ab.c.", "aacbcabacabbaababbc");
  EXPECT_EQ(test.Do(), 2);
}
TEST(Middle, Seventh) {
  ClassForTest test("ab.c.", "aacbcabacabbaabababc");
  EXPECT_EQ(test.Do(), 3);
}
TEST(Middle, Eighth) {
  ClassForTest test("ab.c.", "aacbcabacabbaabababcaa");
  EXPECT_EQ(test.Do(), 0);
}
TEST(Hard, First) {
  ClassForTest test("ab+c+*ab+*c..", "aacbcabacabbaacbababc");
  EXPECT_EQ(test.Do(), 21);
}
TEST(Hard, Second) {
  ClassForTest test("ab.cb.ac.++*", "bbcabcb");
  EXPECT_EQ(test.Do(), 5);
}
TEST(Hard, Third) {
  ClassForTest test("ba***.", "bbbaaaaaaa");
  EXPECT_EQ(test.Do(), 8);
}
TEST(Hard, Fourth) {
  ClassForTest test("ccba+***..", "bbbaaaaaaaccc");
  EXPECT_EQ(test.Do(), 2);
}
TEST(Hard, Fifth) {
  ClassForTest test("ccab+ba+***...", "bbbaaaaaaaccc");
  EXPECT_EQ(test.Do(), 0);
}
TEST(Hard, Sixth) {
  ClassForTest test("ab.*bb.***.", "abababababb");
  EXPECT_EQ(test.Do(), 2);
}
TEST(Hard, Seventh) {
  ClassForTest test("ab.***bb.**.", "ababaabababbbbb");
  EXPECT_EQ(test.Do(), 10);
}
TEST(Hard, Eighth) {
  ClassForTest test("aa.aa..***b.**", "aaababaaaab");
  EXPECT_EQ(test.Do(), 7);
}
TEST(Hard, Nineth) {
  ClassForTest test("c*ab+1+.a.b.a.c.", "accccccabac");
  EXPECT_EQ(test.Do(), 10);
}
TEST(Hard, Tenth) {
  ClassForTest test("11.1.1.1.***", "accccccabac");
  EXPECT_EQ(test.Do(), 0);
}
TEST(Hard, 11th) {
  ClassForTest test("ac1.1.1.1.1.***.", "accccccabacccc");
  EXPECT_EQ(test.Do(), 5);
}
TEST(Hard, 12th) {
  ClassForTest test("b1.a1.c1...1.", "accccccababac");
  EXPECT_EQ(test.Do(), 3);
}
TEST(Hard, 13th) {
  ClassForTest test("b1.a1.c1...1.", "ac");
  EXPECT_EQ(test.Do(), 2);
}
TEST(Example, First) {
  ClassForTest test("ab+c.aba.*.bac.+.+*", "babc");
  EXPECT_EQ(test.Do(), 2);
}
TEST(Example, Second) {
  ClassForTest test("acb..bab.c. * .ab.ba. + . + *a.", "cbaa");
  EXPECT_EQ(test.Do(), 4);
}