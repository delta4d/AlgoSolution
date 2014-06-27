#include <bits/stdc++.h>
using namespace std;

int const L = 1 << 10;
int const N = 1 << 7;

int lp[L];
int f[N][N], m, n;
vector <int> p;

char buf[N];
struct BigInt {
	int d[N], n;

	BigInt(int n=1):n(n) {
		d[0] = 1;
	}

	void writeout() {
		for (int i=0; i<n; ++i) printf("%d", d[n-1-i]);
		puts("");
	}

	void mul2() {
		for (int i=0; i<n; ++i) d[i] <<= 1;
		for (int i=0; i<n; ++i) d[i+1] += d[i] / 10, d[i] %= 10;
		if (d[n]) ++n;
	}

	void minus(int y) {
		d[0] -= y;
		for (int i=0; i<n; ++i) {
			if (d[i] < 0) d[i] += 10, --d[i+1];
		}
		if (!d[n-1]) --n;
		if (!n) ++n;
	}
} x;

void init() {
	for (int i=2; i<L; ++i) {
		if (!lp[i]) lp[i] = i, p.push_back(i);
		for (auto pr: p) {
			if (pr > lp[i] || pr * i >= L) break;
			lp[pr*i] = pr;
		}
	}
}

int main() {
#ifdef ONLINE_JUDGE
	freopen("rsa.in", "r", stdin);
	freopen("rsa.out", "w", stdout);
#endif
	init();
	scanf("%d%d", &m, &n);
	for (int i=0,x; i<n; ++i) {
		scanf("%d", &x);
		for (int j=0; j<m; ++j) if (x % p[j] == 0) {
			int c = 1;
			for (x/=p[j]; x%p[j]==0; x/=p[j],c^=1);
			f[j][i] = c;
		}
	}
	int r = 0, c = 0;
	for (int i,j,k; r<m&&c<n; ++c) {
		for (i=r; i<m&&!f[i][c]; ++i);
		if (i == m) continue;
		for (j=c; j<n; ++j) swap(f[i][j], f[r][j]);
		for (j=r+1; j<m; ++j) if (f[j][c]) {
			for (k=c; k<n; ++k) f[j][k] ^= f[r][k];
		}
		++r;
	}
	int free_v = n - r;
	for (int i=0; i<free_v; ++i) x.mul2();
	x.minus(1);
	x.writeout();
	return 0;
}

// 6966920	 2014-06-27 08:20:54	delta_4d	 H - Cracking' RSA	 GNU C++0x	Accepted	62 ms	240 KB
