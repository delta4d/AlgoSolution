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

// O(1) space
// line length a, cycle length c, meet pos in cycle x, meet time t
// t  - a = x (mod c)
// 2t - a = x (mod c)
// => a + x = t = 0 (mod c)
class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
        ListNode *a = head, *b = head;
        while (a != nullptr && b != nullptr && b->next != nullptr) {
            a = a->next, b = b->next->next;
            if (a == b) break;
        }
        if (a == nullptr || b == nullptr || b->next == nullptr) return nullptr;
        a = head;
        while (a != b) a = a->next, b = b->next;
        return a;
    }
};
