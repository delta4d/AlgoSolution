// 8ms
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
    void _sum(TreeNode *root, int cc, int &sum) {
        if (root == NULL) return;
        cc = cc * 10 + root->val;
        if (root->left == NULL && root->right == NULL) {
            sum += cc;
            return;
        }
        _sum(root->left, cc, sum);
        _sum(root->right, cc, sum);
    }
    int sumNumbers(TreeNode *root) {
        int ret = 0;
        _sum(root, 0, ret);
        return ret;
    }
};
