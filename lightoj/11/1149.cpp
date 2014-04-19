#include <cstdio>
#include <vector>
#include <cstring>
#include <algorithm>
using namespace std;

const int MAXN = 100;

vector <int> e[MAXN];
bool v[MAXN];
int mx[MAXN], my[MAXN];
int A[MAXN];

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

int gao(int n) {
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
		scanf("%d", &n);
		for (int i=0; i<n; ++i) scanf("%d", A+i), e[i].clear();
		scanf("%d", &m);
		for (int i=0,x; i<m; ++i) {
			scanf("%d", &x);
			for (int j=0; j<n; ++j) if (x % A[j] == 0) e[j].push_back(i);
		}
		printf("Case %d: %d\n", ++cn, gao(n));
	}
	return 0;
}

// 321475	2014-02-07 23:53:20	 1149 - Factors and Multiples	 C++	 0.000	 1216	Accepted
