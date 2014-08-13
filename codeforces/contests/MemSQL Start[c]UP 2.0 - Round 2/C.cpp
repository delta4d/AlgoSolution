#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 10;

struct T {
	int h, v, k;
	T(int h=0, int v=0, int k=0):h(h), v(v), k(k) {}
};
bool by_h(const T &l, const T &r) { return l.h > r.h; }
bool by_v(const T &l, const T &r) { return l.v < r.v; }

struct BIT {
	const int BIAS = 5;
	int n;
	vector <int> x;
	BIT(int _n=N):n(_n), x(_n, 0) {}
	void add(int p, int o) {
		p += BIAS;
		for (int i=p; i<n; i+=i&-i) x[i] += o;
	}
	int sum(int p) {
		p += BIAS;
		int ret = 0;
		for (int i=p; i>0; i-=i&-i) ret += x[i];
		return ret;
	}
} T1, T2;
vector <int> f[N];
vector <T> x;

int gao(int m) {
	int L = 0, R = N - 10, M = -1;
	while (L <= R) {
		M = (L + R) >> 1;
		int c = T1.sum(M);
		if (c == m) return T2.sum(M);
		if (c < m) L = M + 1;
		else R = M - 1;
	}
	throw "";
}

int main() {
	int n;
	scanf("%d", &n);
	for (int i=0,a,b; i<n; ++i) {
		scanf("%d%d", &a, &b);
		f[a].push_back(b);
	}
	for (int i=1; i<N; ++i) {
		int sz = (int)f[i].size();
		if (sz == 0) continue;
		sort(begin(f[i]), end(f[i]));
		for (int j=0; j<sz; ++j) x.push_back(T(sz-j, f[i][j], -1));
	}
	int m = (int)x.size(), s = n - m;
	sort(begin(x), end(x), by_v);
	for (int i=0; i<m; ++i) x[i].k = i + 1, T1.add(i+1, 1),T2.add(i+1, x[i].v);
	sort(begin(x), end(x), by_h);
	int mn = INT_MAX;
	for (int h=n,k=0,rm=0,c=0; h>=0; --h) {
		for (; k<m; ++k) {
			if (x[k].h < h) break;
			rm += x[k].v;
			T1.add(x[k].k, -1);
			T2.add(x[k].k, -x[k].v);
			++c;
		}
		if (s + c <= h) {
			mn = min(mn, rm+gao(h-s-c));
		}
	}
	printf("%d\n", mn);
	return 0;
}

// 7426965	2014-08-11 16:24:47	delta_4d	C - Elections	GNU C++0x	Accepted	124 ms	5736 KB
