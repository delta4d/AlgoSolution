// 28ms
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
    void _pt(TreeNode *root, vector <int> &ret) {
        if (root == NULL) return;
        _pt(root->left, ret);
        _pt(root->right, ret);
        ret.push_back(root->val);
    }
    vector<int> postorderTraversal(TreeNode *root) {
        vector <int> ret;
        _pt(root, ret);
        return ret;
    }
};

// iterative
class Solution {
public:
    vector<int> postorderTraversal(TreeNode *root) {
        if (root == nullptr) return {};
        vector <int> ret;
        vector <pair<TreeNode *, int>> st;
        st.push_back({root, 0});
        while (!st.empty()) {
            auto *p = &st.back();
            if (p->second == 0) {
                ++(p->second);
                if (p->first->left != nullptr) {
                    st.push_back({p->first->left, 0});
                }
            } else if (p->second == 1) {
                ++(p->second);
                if (p->first->right != nullptr) {
                    st.push_back({p->first->right, 0});
                }
            } else {
                ret.push_back(p->first->val);
                st.pop_back();
            }
        }
        return ret;
    }
};
