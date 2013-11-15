#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

#define cp(x, y) ((x) > (y)) // max heap, change it when needed

typedef int ele_type;
const int NIL = -1;
const int MAXN = 100000 + 86;

struct leftist_heap {
	int parent, left, right, s;
	ele_type key;

	leftist_heap(int _parent=NIL, int _left=NIL, int _right=NIL, int _s=0, ele_type _key=0):parent(_parent), left(_left), right(_right), s(_s), key(_key) {}
	void init(ele_type _key=0) { s = 0, parent = left = right = NIL, key = _key; }
} lh[MAXN];

// find the root of node x in some heap
int find_root(int x) {
	return lh[x].parent == NIL ? x : find_root(lh[x].parent);
}

// merge two heap x and y
int merge(int x, int y) {
	if (x == NIL) return y;
	if (y == NIL) return x;

	if (!cp(lh[x].key, lh[y].key)) swap(x, y);
	int rx = merge(lh[x].right, y);
	lh[x].right = rx;
	lh[rx].parent = x;
	
	if (lh[x].left == NIL) {
		swap(lh[x].left, lh[x].right);
		lh[x].s = 1;
	} else {
		if (lh[lh[x].left].s < lh[lh[x].right].s) swap(lh[x].left, lh[x].right);
		lh[x].s = lh[lh[x].right].s + 1;	
	}
	return x;
}

// delete node x in one heap
// ======= this part is not tested =========
int del(int x) {
	if (x == NIL) return NIL;
	int root, left, right, parent;
	
	left = lh[x].left, right = lh[x].right, parent = lh[x].parent;
	lh[x].init();
	root = merge(lh[x].left, lh[x].right);
	lh[root].parent = parent;
	
	if (parent != NIL) {
		if (lh[parent].left == x) lh[parent].left = root;
		else if (lh[parent].right == x) lh[parent].right = root;
	}
	while (parent != NIL) {
		if (lh[parent].left == NIL || lh[lh[parent].left].s < lh[lh[parent].right].s) swap(lh[parent].left, lh[parent].right);
		if (lh[lh[parent].right].s + 1 == lh[parent].s) break;
		lh[parent].s = lh[lh[parent].right].s + 1;
		root = parent;
		parent = lh[parent].parent;
	}

	return parent == NIL ? root : find_root(parent);
}

// return the top (min | max) value of heap contains node x
ele_type top(int x) {
	return lh[find_root(x)].key;
}

// leftist heap initialization
void init(int sz=MAXN) {
	for (int i=0; i<sz; ++i) lh[i].init();
}

// ZOJ 2334
int main() {
	int i, j, k;
	int m, n;
	int x, y;

//	freopen("in.txt", "r", stdin);
	while (1 == scanf("%d", &n)) {
		for (i=0; i<n; ++i) {
			lh[i].init();
			scanf("%d", &lh[i].key);
		}
		scanf("%d", &m);
		while (m--) {
			scanf("%d%d", &x, &y);
			--x, --y;
			x = find_root(x), y = find_root(y);
			if (x == y) {
				puts("-1");
			} else {
				lh[x].key >>= 1;
				if (lh[x].left != NIL) lh[lh[x].left].parent = NIL;
				if (lh[x].right != NIL) lh[lh[x].right].parent = NIL;
				int L = merge(lh[x].left, lh[x].right);
				lh[x].init(lh[x].key);
				
				lh[y].key >>= 1;
				if (lh[y].left != NIL) lh[lh[y].left].parent = NIL;
				if (lh[y].right != NIL) lh[lh[y].right].parent = NIL;
				int R = merge(lh[y].left, lh[y].right);
				lh[y].init(lh[y].key);
				
				int root = merge(L, R);
				root = merge(root, x);
				root = merge(root, y);
				printf("%d\n", top(root));
			}
		}
	}

	return 0;
}
