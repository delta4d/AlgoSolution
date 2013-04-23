#include <cstdio>
#include <vector>
#include <algorithm>
#include <functional>
using namespace std;

const int INF = 0x3f3f3f3f;
const int MAXN = 222;
const int MAXM = MAXN * MAXN >> 1;
typedef pair <int, int> PII;

int d[MAXN][MAXN];
int a[MAXM], b[MAXM], w[MAXM];

int main() {
	int n, m;

	scanf("%d%d", &n, &m);
	for (int i=0; i<n; ++i) fill(d[i], d[i]+n, INF);
	for (int i=0; i<n; ++i) d[i][i] = 0;
	for (int i=0; i<m; ++i) {
		scanf("%d%d%d", a+i, b+i, w+i), --a[i], --b[i];
		d[a[i]][b[i]] = d[b[i]][a[i]] = w[i];
	}	
	for (int k=0; k<n; ++k) for (int i=0; i<n; ++i) for (int j=0; j<n; ++j) {
		d[i][j] = min(d[i][j], d[i][k] + d[k][j]);
	}
	int mn = INF;
	for (int k=0; k<m; ++k) {
		vector <PII> e;
		for (int i=0; i<n; ++i) e.push_back(make_pair(d[a[k]][i], d[b[k]][i]));	
		sort(e.begin(), e.end(), greater<PII>());
		for (int i=0,cc,mx=0; i<n; ++i) {
			if (e[i].first - mx < w[k] && mx - e[i].first < w[k]) cc = e[i].first + mx + w[k];	
			else cc = max(e[i].first, mx) << 1;
			mn = min(mn, cc), mx = max(mx, e[i].second);
		}
	}	
	printf("%d.%d\n", mn>>1, 5*(mn&1));

	return 0;
}

// 3609234	 Apr 23, 2013 9:10:03 AM	delta_4d	 266D - BerDonalds	 GNU C++	Accepted	 375 ms	 600 KB
