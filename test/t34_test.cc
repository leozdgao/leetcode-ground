#include <gtest/gtest.h>
#include <gmock/gmock.h>
#include <vector>
#include "t34.h"

using std::vector;
using testing::ElementsAre;

TEST(LeetCode_34, searchRange) {
    vector<int> i = { 5, 7, 7, 8, 8, 10 };
    
    ASSERT_THAT(t34::searchRange(i, 8), ElementsAre(3, 4));
    ASSERT_THAT(t34::searchRange(i, 6), ElementsAre(-1, -1));
}
