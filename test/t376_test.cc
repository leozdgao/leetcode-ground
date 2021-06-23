#include <gtest/gtest.h>
#include <gmock/gmock.h>
#include "t376.h"

using testing::Eq;

TEST(LeetCode_376, wiggleMaxLength) {
  vector<int> s0 = { 1, 1 };
  vector<int> s1 = { 1, 2, 3 };
  vector<int> s2 = { 1, 7, 4, 9, 2, 5 };
  vector<int> s3 = { 1, 17, 5, 10, 13, 15, 10, 5, 16, 8 };

  ASSERT_THAT(t376::wiggleMaxLength(s0), 1);
  ASSERT_THAT(t376::wiggleMaxLength(s1), 2);
  ASSERT_THAT(t376::wiggleMaxLength(s2), 6);
  ASSERT_THAT(t376::wiggleMaxLength(s3), 7);
}
