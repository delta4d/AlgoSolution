// 28ms
// upd short ver
class Solution {
public:
    ListNode *deleteDuplicates(ListNode *head) {
        ListNode *ret = new ListNode(-1);
        ret->next = head;
        for (ListNode *i=ret,*j; i->next!=nullptr; ) {
            for (j=i; j->next!=nullptr&&j->next->val==i->next->val; j=j->next);
            if (i->next == j) {
                i = i->next;
            } else {
                i->next = j->next;
            }
        }
        return ret->next;
    }
};


// 52ms
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
        if (head->next == NULL) return head;
        ListNode *ret = new ListNode((head->val)-1), *p, *q;
        ret->next = head;
        int cc = 1;
        for (p=ret,q; p->next!=NULL; ) {
            if (p->val == p->next->val) {
                ++cc;
                p->next = p->next->next;
            } else {
                if (cc > 1) {
                    q->next = p->next;
                    p = p->next;
                } else {
                    q = p, p = p->next;
                }
                cc = 1;
            }
        }
        if (cc > 1) {
            q->next = p->next;
            p = p->next;
        }
        return ret->next;
    }
};
