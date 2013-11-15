#include <cmath>
#include <vector>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

const int INF = 0x3f3f3f3f;
const int MAXN = 2000;
const int MAXD = 32;

int cnt[MAXN];
int E[MAXN<<1];
int L[MAXN<<1];
int H[MAXN];
int M[MAXN][MAXD];
bool visit[MAXN];
vector<int> graph[MAXN];

inline int find_root(const int n) {
	for (int i=1; i<=n; ++i) if (!visit[i]) return i;
}

void dfs(int root, int depth, int &k) {
	int i, j;
	int x;
	//visit[root] = true;
	E[k] = root;
	L[k] = depth;
	H[root] = k;
	++k;
	for (i=0; i!=graph[root].size(); ++i) {
		x = graph[root][i];
		//if (!visit[x]) {
			dfs(x, depth+1, k);
			E[k] = root;
			L[k] = depth;
			++k;
		//}
	}
}

inline void dp(int a[], const int n) {
	int i, j, k;
	for (i=0; i<=n; ++i) M[i][0] = i;
	for (j = 1; 1 << j <= n; ++j) {
		for (i = 0; i + (1 << j) - 1 < n; ++i) {
			if (a[M[i][j - 1]] < a[M[i + (1 << (j - 1))][j - 1]]) M[i][j] = M[i][j - 1];
			else M[i][j] = M[i + (1 << (j - 1))][j - 1];
		}
	}
}

void gao(const int root, const int n) {
	int i, j, k(0);
	//memset(visit, false, sizeof(visit));
	dfs(root, 0, k);
	dp(L, (n<<1)-1);
}

int RMQ(int a[], int i, int j) {
	if (i > j) swap(i, j);
	int k = int(log(j - i + 1.0) / log(2.0));
	if (a[M[i][k]] < a[M[j-(1<<k)+1][k]]) return M[i][k];
	return M[j-(1<<k)+1][k];
}

int main() {
	int i, j, k;
	int m, n;
	int x, y;
	int root;
	//freopen("f:\\in.txt", "r", stdin);
	while (scanf("%d", &n) != EOF) {
		for (i=0; i<=n; ++i) graph[i].clear();
		memset(visit, false, sizeof(visit));
		for (i=0; i<n; ++i) {
			//scanf("%d %*c %*c %d %*c", &x, &k);
			scanf("%d %*[: (] %d %*[ )]", &x, &k);
			//printf("%d %d\n", x, k);
			for (j=0; j<k; ++j) {
				scanf("%d", &y);
				graph[x].push_back(y);
				visit[y] = true;
			}
		}
		root = find_root(n);
		gao(root, n);
		scanf("%d", &m);
		memset(cnt, 0, sizeof(cnt));
		for (i=0; i<m; ++i) {
			scanf("%*[^(](%d %d)", &x, &y);
			k = E[RMQ(L, H[x], H[y])];
			++cnt[k];
		}
		for (i=1; i<=n; ++i) if (cnt[i] > 0) printf("%d:%d\n", i, cnt[i]);
		while (getchar() != '\n') {}
	}
	return 0;
}