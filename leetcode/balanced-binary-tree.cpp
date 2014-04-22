// 88ms
// basic tree traversal
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
    int depth(TreeNode *root) {
        if (root == NULL) return 0;
        int ld = depth(root->left), rd = depth(root->right);
        if (ld < 0 || rd < 0 || ld - rd > 1 || rd - ld > 1) return -2;
        return max(ld, rd) + 1;
    }
    bool isBalanced(TreeNode *root) {
        return depth(root) >= 0;
    }
};
