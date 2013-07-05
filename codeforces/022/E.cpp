#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;

const int MAXN = 100000 + 86;

int e[MAXN], colo[MAXN], cn;
int x[MAXN], y[MAXN], sz;
vector <pair<int, int> > d;

int dfs(int r) { return colo[r] == cn ? r : (colo[r] = cn, e[r] = dfs(e[r])); }

int main() {
	int n;

	scanf("%d", &n);
	d.resize(n);
	for (int i=1; i<=n; ++i) scanf("%d", e+i), ++d[e[i]-1].first, d[i-1].second = i;
	sort(begin(d), end(d));
	for (int i=0,j; i<n; ++i) {
		if (colo[j = d[i].second]) continue;
		++cn, x[sz] = j, y[sz++] = dfs(j);
	}
	if (sz == 1 && x[0] == y[0]) return puts("0"), 0; 
	printf("%d\n", sz);
	for (int i=0; i<sz; ++i) printf("%d %d\n", y[i], x[i==sz-1?0:i+1]);

	return 0;
}

// 4026783	 Jul 5, 2013 4:06:09 PM	delta_4d	 E - Scheme	 GNU C++0x	Accepted	 78 ms	 5500 KB
