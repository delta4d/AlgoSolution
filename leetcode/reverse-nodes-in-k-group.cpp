// 128ms
// simulation
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
    ListNode *reverseKGroup(ListNode *head, int k) {
        if (k == 1 || head == NULL) return head;
        int len = 0;
        for (ListNode *p=head; p!=NULL; p=p->next,++len);
        ListNode *ret = new ListNode(-1);
        int rem = len / k, cnt = 0;
        ret->next = head;
        for (ListNode *pk=ret,*p=pk->next,*t; rem; ) {
            t = p->next;
            p->next = p->next->next;
            t->next = pk->next;
            pk->next = t;
            ++cnt;
            if (cnt + 1 == k) {
                pk = p, p = p->next;
                cnt = 0, --rem;
            }
        }
        return ret->next;
    }
};
