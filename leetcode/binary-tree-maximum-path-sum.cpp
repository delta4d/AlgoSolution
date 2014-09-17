// 124ms
// tree dp
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
#define UPD(x) {\
    if ((x) >= mx[0]) mx[1] = mx[0], mx[0] = (x); \
    else if ((x) > mx[1]) mx[1] = (x); \
}    
class Solution {
public:
    int _max(TreeNode *root, int mx[]) {
        mx[0] = mx[1] = -INF;
        if (root == NULL) return -INF;
        if (root->left == NULL && root->right == NULL) return mx[0] = root->val;
        int lmx[2], rmx[2], ret = -INF;
        int lv = _max(root->left, lmx), rv = _max(root->right, rmx);
        ret = max(lv, rv);
        ret = max(max(lmx[0], rmx[0]) + root->val, ret);
        ret = max(ret, lmx[0] + rmx[0] + root->val);
        ret = max(ret, root->val);
        for (int i=0; i<2; ++i) {
            UPD(lmx[i]+root->val);
            UPD(rmx[i]+root->val);
        }
        UPD(root->val);
        return ret;
    }
    int maxPathSum(TreeNode *root) {
        int mx[2];
        return _max(root, mx);
    }
};


// a short ver
class Solution {
public:
    int mx;
    int f(TreeNode *root) {
        if (root == nullptr) return 0;
        int ret = root->val;
        int lmx = f(root->left), rmx = f(root->right);
        mx = max({mx, ret, ret+lmx, ret+rmx, ret+lmx+rmx});
        ret = max({ret, ret+lmx, ret+rmx});
        return ret;
    }
    int maxPathSum(TreeNode *root) {
        mx = INT_MIN;
        f(root);
        return mx;
    }
};
