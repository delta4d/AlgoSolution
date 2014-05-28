#include <cstdio>
#include <algorithm>
using namespace std;

using ll = long long;
int const N = 1e7 + 10;
int const P = 700000;
bool isp[N];
int p[P], v[N], t;
ll cnt[P];

void init() {
	p[t++] = 0;
	for (int i=2; i<N; ++i) if (!isp[i]) {
		p[t] = i;
		for (int j=i; j<N; j+=i) isp[j] = true, cnt[t] += v[j];
		cnt[t] += cnt[t-1], ++t;
	}
}

int main() {
	int n, m;
	scanf("%d", &n);
	for (int i=0,x; i<n; ++i) scanf("%d", &x), ++v[x];
	init();
	scanf("%d", &m);
	for (int a,b; m--; ) {
		scanf("%d%d", &a, &b);
		int l = lower_bound(p, p+t, a) - p, r = upper_bound(p, p+t, b) - p - 1;
		printf("%I64d\n", cnt[r]-cnt[l-1]);
	}
	return 0;
}

// 6578755	 May 9, 2014 8:23:13 PM	delta_4d	 C - Bear and Prime Numbers	 GNU C++0x	Accepted	 608 ms	 57100 KB
