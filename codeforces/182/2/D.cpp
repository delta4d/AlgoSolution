#include <cmath>
#include <cstdio>
#include <algorithm>
using namespace std;

const int INF = 0x3f3f3f3f;
const int MAXN = 128;

int f[MAXN][MAXN];
int a[MAXN], d[MAXN];
int x[MAXN], y[MAXN];
bool v[MAXN];

inline int D(int i, int j) {
	return abs(x[i] - x[j]) + abs(y[i] - y[j]);
}

int gao(const int n, const int s, const int t) {
	fill(d, d+n, INF);	
	d[s] = 0;
	for (int k=0; k<n; ++k) {
		int mn = INF, idx = -1;
		for (int i=0; i<n; ++i) if (!v[i] && d[i] < mn) mn = d[i], idx = i;
		v[idx] = true;
		for (int i=0; i<n; ++i) if (!v[i]) d[i] = min(d[i], d[idx] + f[idx][i]);
	}
	return max(0, d[t]);
}

int main() {
	int n, d;
	scanf("%d%d", &n, &d);

	for (int i=1; i<n-1; ++i) scanf("%d", a+i);
	for (int i=0; i<n; ++i) scanf("%d%d", x+i, y+i);
	for (int i=0; i<n; ++i) for (int j=0; j<n; ++j) {
		if (i == j) continue;
		f[i][j] = D(i, j) * d - a[i];	
	}
	printf("%d\n", gao(n, 0, n-1));

	return 0;
}

// 3684683	 May 6, 2013 9:46:03 AM	delta_4d	 B - Yaroslav and Time	 GNU C++	Accepted	31 ms	
