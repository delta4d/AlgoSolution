// 32ms
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
    void _inorderTraversal(TreeNode *root, vector <int> &order) {
        if (root == NULL) return;
        _inorderTraversal(root->left, order);
        order.push_back(root->val);
        _inorderTraversal(root->right, order);
    }
    vector<int> inorderTraversal(TreeNode *root) {
        vector <int> ret;
        _inorderTraversal(root, ret);
        return ret;
    }
};


// 8ms
// iterative
// basic stack usage
typedef pair<TreeNode *, int> stackNode;
class Solution {
public:
    vector<int> inorderTraversal(TreeNode *root) {
        vector <int> ret;
        vector <stackNode> st;
        
        st.push_back(make_pair(root, 0));
        while (!st.empty()) {
            stackNode &top = st.back();
            if (top.first == NULL) {
                st.pop_back();
                continue;
            }
            if (top.second == 0) {
                ++top.second;
                st.push_back(make_pair(top.first->left, 0));
            } else if (top.second == 1) {
                ret.push_back(top.first->val);
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
