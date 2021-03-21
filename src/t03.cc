#include <string>
#include <unordered_set>
#include <vector>
#include "t03.h"

using std::string;
using std::unordered_set;
using std::vector;

namespace t03 {
    int max(int a, int b) { return a < b ? b : a; }

    // 滑动窗口
    int lengthOfLongestSubstring(string s) {
        // 窗口
        unordered_set<char> lookup;
        int length = s.size();

        if (length <= 0) {
            return 0;
        }

        int start = 0;
        int result = 0;

        for (int i = 0; i < length; i++) {
            char c = s[i];
            while (lookup.find(c) != lookup.end()) {
                lookup.erase(s[start]);
                start++;
            }

            result = max(result, i - start + 1);
            lookup.insert(c);
        }

        return result;
    };

    // 另一个思路，双指针，遇到重复时，头指针从最初遇到的位置 + 1
    // int lengthOfLongestSubstring(string s)
    // {
    //     //s[start,end) 前面包含 后面不包含
    //     int start(0), end(0), length(0), result(0);
    //     int sSize = int(s.size());
    //     vector<int> vec(128, -1);
    //     while (end < sSize)
    //     {
    //         char tmpChar = s[end];
    //         //仅当s[start,end) 中存在s[end]时更新start
    //         if (vec[int(tmpChar)] >= start)
    //         {
    //             start = vec[int(tmpChar)] + 1;
    //             length = end - start;
    //         }
    //         vec[int(tmpChar)] = end;

    //         end++;
    //         length++;
    //         result = max(result, length);
    //     }
    //     return result;
    // }
}
