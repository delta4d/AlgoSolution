#include <cstdio>
#include <vector>
#include <cstring>
#include <algorithm>
using namespace std;

const int MAXN = 201;

vector <int> e[MAXN];
int a[MAXN], b[MAXN];
int d[MAXN], n;

void dfs(int r, int p, const int v) {
	for (int i=0; i<e[r].size(); ++i) {
		int k = e[r][i];
		if (k == p || k == v) continue;
		d[k] = d[r] + 1;
		dfs(k, r, v);
	}
}

int far(int r, int p, const int v) {
	memset(d, -1, sizeof(d));
	d[r] = 0;
	dfs(r, p, v);
	int idx = 0;
	for (int i=0; i<n; ++i) if (d[i] > d[idx]) idx = i;
	return idx;
}

int max_length(int r, int p) {
	int r1 = far(r, p, -1);
	int r2 = far(r1, p, p);
	return d[r2];
}

int main() {
	scanf("%d", &n);
	for (int i=0; i+1<n; ++i) {
		scanf("%d%d", a+i, b+i), --a[i], --b[i];
		e[a[i]].push_back(b[i]), e[b[i]].push_back(a[i]);
	}
	int mx = 0;
	for (int i=0; i+1<n; ++i) {
		int c1 = max_length(a[i], b[i]);
		int c2 = max_length(b[i], a[i]);
		mx = max(mx, c1*c2);
//		printf("%d %d %d %d\n", a[i], b[i], c1, c2);
	}
	printf("%d\n", mx);

	return 0;
}

// 3792993	 May 30, 2013 8:46:08 AM	delta_4d	 D - Two Paths	 GNU C++	Accepted	31 ms	84 KB
