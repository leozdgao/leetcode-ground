#include "t02.h"

namespace t02 {
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        int borrow_bit = 0;
        ListNode* l1_curr = l1;
        ListNode* l2_curr = l2;
        ListNode* result = nullptr;
        ListNode* tail = nullptr;

        do {
            int l1_val = l1_curr != nullptr ? l1_curr->val : 0;
            int l2_val = l2_curr != nullptr ? l2_curr->val : 0;
            int sum = l1_val + l2_val + borrow_bit;
            int bit_val = sum % 10;
            borrow_bit = sum / 10;

            if (result == nullptr) {
                result = new ListNode(bit_val);
                tail = result;
            } else {
                tail->next = new ListNode(bit_val);
                tail = tail->next;
            }

            if (l1_curr != nullptr) {
                l1_curr = l1_curr->next;
            }

            if (l2_curr != nullptr) {
                l2_curr = l2_curr->next;
            }
        } while (l1_curr != nullptr || l2_curr != nullptr);

        if (borrow_bit != 0) {
            tail->next = new ListNode(borrow_bit);
        }

        return result;
    };
}
