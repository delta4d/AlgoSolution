// 48ms
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
        if (root->left == NULL && root->right == NULL) return 1;
        int ret = 0x3f3f3f3f;
        if (root->left != NULL) ret = min(ret, depth(root->left));
        if (root->right != NULL) ret = min(ret, depth(root->right));
        return ret + 1;
    }
    int minDepth(TreeNode *root) {
        if (root == NULL) return 0;
        return depth(root);
    }
};
