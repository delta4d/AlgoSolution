// 228ms
// simulation, O(n) time, O(n) space
// O(1) space algo: reverse the later half list and merge with the first half
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
    void reorderList(ListNode *head) {
        vector <ListNode *> ln;
        for (ListNode *p=head; p!=NULL; p=p->next) ln.push_back(p);
        int n = (int)ln.size();
        if (n < 2) return;
        ListNode *tail = ln.back();
        ln.front()->next = ln.back();
        tail->next = NULL;
        for (int i=1; i+i<n; ++i) {
            if (i != n - 1 - i) ln[i]->next = ln[n-1-i];
            tail->next = ln[i];
            tail = ln[n-1-i];
            tail->next = NULL;
        }
    }
};
