// [455] 分发饼干 🍪
// 假设你是一位很棒的家长，想要给你的孩子们一些小饼干。但是，【每个孩子最多只能给一块饼干】。

// 对每个孩子 i，都有一个胃口值 g[i]，这是能让孩子们满足胃口的饼干的最小尺寸；并且每块饼干 j，都有一个尺寸 s[j] 。如果 s[j] >= g[i]，我们可以将这个饼干 j 分配给孩子 i ，这个孩子会得到满足。你的目标是尽可能满足越多数量的孩子，并输出这个最大数值。

// 来源：力扣（LeetCode）
// 链接：https://leetcode-cn.com/problems/assign-cookies
// 著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。

#include <algorithm>
#include "t455.h"

namespace t455 {
  int findContentChildren(vector<int>& g, vector<int>& s) {
    // 资源最大化利用，将最大 size 的饼干优先分配给胃口大的小朋友
    std::sort(g.begin(), g.end());
    std::sort(s.begin(), s.end());

    int sIndex = s.size() - 1;
    int result = 0;

    for (int i = g.size() - 1; i >= 0; i--) {
      // 饼干比胃口大
      if (sIndex >= 0 && s[sIndex]>= g[i]) {
        sIndex--;
        result++;
      }
    }

    return result;
  }
}
