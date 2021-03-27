#include <gtest/gtest.h>
#include <gmock/gmock.h>
#include <vector>
#include "t04.h"

using std::vector;
using testing::ElementsAre;

TEST(LeetCode_04, findMedianSortedArrays) {
    vector<int> nums0_1 = { 1, 3 };
    vector<int> nums0_2 = { 2 };
    double r0 = t04::findMedianSortedArrays(nums0_1, nums0_2);

    ASSERT_EQ(r0, 2);

    vector<int> nums1_1 = { 1, 2 };
    vector<int> nums1_2 = { 3, 4 };
    double r1 = t04::findMedianSortedArrays(nums1_1, nums1_2);
    ASSERT_EQ(r1, 2.5);

    vector<int> nums2_1 = { 0, 0 };
    vector<int> nums2_2 = { 0, 0 };
    double r2 = t04::findMedianSortedArrays(nums2_1, nums2_2);
    ASSERT_EQ(r2, 0);

    vector<int> nums3_1 = {};
    vector<int> nums3_2 = { 2, 3 };
    double r3 = t04::findMedianSortedArrays(nums3_1, nums3_2);
    ASSERT_EQ(r3, 2.5);

    vector<int> nums4_1 = { 2 };
    vector<int> nums4_2 = {};
    double r4 = t04::findMedianSortedArrays(nums4_1, nums4_2);
    ASSERT_EQ(r4, 2);

    vector<int> nums5_1 = { 1, 3 };
    vector<int> nums5_2 = { 2, 7 };
    double r5 = t04::findMedianSortedArrays(nums5_1, nums5_2);
    ASSERT_EQ(r5, 2.5);

    vector<int> nums6_1 = { 3 };
    vector<int> nums6_2 = { -2, -1 };
    double r6 = t04::findMedianSortedArrays(nums6_1, nums6_2);
    ASSERT_EQ(r6, -1);
}
