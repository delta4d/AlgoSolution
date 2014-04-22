// 44ms
// basci tree traversal
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
    bool _isSymmetric(TreeNode *L, TreeNode *R) {
        if (L == NULL && R == NULL) return true;
        if (L == NULL && R != NULL) return false;
        if (L != NULL && R == NULL) return false;
        if (L->val != R->val) return false;
        return _isSymmetric(L->left, R->right) && _isSymmetric(L->right, R->left);
    }
    bool isSymmetric(TreeNode *root) {
        if (root == NULL) return true;
        return _isSymmetric(root->left, root->right);
    }
};
