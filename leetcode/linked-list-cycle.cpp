// 84ms
// dfs
// dirty!, changes val
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
const int DIRTY = 0x3f3f3f3f;
class Solution {
public:
    bool _h(ListNode *root) {
        if (root == NULL) return false;
        root->val = DIRTY;
        if (root->next == NULL) return false;
        if (root->next->val == DIRTY) return true;
        return _h(root->next);
    }
    bool hasCycle(ListNode *head) {
        return _h(head);
    }
};

// 52ms
// p1 moves 1 step, p2 moves 2 steps
// see if p2 can catch p1
class Solution {
public:
    bool hasCycle(ListNode *head) {
        ListNode *p1 = head, *p2 = head;
        while (p1 != NULL && p2 != NULL && p2->next != NULL) {
            p1 = p1->next;
            p2 = p2->next->next;
            if (p1 == p2) return true;
        }
        return false;
    }
};
