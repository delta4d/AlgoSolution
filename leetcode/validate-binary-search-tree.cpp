// 72ms
// tree basic
/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
const int INF = 0x3f3f3f3f;
class Solution {
public:
    bool _isValid(TreeNode *root, int &mn, int &mx) {
        int lmn, lmx, rmn, rmx;
        bool ret = true;
        mn = INF, mx = -INF;
        if (root == NULL) return true;
        ret = _isValid(root->left, lmn, lmx) && _isValid(root->right, rmn, rmx);
        ret = ret && lmx < root->val && rmn > root->val;
        mn = min(root->val, min(lmn, rmn)), mx = max(root->val, max(lmx, rmx));
        return ret;
    }
    bool isValidBST(TreeNode *root) {
        int mx, mn;
        return _isValid(root, mn, mx);
    }
};
