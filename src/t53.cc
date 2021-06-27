// 给定一个整数数组 nums ，找到一个具有最大和的连续子数组（子数组最少包含一个元素），返回其最大和。

// 示例 1：

// 输入：nums = [-2,1,-3,4,-1,2,1,-5,4]
// 输出：6
// 解释：连续子数组 [4,-1,2,1] 的和最大，为 6 。


// 来源：力扣（LeetCode）
// 链接：https://leetcode-cn.com/problems/maximum-subarray
// 著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。

#include "t53.h"

namespace t53 {
    int maxSubArray(vector<int>& nums) {
        int count = 0;
        int result = INT_MIN;
        int len = nums.size();

        // 暴力求解
        // for (int i = 0; i < len; i++) {
        //     count = 0;

        //     for (int j = i; j < len; j++) {
        //         int val = nums[j];
        //         count += val;

        //         if (count > result) {
        //             result = count;
        //         }
        //     }
        // }


        // 贪心算法，任何加和后使结果小于0的数据一定会让最后的结果更小，此时直接中断连续
        for (int i = 0; i < len; i++) {
            int val = nums[i];
            count += val;

            if (count > result) {
                result = count;
            }

            if (count < 0) {
                count = 0;
            }
        }

        return result;
    }
}
