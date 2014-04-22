// 60ms
// linked list basic
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode *deleteDuplicates(ListNode *head) {
        if (head == NULL) return head;
        ListNode *p = head, *q = p->next;
        while (q != NULL) {
            if (q->val == p->val) {
                p->next = q->next;
                if (p != NULL) q = p->next;
                else q = NULL;
            } else {
                p = q;
                q = p->next;
            }
        }
        return head;
    }
};
