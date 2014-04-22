// 88ms
// divide and conquer
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
    TreeNode *_BST(int a, int b, vector<int> &num) {
        if (a > b) return NULL;
        if (a == b) {
            TreeNode *root = new TreeNode(num[a]);
            return root;
        }
        int c = (a & b) + ((a ^ b) >> 1);
        TreeNode *root = new TreeNode(num[c]);
        root->left = _BST(a, c-1, num);
        root->right = _BST(c+1, b, num);
    }
    TreeNode *sortedArrayToBST(vector<int> &num) {
        return _BST(0, (int)num.size()-1, num);
    }
};
