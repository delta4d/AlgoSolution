#include <cstdio>
#include <vector>
#include <cstring>
#include <algorithm>
using namespace std;

const int MAXN = 1 << 10;

int x[MAXN], avg, sum, cnt;
vector <int> e[MAXN];
bool v[MAXN];

void gao(int r) {
	v[r] = true, sum += x[r], ++cnt;
	for (int i=0; i<(int)e[r].size(); ++i) {
		int c = e[r][i];
		if (v[c]) continue;
		gao(c);
	}
}

int main() {
	int tc, cn = 0, n, m;
	for (scanf("%d", &tc); tc--; ) {
		scanf("%d%d", &n, &m);
		int tot = 0;
		for (int i=0; i<n; ++i) scanf("%d", x+i), tot += x[i], e[i].clear();
		for (int i=0,u,v; i<m; ++i) scanf("%d%d", &u, &v), --u, --v, e[u].push_back(v), e[v].push_back(u);
		printf("Case %d: ", ++cn);
		if (tot % n) {
			puts("No");
		} else {
			avg = tot / n;
			bool ok = true;
			memset(v, false, sizeof(v));
			for (int i=0; ok&&i<n; ++i) if (!v[i]) {
				sum = 0, cnt = 0;
				gao(i);
				if (sum != cnt * avg) ok = false;
			}
			puts(ok?"Yes":"No");
		}
	}
	return 0;
}

// 307698	2014-01-05 14:49:43	 1263 - Equalizing Money	 C++	 0.220	 1508	Accepted
