// 340ms
/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
int p;
TreeNode *x[10];
class Solution {
public:
    void _r(TreeNode *root, TreeNode *c[], int &pc) {
        if (root == NULL) return;
        _r(root->left, c, pc);
        if (pc < 3) c[pc++] = root;
        else c[0] = c[1], c[1] = c[2], c[2] = root;
        if (pc == 3) {
            int L = c[0]->val, M = c[1]->val, R = c[2]->val;
            if (M < L || M > R) x[p++] = c[1];
        } else if (pc == 2) {
            if (c[0]->val > c[1]->val) x[p++] = c[0];
        }
        _r(root->right, c, pc);
    }
    void recoverTree(TreeNode *root) {
        TreeNode *c[3];
        int pc = 0;
        p = 0;
        _r(root, c, pc);
        if (pc == 1) return;
        if (c[pc-1]->val < c[pc-2]->val) x[p++] = c[pc-1];
        if (p > 2) x[1] = x[p-1];
        swap(x[0]->val, x[1]->val);
    }
};
