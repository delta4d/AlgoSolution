// 192ms
// postorder gives root
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
    TreeNode *_build(int &st, vector <int> &post, int a, int b, vector <int> &in) {
        if (a > b) return NULL;
        --st;
        if (a == b) return new TreeNode(in[a]);
        TreeNode *root = new TreeNode(post[st]);
        for (int i=a; i<=b; ++i) if (in[i] == post[st]) {
            root->right = _build(st, post, i+1, b, in);
            root->left = _build(st, post, a, i-1, in);
            return root;
        }
    }
    TreeNode *buildTree(vector<int> &inorder, vector<int> &postorder) {
        int st = (int)postorder.size();
        return _build(st, postorder, 0, (int)inorder.size()-1, inorder);
    }
};
