#include <gtest/gtest.h>
#include <gmock/gmock.h>
#include <vector>
#include "t01.h"

using std::vector;
using testing::ElementsAre;

TEST(LeetCode_01, twoSum) {
    vector<int> arr = { 2, 7, 11, 15 };
    vector<int> result = t01::twoSum(arr, 9);

    ASSERT_THAT(result, ElementsAre(0, 1));
}
