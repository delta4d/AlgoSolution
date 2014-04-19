#include <cstdio>
#include <vector>
#include <cstring>
#include <algorithm>
using namespace std;

const int MAXN = 1000;

vector <int> e[MAXN];
bool v[MAXN];
int mx[MAXN], my[MAXN];

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
		for (int i=0; i<n; ++i) e[i].clear();
		for (int i=0,a,b; i<m; ++i) {
			scanf("%d%d", &a, &b);
			e[a-1].push_back(b-1);
		}
		printf("Case %d: %d\n", ++cn, n-Hungarian(n));
	}
	return 0;
}

// 321646	2014-02-08 20:20:24	 1403 - Air Raid	 C++	 0.488	 1380	Accepted
