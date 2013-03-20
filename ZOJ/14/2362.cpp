#include <cstdio>
#include <memory.h>
#include <cstdlib>
using namespace std;

const int MAXN = 411;
struct node {
	int index;
	int weight;
};
inline int	cmp(const void *a, const void *b) {
	node *c = (node *)a;
	node *d = (node *)b;
	return d->weight - c->weight;
}
int n;
node f[MAXN];
int match[MAXN];
int out[MAXN];
bool visit[MAXN];
bool graph[MAXN][MAXN];

bool dfs(const int x) {
	int y;
	for (y=1; y<=n; ++y) {
		if (!visit[y] && graph[x][y]) {
			visit[y] = true;
			if (match[y] == 0 || dfs(match[y])) {
				match[y] = x;
				return true;
			}
		}
	}
	return false;
}

void gao() {
	int i, j, k;
	memset(match, 0, sizeof(match));
	for (i=1; i<=n; ++i) {
		memset(visit, false, sizeof(visit));
		dfs(f[i].index);
	}
	memset(out,0,sizeof(out));
	for (i=1; i<=n; ++i) {
		out[match[i]] = i;
	}
	printf("%d", out[1]);
	for (i=2; i<=n; ++i) printf(" %d", out[i]);
	puts("");
}

int main() {
	int i, j, k, t;
	int tc;
	int x, y;
	//freopen("f:\\in.txt", "r", stdin);
	scanf("%d", &tc);
	for (t=1; t<=tc; ++t) {
		scanf("%d", &n);
		for (i=1; i<=n; ++i) {
			scanf("%d", &f[i].weight);
			f[i].index = i;
		}
		qsort(f+1, n, sizeof(f[0]), cmp);
		memset(graph, false, sizeof(graph));
		for (i=1; i<=n; ++i) {
			scanf("%d", &k);
			for (j=0; j<k; ++j) {
				scanf("%d", &x);
				graph[i][x] = true;
			}
		}
		gao();
		if (t != tc) puts("");
	}
	return 0;
}