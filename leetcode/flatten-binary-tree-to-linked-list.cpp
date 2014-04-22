// 44ms
// recursive
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
    TreeNode *_f(TreeNode *root) {
        if (root->left == NULL && root->right == NULL) {
            return root;
        }
        TreeNode *L = NULL, *R = NULL;
        if (root->left != NULL) L = _f(root->left);
        if (root->right != NULL) R = _f(root->right);
        if (L == NULL) return R;
        L->right = root->right;
        root->right = root->left;
        root->left = NULL;
        return R == NULL ? L : R;
    }
    void flatten(TreeNode *root) {
        if (root == NULL) return;
        _f(root);
    }
};
