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

// 8ms
// a little neat than previous one
class Solution {
public:
    ListNode *reverseBetween(ListNode *head, int m, int n) {
        if (m == n) return head;
        ListNode *ret = new ListNode(-1), *i = ret, *j = ret;
        ret->next = head;
        for (int k=1; k<m; ++k) j = j->next;
        i = j->next;
        for (int k=m; k<n; ++k) {
            ListNode *new_head = i->next;
            i->next = i->next->next;
            new_head->next = j->next;
            j->next = new_head;
        }
        return ret->next;
    }
};
