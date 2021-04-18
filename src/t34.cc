// 给定一个按照升序排列的整数数组 nums，和一个目标值 target。找出给定目标值在数组中的开始位置和结束位置。
// 如果数组中不存在目标值 target，返回 [-1, -1]。
// 
// 进阶：
// 你可以设计并实现时间复杂度为 O(log n) 的算法解决此问题吗？
//  
// 示例 1：
// 输入：nums = [5,7,7,8,8,10], target = 8
// 输出：[3,4]
// 
// 示例 2：
// 输入：nums = [5,7,7,8,8,10], target = 6
// 输出：[-1,-1]
// 
// 示例 3：
// 输入：nums = [], target = 0
// 输出：[-1,-1]
// 
// 来源：力扣（LeetCode）
// 链接：https://leetcode-cn.com/problems/find-first-and-last-position-of-element-in-sorted-array
// 著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。

#include "t34.h"

namespace t34 {
    int lower_bound(vector<int>& nums, int target) {
        int len = nums.size();
        int l = 0;
        int r = len - 1;
        
        while (l <= r) {
            int mid = l + (r - l) / 2;
            int val = nums[mid];

            if (val >= target) {
                r = mid - 1;
            } else {
                l = mid + 1;
            }
        }
        
        return l;
    }

    int higher_bound(vector<int>& nums, int target) {
        int len = nums.size();
        int l = 0;
        int r = len - 1;

        while (l <= r) {
            int mid = l + (r - l) / 2;
            int val = nums[mid];

            if (val > target) {
                r = mid - 1;
            } else {
                l = mid + 1;
            }
        }

        return r;
    }

    vector<int> searchRange(vector<int>& nums, int target) {
        int len = nums.size();

        if (len <= 0) {
            return { -1, -1 };
        }

        // 两次折半分别搜索起始位置和终止位置
        int l = lower_bound(nums, target);

        // 没找到直接返回
        if (l >= len || nums[l] != target) {
            return { -1, -1 };
        }

        int r = higher_bound(nums, target);

        return { l, r };
    }
}
