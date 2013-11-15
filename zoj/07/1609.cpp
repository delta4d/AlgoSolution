#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

const int INF = 0x3f3f3f3f;
const int MAXN = 6;
int f[MAXN][MAXN];
int res;
//int out[MAXN], tout[MAXN];
bool visit[MAXN];

void dfs(const int n, const int src, int s, int d, int cur) {
	int i, j, k;
	if (cur >= res) return;
	if (d == n - 1) {
		res = min(res, cur+f[s][src]);
		return;
	}
	for (i=0; i<n; ++i) {
		if (!visit[i]) {
			visit[i] = true;
			//tout[d+1] = i;
			dfs(n, src, i, d+1, cur+f[s][i] );
			visit[i] = false;
		}
	}
}

int main() {
	int i, j, k;
	int n;
	//freopen("f:\\in.txt", "r", stdin);
	while (scanf("%d", &n) != EOF) {
		for (i=0; i<n; ++i) for (j=0; j<n; scanf("%d", f[i]+(j++)));
		res = INF;
		for (i=0; i<n; ++i) {
			memset(visit, false, sizeof(visit));
			visit[i] = true;
			//tout[0] = i;
			dfs(n, i, i, 0, 0);
		}
		printf("%d\n", res);
	}
	return 0;
}