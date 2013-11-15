#include <cstdio>
#include <vector>
#include <cstring>
#include <algorithm>
using namespace std;

const int MAXN = 100086;

vector <int> f[MAXN];
bool is_child[MAXN], is_leaf[MAXN];
int dep[MAXN], parent[MAXN];
int n;

void dfs(int root, int d) {
	dep[root] = d;
	for (int i=0; i<f[root].size(); ++i) dfs(f[root][i], d+1);
}

int main() {
	int i, j, k;
	int m, id;
	int root;

	scanf("%d", &n);
	for (i=0; i<n; ++i) {
		scanf("%d%d", &id, &m);
		if (!m) is_leaf[id] = true;
		for (j=0; j<m; ++j) {
			scanf("%d", &k);
			f[id].push_back(k);
			is_child[k] = true;
			parent[k] = id;
		}
	}
	for (i=0; i<n; ++i) if (!is_child[i]) {
		root = i;
		parent[root] = -1;
		is_leaf[root] = false;
		break;
	}
	dfs(root, 0);
	for (i=0; i<n; ++i) {
		printf("node %d: parent = %d, depth = %d, %s, ", i, parent[i], dep[i], is_leaf[i]?"leaf":(i==root?"root":"internal node"));
		printf("[");
		for (j=0; j<f[i].size(); ++j) printf("%d%s", f[i][j], j==f[i].size()-1?"":", ");
		puts("]");
	}

	return 0;
}
