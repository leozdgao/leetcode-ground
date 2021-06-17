#pragma once

namespace t142 {
  struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x): val(x), next(nullptr) {}
  };
  

  ListNode *detectCycle(ListNode *head);
}
