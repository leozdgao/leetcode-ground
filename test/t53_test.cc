#include <gtest/gtest.h>
#include <gmock/gmock.h>
#include "t53.h"

using testing::Eq;

TEST(LeetCode_53, maxSubArray) {
  vector<int> s0 = { -2, 1, -3, 4, -1, 2, 1, -5, 4 };

  ASSERT_THAT(t53::maxSubArray(s0), 6);
}
