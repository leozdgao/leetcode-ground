// 69. x 的平方根
// [二分查找]
// 
// 实现 int sqrt(int x) 函数。
// 计算并返回 x 的平方根，其中 x 是非负整数。
// 由于返回类型是整数，结果只保留整数的部分，小数部分将被舍去。

// 示例 1:
// 输入: 4
// 输出: 2

// 示例 2:
// 输入: 8
// 输出: 2
// 说明: 8 的平方根是 2.82842..., 
//      由于返回类型是整数，小数部分将被舍去。

// 来源：力扣（LeetCode）
// 链接：https://leetcode-cn.com/problems/sqrtx
// 著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。

#include "t69.h"

namespace t69 {
    int mySqrt(int x) {
        if (x == 0) {
            return 0;
        }

        // 下面直接折半了，1就变成特殊情况了
        if (x == 1) {
            return 1;
        }

        int left = 1;
        int right = x / 2;

        while (left <= right) {
            // 加法防溢出 (x + y) / 2 = x + (y - x) / 2
            int mid = left + (right - left) / 2;
            // 用除法防溢出
            int sqrt = x / mid;

            if (sqrt == mid) {
                return mid;
            }

            if (sqrt < mid) {
                // 左区间
                right = mid - 1;
            } else {
                // 右区间
                left = mid + 1;
            }
        }

        return right;
    }
}

