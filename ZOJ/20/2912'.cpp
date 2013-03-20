#include <cstdio>
#include <vector>
#include <cstring>
#include <algorithm>
using namespace std;

typedef long long LL;
const int MAXN = 10000;
struct node {
	int x;
	int y;
	int w;
} e[MAXN];
vector<int> conn[MAXN];
int num[MAXN];

void dfs(int root, int parent) {
	int i, t;
	for (i=0; i!=conn[root].size(); ++i) {
		t = conn[root][i];
		if (t == parent) continue;
		dfs(t, root);
		num[root] += num[t];
	}
}

int main() {
	int tc;
	int m, n;
	int i, j, k;
	int x, y, w;
	int r, s, t;
	double sum;
	//freopen("f:\\in.txt", "r", stdin);
	scanf("%d", &tc);
	while (tc--) {
		scanf("%d", &n);
		for (i=0; i<n; ++i) conn[i].clear();
		for (i=0; i<n-1; ++i) {
			scanf("%d %d %d", &x, &y, &w);
			e[i].x = x, e[i].y = y, e[i].w = w;
			conn[x].push_back(y);
			conn[y].push_back(x);
		}
		num[0] = 0;
		for (i=1; i<n; ++i) num[i] = 1;
		dfs(0, -1);
		sum = 0.0;
		num[0] = 1111111111;
		for (i=0; i<n-1; ++i) {
			k = min(num[e[i].x], num[e[i].y]);
			sum += 1.0 * k * (n - k) * e[i].w;
		}
		printf("%.3lf\n", sum*2.0/(double(n)*double(n-1)));
	}
	return 0;
}