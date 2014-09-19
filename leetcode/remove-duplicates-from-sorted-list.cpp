// 36ms
// upd short ver
class Solution {
public:
    ListNode *deleteDuplicates(ListNode *head) {
        ListNode *ret = new ListNode(INT_MIN);
        ret->next = head;
        for (ListNode *i=ret; i->next!=nullptr; ) {
            if (i->val == i->next->val) i->next = i->next->next;
            else i = i->next;
        }
        return ret->next;
    }
};

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
