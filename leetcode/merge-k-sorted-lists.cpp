// 128ms
// merge one by one
// O(nk)
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
    ListNode *_merge(ListNode *a, ListNode *b) {
        ListNode *head = new ListNode(-1), *tail = head, *pa = a, *pb = b;
        for (; pa!=NULL&&pb!=NULL; ) {
            if (pa->val < pb->val) {
                tail->next = new ListNode(pa->val);
                pa = pa->next;
            } else {
                tail->next = new ListNode(pb->val);
                pb = pb->next;
            }
            tail = tail->next;
        }
        for (; pa!=NULL; pa=pa->next,tail=tail->next) tail->next = new ListNode(pa->val);
        for (; pb!=NULL; pb=pb->next,tail=tail->next) tail->next = new ListNode(pb->val);
        return head->next;
    }
    ListNode *mergeKLists(vector<ListNode *> &lists) {
        ListNode *ret = NULL;
        for (auto &li: lists) ret = _merge(ret, li);
        return ret;
    }
};

// 96ms
// same as merge sort
// O(nlog(k))
class Solution {
public:
    ListNode *_merge(ListNode *a, ListNode *b) {
        ListNode *head = new ListNode(-1), *tail = head, *pa = a, *pb = b;
        for (; pa!=NULL&&pb!=NULL; ) {
            if (pa->val < pb->val) {
                tail->next = new ListNode(pa->val);
                pa = pa->next;
            } else {
                tail->next = new ListNode(pb->val);
                pb = pb->next;
            }
            tail = tail->next;
        }
        for (; pa!=NULL; pa=pa->next,tail=tail->next) tail->next = new ListNode(pa->val);
        for (; pb!=NULL; pb=pb->next,tail=tail->next) tail->next = new ListNode(pb->val);
        return head->next;
    }
    ListNode *_mergeKLists(int L, int R, vector<ListNode *> &lists) {
        if (L > R) return NULL;
        if (L == R) return lists[L];
        int M = ((L ^ R) >> 1) + (L & R);
        return _merge(_mergeKLists(L, M, lists), _mergeKLists(M+1, R, lists));
    }
    ListNode *mergeKLists(vector<ListNode *> &lists) {
        return _mergeKLists(0, (int)lists.size()-1, lists);
    }
};
