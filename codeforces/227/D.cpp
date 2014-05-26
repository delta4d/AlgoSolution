#include <cstdio>
#include <vector>
#include <cstring>
#include <algorithm>
using namespace std;

int const N = 1 << 9;
int const INF = 0x3f3f3f3f;
vector <int> e[N];
int m, n, d[N];
int mx[N], my[N];
bool v[N];

int dfs(int x, int c) {
	for (auto y: e[x]) if (y != c && !v[y]) {
		v[y] = true;
		if (my[y] == -1 || dfs(my[y], c)) {
			mx[x] = y, my[y] = x;
			return true;
		}
	}
	return false;
}

int gao(int c) {
	int ret = 0;
	memset(mx, -1, sizeof(mx));
	memset(my, -1, sizeof(my));
	for (int i=0; i<n; ++i) if (i != c) {
		memset(v, false, sizeof(v));
		ret += dfs(i, c);
	}
	ret = 3 * n + m - 2 * d[c] - ret * 2 - 2;
	return ret;
}

int main() {
	int mn = INF;
	scanf("%d%d", &n, &m);
	for (int i=0,a,b; i<m; ++i) {
		scanf("%d%d", &a, &b), --a, --b;
		e[a].push_back(b);
		if (a == b) ++d[a];
		else ++d[a], ++d[b];
	}
	for (int i=0; i<n; ++i) mn = min(mn, gao(i));
	printf("%d\n", mn);
	return 0;
}

// 6578334	 May 9, 2014 6:44:45 PM	delta_4d	 D - George and Interesting Graph	 GNU C++0x	Accepted	 30 ms	 200 KB
