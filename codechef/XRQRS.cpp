#include <bits/stdc++.h>
using namespace std;

int const N = 5e5 + 10;
int const DEPTH = 20;

namespace trie {
	struct node {
		int cnt;
		int nxt[2];
		node(int c=0):cnt(c) { nxt[0] = nxt[1] = 0; }
	} f[N*21];
	int next_node = 1;
	int root[N];
	
	int insert(int r, int x, int d) {
		int cur = next_node++;
		f[cur] = f[r];
		++f[cur].cnt;
		if (d >= 0) {
			int b = x >> d & 1;
			f[cur].nxt[b] = insert(f[r].nxt[b], x, d-1);
		}
		return cur;
	}

	int query(int l, int r, int x, int d) {
		if (d < 0) return 0;
		int b = x >> d & 1, c = b ^ 1;
		if (f[f[r].nxt[c]].cnt - f[f[l].nxt[c]].cnt > 0) {
			return (c << d) + query(f[l].nxt[c], f[r].nxt[c], x, d-1);
		}
		return (b << d) + query(f[l].nxt[b], f[r].nxt[b], x, d-1);
	}
}

namespace segtree {
	struct node {
		int sum, left, right;
		node(int s=0, int l=0, int r=0):sum(s), left(l), right(r) {}
	} f[N*21];
	int next_node = 1;
	int root[N];

	int insert(int r, int L, int R, int x) {
		if (R < x || L > x || L > R) return r;
		int cur = next_node++;
		f[cur] = f[r];
		if (L == R) {
			++f[cur].sum;
		} else {
			int M = L + (R - L) / 2;
			f[cur].left = insert(f[r].left, L, M, x);
			f[cur].right = insert(f[r].right, M+1, R, x);
			f[cur].sum = f[f[cur].left].sum + f[f[cur].right].sum;
		}
		return cur;
	}

	int query_rank(int l, int r, int L, int R, int x) {
		if (L > x || L > R) return 0;
		if (R <= x) return f[r].sum - f[l].sum;
		int M = L + (R - L) / 2;
		return query_rank(f[l].left, f[r].left, L, M, x)
			 + query_rank(f[l].right, f[r].right, M+1, R, x);
	}

	int query_kth(int l, int r, int L, int R, int k) {
		if (L == R) return L;
		int sum = f[f[r].left].sum - f[f[l].left].sum;
		int M = L + (R - L) / 2;
		if (sum < k) return query_kth(f[l].right, f[r].right, M+1, R, k-sum);
		return query_kth(f[l].left, f[r].left, L, M, k);
	}
}

int main() {
	int q, op, l, r, x, k, n = 1;
	for (scanf("%d", &q); q--; ) {
		scanf("%d", &op);
		if (op == 0) {
			scanf("%d", &x);
			trie::root[n] = trie::insert(trie::root[n-1], x, DEPTH);
			segtree::root[n] = segtree::insert(segtree::root[n-1], 1, N, x);
			++n;
		} else if (op == 1) {
			scanf("%d%d%d", &l, &r, &x);
			int t = trie::query(trie::root[l-1], trie::root[r], x, DEPTH);
			printf("%d\n", t);
		} else if (op == 2) {
			scanf("%d", &k);
			n -= k;
		} else if (op == 3) {
			scanf("%d%d%d", &l, &r, &x);
			int t = segtree::query_rank(segtree::root[l-1], segtree::root[r], 1, N, x);
			printf("%d\n", t);
		} else {
			scanf("%d%d%d", &l, &r, &k);
			int t = segtree::query_kth(segtree::root[l-1], segtree::root[r], 1, N, k);
			printf("%d\n", t);
		}
	}
	return 0;
}

// 905010	delta_4d	100 [100pts]	5.68	247.2M	C++14	
