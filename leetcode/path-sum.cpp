// 56ms
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
    bool _hasPathSum(TreeNode *root, int sum) {
        sum -= root->val;
        if (root->left == NULL && root->right == NULL) return sum == 0;
        return root->left != NULL && _hasPathSum(root->left, sum) 
            || root->right != NULL && _hasPathSum(root->right, sum);
    }
    bool hasPathSum(TreeNode *root, int sum) {
        if (root == NULL) return false;
        return _hasPathSum(root, sum);
    }
};
