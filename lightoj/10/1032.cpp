#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

const int N = 35;

long long f[N][2], c[N][2], p[N];
int s[N], x[N];

void init() {
	c[1][1] = 1;
	for (int i=2; i<N; ++i) {
		f[i][0] = f[i-1][0] + f[i-1][1];
		f[i][1] = f[i][0] + c[i-1][1];
		c[i][0] = c[i-1][0] + c[i-1][1];
		c[i][1] = c[i-1][0] + c[i-1][1];
		p[i] = f[i][0] + f[i][1] + p[i-1];
	}
//	printf("%lld\n", p[31]);
}

int to_s(int t) {
	int n;
	for (n=1; t; s[n++]=t%2,t>>=1);
	for (int i=1; i+i<n+1; ++i) swap(s[i], s[n-i]);
	x[1] = 0;
	for (int i=2; i<n; ++i) x[i] = x[i-1] + (s[i] == 1 && s[i-1] == 1);
	return n - 1;
}

int main() {
	init();
	int tc, cn = 0, t;
	for (scanf("%d", &tc); tc--; ) {
		scanf("%d", &t);
		int n = to_s(t);
		memset(f, 0, sizeof(f));
		memset(c, 0, sizeof(c));
		c[1][1] = 1;
		for (int i=2; i<=n; ++i) {
			f[i][0] = f[i-1][0] + f[i-1][1];
			f[i][1] = f[i][0] + c[i-1][1];
			if (s[i] == 0) f[i][1] -= x[i-1] + (s[i-1] == 1);
			c[i][0] = c[i-1][0] + c[i-1][1];
			c[i][1] = c[i][0];
			if (s[i] == 0) c[i][1] -= 1;
		}
//		for (int i=1; i<=n; ++i) printf("f: %lld %lld\n", f[i][0], f[i][1]);
//		for (int i=1; i<=n; ++i) printf("c: %lld %lld\n", c[i][0], c[i][1]);
		long long tot = f[n][0] + f[n][1] + p[n-1];
		printf("Case %d: %lld\n", ++cn, tot);
	}
	return 0;
}

// 291410	2013-11-25 21:08:23	 1032 - Fast Bit Calculations	 C++	 0.012	 1088	Accepted
