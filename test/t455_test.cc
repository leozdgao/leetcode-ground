#include <gtest/gtest.h>
#include <gmock/gmock.h>
#include "t455.h"

using testing::Eq;

TEST(LeetCode_455, findContentChildren) {
  vector<int> g0 = { 1, 2, 3 };
  vector<int> s0 = { 1, 1 };
  vector<int> g1 = { 1, 2 };
  vector<int> s1 = { 1, 2, 3 };

  ASSERT_THAT(t455::findContentChildren(g0, s0), Eq<int>(1));
  ASSERT_THAT(t455::findContentChildren(g1, s1), Eq<int>(2));
}
