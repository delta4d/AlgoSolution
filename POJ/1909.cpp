#include <cstdio>
#include <vector>
#include <cstring>
using namespace std;

const int MAXN = 10001;

struct node {
	int left;
	int move;
	node(int _left=0, int _move=0):left(_left), move(_move) {}
} info[MAXN];

vector<int> tree[MAXN];
bool root[MAXN];

int dfs(int root) {
	int i, j, k;
	info[root].move = 0;
	for (i=0; i!=tree[root].size(); ++i) {
		k = tree[root][i];
		dfs(k);
		info[root].left += info[k].left;
		info[root].move += abs(info[k].left) + info[k].move;
	}
	return info[root].move;
}

int main() {
	int i, j, k;
	int n, m;
	int x, y, z, w;
	//freopen("f:\\in.txt", "r", stdin);
	scanf("%d", &n);
	while (n != 0) {
		for (i=1; i<=n; ++i) tree[i].clear();
		memset(root, true, sizeof(root));
		for (i=1; i<=n; ++i) {
			scanf("%d %d %d", &x, &w, &m);
			info[x].left = w - 1, info[x].move = 0;
			for (j=0; j<m; ++j) {
				scanf("%d", &y);
				tree[x].push_back(y);
				root[y] = false;
			}
		}
		for (i=1; i<=n; ++i) if (root[i]) {
			printf("%d\n", dfs(i));
			break;
		}
		scanf("%d", &n);
	}
	return 0;
}