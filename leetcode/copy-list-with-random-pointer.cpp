// 300ms
// dfs
/**
 * Definition for singly-linked list with a random pointer.
 * struct RandomListNode {
 *     int label;
 *     RandomListNode *next, *random;
 *     RandomListNode(int x) : label(x), next(NULL), random(NULL) {}
 * };
 */
class Solution {
public:
    RandomListNode * _c(RandomListNode *root, unordered_map <RandomListNode *, RandomListNode *> &h) {
        if (root == NULL) return root;
        if (h.count(root)) return h[root];
        RandomListNode *ret = new RandomListNode(root->label);
        h[root] = ret;
        ret->next = _c(root->next, h);
        ret->random = _c(root->random, h);
        return ret;
    }
    RandomListNode *copyRandomList(RandomListNode *head) {
        unordered_map <RandomListNode *, RandomListNode *> h;
        return _c(head, h);
    }
};
