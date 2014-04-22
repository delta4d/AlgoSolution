// 20ms
// record the first node with value >= x
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
    ListNode *partition(ListNode *head, int x) {
        ListNode *ret = new ListNode(x-1), *cc = NULL, *pp = NULL;
        ret->next = head;
        for (ListNode *p=ret,*q; p!=NULL; ) {
            if (p->val >= x) {
                if (cc == NULL) {
                    cc = p, pp = q;
                }
                q = p, p = p->next;
            } else {
                if (cc != NULL) {
                    pp->next = p;
                    q->next = p->next;
                    p->next = cc;
                    pp = p;
                    p = q->next;
                } else {
                    q = p, p = p->next;
                }
            }
        }
        return ret->next;
    }
};
