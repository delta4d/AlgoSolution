#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

char buf[51];
struct Trie {
	int mx;
	struct node {
		int dep, cnt;
		node *nxt[4];
		node(int d=0, int c=0):dep(d), cnt(c) {
			nxt[0] = nxt[1] = nxt[2] = nxt[3] = NULL;
		}
		void init() {
			dep = 0, cnt = 0;
			nxt[0] = nxt[1] = nxt[2] = nxt[3] = NULL;
		}
	} *root;

	inline int mp(const char x) {
		if (x == 'A') return 0;
		if (x == 'C') return 1;
		if (x == 'G') return 2;
		return 3;
	}

	void init() {
		mx = 0;
		if (root != NULL) free(root);
		root = new node();
	}

	void insert_node(node *root, char s[], int d) {
		mx = max(mx, root->dep * root->cnt);
		if (s[d] == '\0') return;
		int c = mp(s[d]);
		if (root->nxt[c] == NULL) root->nxt[c] = new node(root->dep+1);
		++(root->nxt[c]->cnt);
		insert_node(root->nxt[c], s, d+1);
		mx = max(mx, root->dep * root->cnt);
	}

	void insert(char s[]) {
		insert_node(root, s, 0);
	}
} T;

int main() {
	int tc, cn = 0, n;
	for (scanf("%d", &tc); tc--; ) {
		scanf("%d", &n);
		T.init();
		for (int i=0; i<n; ++i) {
			scanf("%s", buf);
			T.insert(buf);
		}
		printf("Case %d: %d\n", ++cn, T.mx);
	}
	return 0;
}

// 321008	2014-02-06 22:30:30	 1224 - DNA Prefix	 C++	 0.392	 60484	Accepted
