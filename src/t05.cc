// 给你一个字符串 s，找到 s 中最长的回文子串。
// 提示：

// 1 <= s.length <= 1000
// s 仅由数字和英文字母（大写和/或小写）组成

// 来源：力扣（LeetCode）
// 链接：https://leetcode-cn.com/problems/longest-palindromic-substring
// 著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。

#include <string>
#include <vector>
#include "t05.h"

using std::string;
using std::vector;

namespace t05 {
    // 暴力实现，三层循环 O(n^3)
    // string longestPalindrome(string s) {
    //     if (s.size() < 2) {
    //         return s;
    //     }

    //     int candnidate_length = 0;
    //     string result = s.substr(0, 1);

    //     for (auto i = s.cbegin(); i < s.cend(); i++) {
    //         for (auto j = i + 1; j < s.cend(); j++) {
    //             auto left = i;
    //             auto right = j;
    //             bool is_palindome = true;

    //             while (left <= right) {
    //                 if (*left == *right) {
    //                     left += 1;
    //                     right -= 1;
    //                 } else {
    //                     is_palindome = false;
    //                     break;
    //                 }
    //             }

    //             if (is_palindome) {
    //                 int sub_length = j - i + 1;
                    
    //                 if (sub_length > candnidate_length) {
    //                     result = string(i, j + 1);
    //                     candnidate_length = sub_length;
    //                 }
    //             }
    //         }
    //     }

    //     return result;
    // }

    // 动态规划版本，二维 O(n^2)
    string longestPalindrome(string s) {
        int len = s.size();
        // 就算没有匹配到，还是会取第一个字符
        int maxLen = 1;
        int begin = 0;

        if (len < 2) {
            return s;
        }

        int dp[len][len];
        for (int i = 0; i < len; i++) {
            dp[i][i] = true;
        }

        for (int j = 1; j < len; j++) {
            for (int i = 0; i < j; i++) {
                if (s[i] != s[j]) {
                    dp[i][j] = false;
                } else {
                    // // 长度为 2 或 3, 子问题 [i+1,j-1] 不构成区间, 即 j-1-(i+1)+1<2, 即为 j-i<3
                    if (j - i < 3) {
                        dp[i][j] = true;
                    } else {
                        dp[i][j] = dp[i + 1][j - 1];
                    }
                }

                if (dp[i][j] && j - i + 1 > maxLen) {
                    maxLen = j - i + 1;
                    begin = i;
                }
            }
        }

        return s.substr(begin, maxLen);
    }
}
