#include <cstdio>
#include <memory>
using namespace std;

const int MAXN = 100;
int match[MAXN];
bool visit[MAXN];
bool conn[MAXN][MAXN];

bool dfs(int x, const int &m) {
	int i;
	for (i=0; i<m; ++i) {
		if (!visit[i] && conn[x][i]) {
			visit[i] = true;
			if (match[i] == -1 || dfs(match[i], m)) {
				match[i] = x;
				return true;
			}
		}
	}
	return false;
}

void gao(const int &n, const int &m) {
	int i;
	int res(0);
	memset(match, -1, sizeof(match));
	for (i=0; i<n; ++i) {
		memset(visit, false, sizeof(visit));
		if (dfs(i, m)) ++res;
	}
	printf("%d\n", res);
}

int main() {
	int m, n, k;
	int i, j;
	int x, y, t;
	//freopen("f:\\in.txt", "r", stdin);
	scanf("%d", &n);
	while (n != 0) {
		scanf("%d %d", &m, &k);
		//initial graph
		memset(conn, false, sizeof(conn));
		for (i=0; i<k; ++i) {
			scanf("%d %d %d", &t, &x, &y);
			if (x * y != 0) conn[x][y] = true;
		}
		gao(n, m);
		scanf("%d", &n);
	}
	
	return 0;
}