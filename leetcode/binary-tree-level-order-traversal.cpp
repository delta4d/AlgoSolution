// 44ms
// tree traversal basics
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
    void _levelOrder(TreeNode *root, int dep, vector <vector <int>> &order) {
        if (root == NULL) return;
        if (dep >= (int)order.size()) order.push_back({});
        order[dep].push_back(root->val);
        _levelOrder(root->left, dep+1, order);
        _levelOrder(root->right, dep+1, order);
    }
    vector<vector<int> > levelOrder(TreeNode *root) {
        vector <vector <int>> ret;
        _levelOrder(root, 0, ret);
        return ret;
    }
};
