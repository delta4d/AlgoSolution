// O(1) space
class Solution {
public:
    void connect(TreeLinkNode *root) {
        for (TreeLinkNode *cur=root,*nxt,*a,*b; cur!=nullptr; cur=nxt) {
            nxt = a = b = nullptr;
            auto upd = [&](TreeLinkNode *p) {
                if (p == nullptr) return;
                if (nxt == nullptr) nxt = p;
                a = b, b = p;
                if (a != nullptr) a->next = b;
            };
            for (TreeLinkNode *i=cur; i!=nullptr; i=i->next) upd(i->left), upd(i->right);
        }
    }
};

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
