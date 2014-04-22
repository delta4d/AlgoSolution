// 96ms
// tree traversal
/**
 * Definition for binary tree with next pointer.
 * struct TreeLinkNode {
 *  int val;
 *  TreeLinkNode *left, *right, *next;
 *  TreeLinkNode(int x) : val(x), left(NULL), right(NULL), next(NULL) {}
 * };
 */
class Solution {
public:
    void _connect(TreeLinkNode *root, TreeLinkNode *parent, bool on_left) {
        if (root == NULL) return;
        if (on_left && parent != NULL) root->next = parent->right;
        if (!on_left && parent != NULL && parent->next != NULL) root->next = parent->next->left;
        _connect(root->left, root, true);
        _connect(root->right, root, false);
    }
    void connect(TreeLinkNode *root) {
        _connect(root, NULL, true);
    }
};
