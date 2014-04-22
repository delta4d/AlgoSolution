// 44ms
// recursive
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
    void _preorder(TreeNode *root, vector <int> &ret) {
        if (root == NULL) return;
        ret.push_back(root->val);
        _preorder(root->left, ret);
        _preorder(root->right, ret);
    }
    vector<int> preorderTraversal(TreeNode *root) {
        vector <int> ret;
        _preorder(root, ret);
        return ret;
    }
};


// 32ms
// iterate, stack usage
typedef pair <TreeNode *, int> state;
class Solution {
public:
    vector<int> preorderTraversal(TreeNode *root) {
        vector <int> ret;
        vector <state> st;
        st.push_back(make_pair(root, 0));
        while (!st.empty()) {
            state &top = st.back();
            if (top.first == NULL) {
                st.pop_back();
                continue;
            }
            if (top.second == 0) {
                ret.push_back(top.first->val);
                ++top.second;
                st.push_back(make_pair(top.first->left, 0));
            } else if (top.second == 1) {
                ++top.second;
                st.push_back(make_pair(top.first->right, 0));
            } else if (top.second == 2) {
                st.pop_back();
            } else {
                throw "dont panic, take it easy";
            }
        }
        return ret;
    }
};
