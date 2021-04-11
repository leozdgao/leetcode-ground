#include <gtest/gtest.h>
#include <gmock/gmock.h>
#include "t69.h"

using testing::Eq;

TEST(LeetCode_69, mySqrt) {
    ASSERT_THAT(t69::mySqrt(4), Eq<int>(2));
    ASSERT_THAT(t69::mySqrt(1), Eq<int>(1));
}
