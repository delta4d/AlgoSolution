#include <cstdio>
#include <cstring>
using namespace std;

const int MAXN = 10000 + 86;

bool v[MAXN];
int p[MAXN], c;
int cc[MAXN], r[MAXN];

struct bignum {
	int a[MAXN * 10], n;

	void init() {
		memset(a, 0, sizeof(a));
		a[0] = 1, n = 1;
	}

	void mul(int x) {
		for (int i=0; i<n; ++i) a[i] *= x;
		for (int i=0; i<n; ++i) {
			a[i+1] += a[i] / 10;
			a[i] %= 10;
		}
		for (; a[n]; ++n) a[n+1] += a[n] / 10, a[n] %= 10;
	}

	void to_s() {
		for (int i=n-1; i>=0; --i) printf("%d", a[i]);
	}
} tot;

void init() {
	for (int i=2; i<MAXN; ++i) if (!v[i]) {
		p[c++] = i, r[i] = c - 1;
		for (int j=i*i; j<MAXN; j+=i) v[j] = true;
	}
}

int main() {
	init();
	int tc, cn = 0, n, x;
	for (scanf("%d", &tc); tc--; ) {
		memset(cc, 0, sizeof(cc));
		scanf("%d", &n);
		for (int i=0; i<n; ++i) {
			scanf("%d", &x);
			for (int k=0; p[k]*p[k]<=x; ++k) if (x % p[k] == 0) {
				int t = 0;
				for (; x%p[k]==0; x/=p[k],++t);
				if (cc[k] < t) cc[k] = t;
			}
			if (x != 1 && cc[r[x]] < 1) cc[r[x]] = 1;
		}
		tot.init();
		for (int i=0; i<c; ++i) for (int j=0; j<cc[i]; ++j) tot.mul(p[i]);
		printf("Case %d: ", ++cn);
		tot.to_s();
		puts("");
	}
	return 0;
}

// 249786	2013-08-09 20:58:03	 1024 - Eid	 C++	 0.204	 1608	Accepted
