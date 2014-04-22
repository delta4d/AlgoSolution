// 276ms
// mergesort, O(nlogn)
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
    ListNode *_merge(ListNode *lp, ListNode *rp) {
        ListNode *ret = new ListNode(-1), *tail = ret;
        while (lp != NULL && rp != NULL) {
            if (lp->val < rp->val) tail->next = lp, lp = lp->next;
            else tail->next = rp, rp = rp->next;
            tail = tail->next;
        }
        for (; lp!=NULL; lp=lp->next,tail=tail->next) tail->next = lp;
        for (; rp!=NULL; rp=rp->next,tail=tail->next) tail->next = rp;
        return ret->next;
    }
    ListNode *_mergesort(ListNode *head) {
        if (head == NULL) return head;
        if (head->next == NULL) return head;
        ListNode *mid, *p;
        for (p=mid=head; p!=NULL; mid=mid->next) {
            p = p->next;
            if (p != NULL) p = p->next;
            if (p == NULL) break;
        }
        p = mid->next;
        mid->next = NULL;
        return _merge(_mergesort(head), _mergesort(p));
    }
    ListNode *sortList(ListNode *head) {
        return _mergesort(head);
    }
};
