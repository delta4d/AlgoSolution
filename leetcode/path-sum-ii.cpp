// 56ms
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
    void _ps(TreeNode *root, int rem, vector <int> &cc, vector <vector <int>> &ret) {
        if (root == NULL) return;
        rem -= root->val;
        cc.push_back(root->val);
        if (root->left == NULL && root->right == NULL) {
            if (rem == 0) ret.push_back(cc);
            cc.pop_back();
            return;
        }
        _ps(root->left, rem, cc, ret);
        _ps(root->right, rem, cc, ret);
        cc.pop_back();
    }
    vector<vector<int> > pathSum(TreeNode *root, int sum) {
        vector <vector <int>> ret;
        vector <int> cc;
        _ps(root, sum, cc, ret);
        return ret;
    }
};
