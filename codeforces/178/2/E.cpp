#include <cstdio>
#include <vector>
#include <cstring>
#include <algorithm>
using namespace std;

const int MAXN = 5000 + 86;
const long long INF = 0x3f3f3f3f3f3f3f3fll;

int c[MAXN];
vector <pair<int, int> > T[MAXN];
int a[MAXN], b[MAXN], w[MAXN];
long long mn, cc = INF;
int idx, n;

void hn(int r, int p) {
	++n;
	for (int i=0; i<T[r].size(); ++i) {
		if (T[r][i].first == p) continue;
		hn(T[r][i].first, r);
	}
}

void gp(int r, int p) {
	int mx = 0;
	c[r] = 1;
	for (int i=0; i<T[r].size(); ++i) {
		int s = T[r][i].first, w = T[r][i].second;	
		if (s == p) continue;
		gp(s, r);
		c[r] += c[s];
		mx = max(mx, c[s]);
	}	
	mx = max(mx, n - c[r]);	
	if (mx < mn) mn = mx, idx = r;
}

int find_gp(int r, int p) {
	memset(c, 0, sizeof(c));	
	mn = INF, idx = -1;
	n = 0;
	hn(r, p);
	gp(r, p);
	return idx;
}

void gao(int r, int p, int a, int b, int x, int y, int w) {
	c[r] = 1;
	if (r == x && y != p) {
		gao(y, r, a, b, x, y, w);	
		c[r] += c[y];
		mn += (long long)w * c[y] * (n - c[y]);
	}
	if (r == y && x != p) {
		gao(x, r, a, b, x, y, w);
		c[r] += c[x];
		mn += (long long)w * c[x] * (n - c[x]);
	}
	for (int i=0; i<T[r].size(); ++i) {
		int s = T[r][i].first, w0 = T[r][i].second;	
		if (s == p) continue;
		if (r == a && s == b || r == b && s == a) continue;
		gao(s, r, a, b, x, y, w);	
		c[r] += c[s];
		mn += (long long)w0 * c[s] * (n - c[s]);
	}	
}

int main() {
	int n;

	scanf("%d", &n);
	for (int i=0; i+1<n; ++i) {
		scanf("%d%d%d", a+i, b+i, w+i), --a[i], --b[i];
		T[a[i]].push_back(make_pair(b[i], w[i]));
		T[b[i]].push_back(make_pair(a[i], w[i]));
	}
	for (int i=0; i+1<n; ++i) {
		int x = find_gp(a[i], b[i]), y = find_gp(b[i], a[i]);
		memset(c, 0, sizeof(c));
		::n = n, mn = 0;
		gao(0, -1, a[i], b[i], x, y, w[i]);
		cc = min(mn, cc);
//		printf("%d %d %lld\n", x, y, mn);
	}
	printf("%I64d\n", cc);

	return 0;
}

// 3696117	 May 9, 2013 4:26:13 PM	delta_4d	 E - Shaass the Great	 GNU C++	Accepted	2812 ms	660 KB
