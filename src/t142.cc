// [142] 环形链表 II
// 给定一个链表，返回链表开始入环的第一个节点。 如果链表无环，则返回 null。
// 为了表示给定链表中的环，我们使用整数 pos 来表示链表尾连接到链表中的位置（索引从 0 开始）。 如果 pos 是 -1，则在该链表中没有环。注意，pos 仅仅是用于标识环的情况，并不会作为参数传递到函数中。

// 来源：力扣（LeetCode）
// 链接：https://leetcode-cn.com/problems/linked-list-cycle-ii
// 著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。


// @link: https://mp.weixin.qq.com/s/_QVP3IkRZWx9zIpQRgajzA

#include "t142.h"

using t142::ListNode;

namespace t142 {
  ListNode* detectCycle(ListNode* head) {
    // 环链判断使用快慢指针
    ListNode* slow = head;
    ListNode* fast = head;

    // 直到快指针结束遍历
    while (fast != nullptr && fast->next != nullptr) {
      slow = slow->next;
      fast = fast->next->next;

      // 快慢指针相遇，说明有环，多判断一步 slow 非空用来处理仅有一个节点的情况
      if (slow != nullptr && slow == fast) {
        ListNode* first = head;

        while (first != fast) {
          first = first->next;
          fast = fast->next;
        }

        return fast;
      }
    }
    
    return nullptr;
  }
}
