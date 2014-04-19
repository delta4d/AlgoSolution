#include <queue>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

const int N = 100;

int x[N][N], y[N][N];
int e[N], f[N];
bool proposed[N][N];
queue <int> q;

int main() {
	int tc, cn = 0, n;
	for (scanf("%d", &tc); tc--; ) {
		scanf("%d", &n);
		for (int i=0; i<n; ++i) for (int j=0; j<n; ++j) scanf("%d", x[i]+j);
		for (int i=0,t; i<n; ++i) for (int j=0; j<n; ++j) scanf("%d", &t), y[i][t-1] = j;
		memset(e, -1, sizeof(e));
		memset(f, -1, sizeof(f));
		memset(proposed, false, sizeof(proposed));
		while (!q.empty()) q.pop();
		for (int i=0; i<n; ++i) q.push(i);
		while (!q.empty()) {
			int t = q.front(); q.pop();
			int s = 0;
			for (int i=0; i<n; ++i) if (!proposed[t][x[t][i]-n-1]) {
				s = x[t][i] - n - 1;
				proposed[t][s] = true;
				if (f[s] == -1) {
					f[s] = t, e[t] = s;
					break;
				}
				int tt = f[s];
				if (y[s][t] < y[s][tt]) {
					f[s] = t, e[t] = s;
					q.push(tt);
					break;
				}
			}
		}
		printf("Case %d: ", ++cn);
		for (int i=0; i<n; ++i) printf("(%d %d)%s", i+1, e[i]+1+n, i==n-1?"\n":" ");
	}
	return 0;
}

// 318269	2014-01-29 00:44:05	 1400 - Employment	 C++	 0.084	 1336	Accepted
