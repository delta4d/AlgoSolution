#include <cmath>
#include <cstdio>
#include <vector>
#include <cstring>
#include <algorithm>
using namespace std;

const int MAXN = 50;

vector <int> e[MAXN];
bool v[MAXN];
int mx[MAXN], my[MAXN];
int h[MAXN], a[MAXN], d[MAXN];

bool dfs(int x) {
	for (int i=(int)e[x].size()-1; i>=0; --i) {
		int y = e[x][i];
		if (v[y]) continue;
		v[y] = true;
		if (my[y] == -1 || dfs(my[y])) {
			mx[x] = y, my[y] = x;
			return true;
		}
	}
	return false;
}

int Hungarian(int n) {
	int ret = 0;
	memset(mx, -1, sizeof(mx));
	memset(my, -1, sizeof(my));
	for (int i=0; i<n; ++i) {
		memset(v, false, sizeof(v));
		ret += dfs(i);
	}
	return ret;
}

int main() {
	int tc, cn = 0, n, m;
	for (scanf("%d", &tc); tc--; ) {
		scanf("%d%d", &n, &m);
		for (int i=0; i<n; ++i) scanf("%d%d%d", h+i, a+i, d+i), e[i].clear();
		for (int i=0,hh,aa,dd; i<m; ++i) {
			scanf("%d%d%d", &hh, &aa, &dd);
			for (int j=0; j<n; ++j) {
				if (abs(h[j] - hh) > 12 || abs(a[j] - aa) > 5 || d[j] != dd) continue;
				e[j].push_back(i);
			}
		}
		printf("Case %d: %d\n", ++cn, Hungarian(n));
	}
	return 0;
}

// 321484	2014-02-08 00:31:09	 1184 - Marriage Media	 C++	 0.004	 1216	Accepted
