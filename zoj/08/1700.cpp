#include <vector>
#include <cstdio>
#include <cstring>
using namespace std;

const int MAXN = 26;
const int MAXL = 26;

int f[MAXN][2];
char s[MAXN][MAXL];

inline void insert_tree(const int root, const int v) {
	int i, j, k(root);
	while (true) {
		if (v < k) {
			if (f[k][0] == -1) {
				f[k][0] = v;
				return;
			} else {
				k = f[k][0];
			}
		} else {
			if (f[k][1] == -1) {
				f[k][1] = v;
				return;
			} else {
				k = f[k][1];
			}
		}
	}	
}

void travel_tree(int root) {
	int i, j, k;
	printf("%c", root+'A');
	if (f[root][0] != -1) travel_tree(f[root][0]);
	if (f[root][1] != -1) travel_tree(f[root][1]);
}

inline int build_tree(const int n) {
	int i, j, k;
	int len;
	int root(s[n-1][0]-'A');
	memset(f, -1, sizeof(f));
	for (i=n-2; i>=0; --i) {
		len = strlen(s[i]);
		for (k=0; k<len; ++k) {
			insert_tree(root, s[i][k]-'A');
		}
	}
	return root;
}

int main() {
	int root;
	int m, n, d;
	int i, j, k;
	//freopen("f:\\in.txt", "r", stdin);
	scanf("%s", s[0]);
	while (true) {
		n = 1;	
		while (s[n-1][0] != '*' && s[n-1][0] != '$') {
			scanf("%s", s[n]);
			++n;
		}
		--n;
		root = build_tree(n);
		travel_tree(root);
		puts("");
		if (scanf("%s", s[0]) == EOF) break;
	}
	return 0;
}
