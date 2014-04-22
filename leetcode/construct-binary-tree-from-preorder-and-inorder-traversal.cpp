// 156ms
// preorder gives root
// inorder gives root->left and root->right
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
    TreeNode *_build(int &st, vector <int> &pre, int a, int b, vector <int> &in) {
        if (a > b) return NULL;
        ++st;
        if (a == b) return new TreeNode(in[a]);
        TreeNode *root = new TreeNode(pre[st]);
        for (int i=a; i<=b; ++i) if (in[i] == pre[st]) {
            root->left = _build(st, pre, a, i-1, in);
            root->right = _build(st, pre, i+1, b, in);
            return root;
        }
    }
    TreeNode *buildTree(vector<int> &preorder, vector<int> &inorder) {
        int st = -1;
        return _build(st, preorder, 0, (int)inorder.size()-1, inorder);
    }
};
