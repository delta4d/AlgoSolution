// 308ms
// http://en.wikipedia.org/wiki/Insertion_sort
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
    ListNode *insertionSortList(ListNode *head) {
        if (head == NULL) return head;
        ListNode *ret = new ListNode(-1);
        ret->next = head;
        for (ListNode *p=ret->next,*q=p->next; q!=NULL; ) {
            int v = q->val, mv = 0;
            for (ListNode *s=ret,*t=s->next; t!=q; s=t,t=s->next) {
                if (v < t->val) {
                    p->next = q->next;
                    s->next = q;
                    q->next = t;
                    q = p->next;
                    mv = 1;
                    break;
                }
            }
            if (q == NULL) break;
            if (!mv) p = q, q = p->next;
        }
        return ret->next;
    }
};
