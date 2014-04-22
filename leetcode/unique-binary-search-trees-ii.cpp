// 96ms
// dfs
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
    vector<TreeNode *> _g(int a, int b) {
        if (a > b) return {NULL};
        vector <TreeNode *> ret;
        for (int i=a; i<=b; ++i) {
            vector <TreeNode *> L = _g(a, i-1), R = _g(i+1, b);
            for (auto l: L) for (auto r: R) {
                TreeNode *root = new TreeNode(i);
                root->left = l, root->right = r;
                ret.push_back(root);
            }
        }
        return ret;
    }
    vector<TreeNode *> generateTrees(int n) {
        return _g(1, n);
    }
};
