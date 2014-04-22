// 16ms
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
    void levelOrderUp(TreeNode *root, int dep, vector <vector <int>> &ret) {
        if (root == NULL) return;
        if (dep >= (int)ret.size()) ret.push_back({});
        ret[dep].push_back(root->val);
        levelOrderUp(root->left, dep+1, ret);
        levelOrderUp(root->right, dep+1, ret);
    }
    vector<vector<int> > levelOrderBottom(TreeNode *root) {
        vector <vector <int>> ret;
        levelOrderUp(root, 0, ret);
        reverse(begin(ret), end(ret));
        return ret;
    }
};
