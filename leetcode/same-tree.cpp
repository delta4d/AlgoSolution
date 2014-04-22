// 28ms
// tree traversal
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
    bool _isSameTree(TreeNode *p, TreeNode *q) {
        if (p == NULL && q == NULL) return true;
        if (p == NULL && q != NULL) return false;
        if (p != NULL && q == NULL) return false;
        if (p->val != q->val) return false;
        return _isSameTree(p->left, q->left) && _isSameTree(p->right, q->right);
    }
    bool isSameTree(TreeNode *p, TreeNode *q) {
        return _isSameTree(p, q);
    }
};
