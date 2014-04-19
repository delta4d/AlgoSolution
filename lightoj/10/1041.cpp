#include <map>
#include <cstdio>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

const int INF = 0x3f3f3f3f;
const int N = 1 << 7;

int e[N][N];
map <string, int> mp;
char s1[N], s2[N];
int d[N];
bool v[N];

int gao(int n) {
	fill(d, d+n, INF), d[0] = 0;
	fill(v, v+n, false);
	for (int k=0; k<n; ++k) {
		int mn = INF, idx = -1;
		for (int i=0; i<n; ++i) if (!v[i] && d[i] < mn) mn = d[i], idx = i;
		if (idx == -1) return -1;
		v[idx] = true;
		for (int i=0; i<n; ++i) if (!v[i] && e[idx][i] < d[i]) d[i] = e[idx][i];
	}
	int tot = 0;
	for (int i=0; i<n; ++i) tot += d[i];
	return tot;
}

int main() {
	int tc, cn = 0, n;
	for (scanf("%d", &tc); tc--; ) {
		scanf("%d", &n);
		int tot = 0;
		mp.clear();
		for (int i=0; i<2*n; ++i) fill(e[i], e[i]+2*n, INF);
		for (int i=0,cost; i<n; ++i) {
			scanf("%s%s%d", s1, s2, &cost);
			if (!mp.count(s1)) mp[s1] = tot++;
			if (!mp.count(s2)) mp[s2] = tot++;
			int a = mp[s1], b = mp[s2];
			e[a][b] = e[b][a] = min(e[a][b], cost);
		}
		printf("Case %d: ", ++cn);
		int cc = gao(tot);
		if (cc >= 0) printf("%d\n", cc);
		else puts("Impossible");
	}
	return 0;
}

// 307939	2014-01-05 22:45:57	 1041 - Road Construction	 C++	 0.000	 1316	Accepted
