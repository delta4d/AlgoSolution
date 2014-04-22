// 76ms
// DIRTY
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
const int DIRTY = 0x3f3f3f3f;
class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
        if (head == NULL) return head;
        head->val = DIRTY;
        if (head->next == NULL) return NULL;
        if (head->next->val == DIRTY) return head->next;
        return detectCycle(head->next);
    }
};
