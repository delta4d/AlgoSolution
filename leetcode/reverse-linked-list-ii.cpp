// 44ms
// store the mth pointer
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
    ListNode *reverseBetween(ListNode *head, int m, int n) {
        ListNode *pm, *qm, *ret = new ListNode(-1);
        int cnt = 0;
        ret->next = head;
        for (ListNode *p=ret,*q; cnt<=n&&p!=NULL; ++cnt) {
            if (cnt == m) {
                pm = p, qm = q;
                q = p, p = p->next;
            } else if (m < cnt && cnt <= n) {
                qm->next = p, q->next = p->next;
                p->next = pm, pm = p, p = q->next;
            } else {
                q = p, p = p->next;
            }
        }
        return ret->next;
    }
};
