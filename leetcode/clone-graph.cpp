// 240ms
/**
 * Definition for undirected graph.
 * struct UndirectedGraphNode {
 *     int label;
 *     vector<UndirectedGraphNode *> neighbors;
 *     UndirectedGraphNode(int x) : label(x) {};
 * };
 */
class Solution {
public:
    UndirectedGraphNode *_c(UndirectedGraphNode *root, unordered_map <int, UndirectedGraphNode *> &h) {
        if (h.count(root->label)) return h[root->label];
        UndirectedGraphNode *ret = new UndirectedGraphNode(root->label);
        h[root->label] = ret;
        for (auto &c: root->neighbors) (ret->neighbors).push_back(_c(c, h));
        return ret;
    }
    UndirectedGraphNode *cloneGraph(UndirectedGraphNode *node) {
        if (node == NULL) return node;
        unordered_map <int, UndirectedGraphNode *> h;
        return _c(node, h);
    }
};
