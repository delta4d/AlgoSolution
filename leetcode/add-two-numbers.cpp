// 192ms
// basic linked list operation [O(n)]
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
 #define ADD(li) if (li != NULL) {\
    sum += li->val; \
    li = li->next; \
 }
class Solution {
public:
    ListNode *addTwoNumbers(ListNode *l1, ListNode *l2) {
        ListNode *head = new ListNode(-1), *p = head;
        int carry = 0;
        while (true) {
            int sum = carry;
            ADD(l1)
            ADD(l2)
            p->val = sum % 10;
            carry = sum / 10;
            if (l1 == NULL && l2 == NULL) break;
            p->next = new ListNode(-1);
            p = p->next;
        }
        if (carry != 0) {
            p->next = new ListNode(-1);
            p = p->next;
            p->val = carry;
        }
        return head;
    }
};
