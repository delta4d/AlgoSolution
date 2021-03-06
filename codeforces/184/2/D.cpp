#include <cstdio>
#include <algorithm>
using namespace std;

const int MOD = 1000000007;

int pow(int x, int e) {
	int r = 1;
	for (; e; e>>=1,x=(long long)x*x%MOD) if (e&1) r = (long long)r * x % MOD;
	return r;
}

int main() {
	int n, m, k;
	int sz=0;
	int a1=-1, b1=-1, a2=-1, b2=-1;

	scanf("%d%d%d", &n, &m, &k);
	for (int i=0,a,b; i<m; ++i) {
		scanf("%d%d", &a, &b), --a, --b;
		if (b - a != k + 1 && b - a != 1) return puts("0"), 0;
		if (b - a == k + 1 && a1 != -1 && a - a1 > k) return puts("0"), 0;
		if (b - a == k + 1 && a1 == -1) a1 = a, b1 = b;
		if (b - a == k + 1) ++sz, a2 = a, b2 = b;
	}
	int cc = 0;
	if (!sz) a1 = n - k - 1, a2 = k;
	for (int i=max(0,a2-k); i<a1; ++i) {
		int p = min(k, n-k-2-i) - sz;
		cc = (cc + pow(2, p)) % MOD;
//		printf("%d: %d\n", i, cc);
	}
	int p = min(k, n-k-2-a1) - sz;
	if (b1 != -1) ++p;
	if (p >= 0) cc = (cc + pow(2, p)) % MOD;
	if (b1 == -1) cc = (cc + 1) % MOD;
	printf("%d\n", cc);

	return 0;
}

// 3748052	 May 20, 2013 8:26:48 AM	delta_4d	 D - Olya and Graph	 GNU C++	Accepted	453 ms	0 KB
