#include <algorithm>
#include <vector>
#include "t04.h"

using std::vector;
using std::swap;
using std::max;
using std::min;

namespace t04 {
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        // 方法一：归并求中位数，时间复杂度 O(m + n)
        // auto i1 = nums1.cbegin();
        // auto i2 = nums2.cbegin();
        // vector<int> tmp = {};

        // while (i1 != nums1.cend() || i2 != nums2.cend()) {
        //     if (i1 == nums1.cend()) {
        //         tmp.push_back(*i2);
        //         i2++;
        //         continue;
        //     }

        //     if (i2 == nums2.cend()) {
        //         tmp.push_back(*i1);
        //         i1++;
        //         continue;
        //     }

        //     if (*i1 < *i2) {
        //         tmp.push_back(*i1);
        //         i1++;
        //     } else {
        //         tmp.push_back(*i2);
        //         i2++;
        //     }
        // }
        
        // int s = tmp.size();

        // if (s % 2 == 0) {
        //     return double (tmp[s / 2 - 1] + tmp[s / 2]) / 2;
        // } else {
        //     return double (tmp[(s - 1) / 2]);
        // }

        // 方法二：二分查找
        int m = nums1.size();
        int n = nums2.size();

        if (m > n) {
            swap(nums1, nums2);
            swap(m, n);
        }

        // 不论总数奇偶，左边元素个数总是满足该条件（m + n为偶数时会向下取整）
        int left_total_size = (m + n + 1) / 2;
        // 下面用二分查找找到分割线
        int left = 0;
        int right = m;
        int max_l = 0;
        int min_r = 0;

        while (left <= right) {
            int i = left + (right - left) / 2;
            int j = left_total_size - i;

            int nums1_l = i <= 0 ? INT_MIN : nums1[i - 1];
            int nums1_r = i >= m ? INT_MAX : nums1[i];
            int nums2_l = j <= 0 ? INT_MIN : nums2[j - 1];
            int nums2_r = j >= n ? INT_MAX : nums2[j];

            // 在二分临界值下，保证判断逻辑严谨
            if (nums1_l <= nums2_r) {
                left = i + 1;
                max_l = max(nums1_l, nums2_l);
                min_r = min(nums1_r, nums2_r);
            } else {
                right = i - 1;
            }
        }

        if ((m + n) % 2 == 0) {
            return double (max_l + min_r) / 2;
        } else {
            return double (max_l);
        }
    }
}
