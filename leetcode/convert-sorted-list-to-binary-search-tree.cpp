// 112ms
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    TreeNode *_BST(int a, int b, int p[]) {
        if (a > b) return NULL;
        int c = a + ((b - a) >> 1);
        TreeNode *ret = new TreeNode(p[c]);
        if (a == b) return ret;
        ret->left = _BST(a, c-1, p);
        ret->right = _BST(c+1, b, p);
        return ret;
    }
    TreeNode *sortedListToBST(ListNode *head) {
        int n = 0, p[20000];
        for (ListNode *i=head; i!=NULL; i=i->next) p[n++] = i->val;
        return _BST(0, n-1, p);
    }
};
