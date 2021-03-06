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

// 160ms
// NASTY
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
    void _c(TreeLinkNode *root, TreeLinkNode *parent) {
        if (root == NULL) return;
        TreeLinkNode *next_root = NULL, *next_parent = NULL;
        while (true) {
            if (next_root == NULL) {
                if (root->left != NULL) next_root = root->left;
                else if (root->right != NULL) next_root = root->right;
                next_parent = root;
            }
            if (parent == NULL) break;
            for (; parent!=NULL&&parent->left==NULL&&parent->right==NULL; parent=parent->next);
            if (parent != NULL && parent->left != NULL && parent->left != root) {
                root->next = parent->left, root = root->next;
            } else if (parent != NULL && parent->right != NULL && parent->right != root) {
                root->next = parent->right, root = root->next, parent = parent->next;
            } else if (parent != NULL) {
				parent = parent->next;
            }
        };
        _c(next_root, next_parent);
    }
    void connect(TreeLinkNode *root) {
        _c(root, NULL);
    }
};
