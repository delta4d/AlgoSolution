// 28ms
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
    void _pt(TreeNode *root, vector <int> &ret) {
        if (root == NULL) return;
        _pt(root->left, ret);
        _pt(root->right, ret);
        ret.push_back(root->val);
    }
    vector<int> postorderTraversal(TreeNode *root) {
        vector <int> ret;
        _pt(root, ret);
        return ret;
    }
};
