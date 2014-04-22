// 12ms
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
    void _zz(TreeNode *root, int dep, vector <vector <int>> &order) {
        if (root == NULL) return;
        if (dep >= (int)order.size()) order.push_back({});
        order[dep].push_back(root->val);
        _zz(root->left, dep+1, order);
        _zz(root->right, dep+1, order);
    }
    vector<vector<int> > zigzagLevelOrder(TreeNode *root) {
        vector <vector <int>> ret;
        _zz(root, 0, ret);
        for (int i=1; i<(int)ret.size(); ++i,++i) reverse(begin(ret[i]), end(ret[i]));
        return ret;
    }
};
