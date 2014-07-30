#include <bits/stdc++.h>
using namespace std;

using ull = unsigned long long;
int const N = 3e5 + 10;
int const SEED = 17;

struct BIT {
	int n;
	vector <ull> x;
	BIT(int n=N):n(n), x(n, 0) {}
	void add(int p, ull o) {
		for (int i=p; i<n; i+=i&-i) x[i] += o;
	}
	ull sum(int p) {
		ull ret = 0;
		for (int i=p; i>0; i-=i&-i) ret += x[i];
		return ret;
	}
	ull sum(int l, int r) {
		if (l > r) return 0;
		return sum(r) - sum(l-1);
	}
} T1, T2;
ull p[N]={1};

int main() {
	int n;
	scanf("%d", &n);
	for (int i=1; i<N; ++i) p[i] = p[i-1] * SEED;
	for (int i=0,x; i<n; ++i) {
		scanf("%d", &x);
		int d = min(x-1, n-x);
		ull low = T1.sum(x-d, x-1) * p[n-x+1], high = T2.sum(x+1, x+d) * p[x];
		if (low != high) return puts("YES"), 0;
		T1.add(x, p[x-1]), T2.add(x, p[n-x]);
	}
	puts("NO");
	return 0;
}

// 7289272	2014-07-30 07:43:27	delta_4d	F - Permutation	GNU C++0x	Accepted	186 ms	7000 KB
