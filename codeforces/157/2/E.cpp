#include <cstdio>
#include <algorithm>
using namespace std;

typedef long long LL;
const int MAXN = 100000 + 86;
const int MOD = 1000000007;

int x[MAXN];
int p[MAXN], np;

int pow(int x, int e) {
	if (e <= 0) return 1;
	int r = 1;
	for (; e; e>>=1,x=(LL)x*x%MOD) if (e & 1) r = (LL)r * x % MOD;
	return r;
}

int main() {
	int n, mx = 0;
	int tot = 0;

	scanf("%d", &n);
	for (int i=0; i<n; ++i) scanf("%d", x+i), mx = max(mx, x[i]);
	sort(x, x+n);
	for (; mx>0; --mx) {
		np = 0;
		for (int i=1; i*i<=mx; ++i) if (mx % i == 0) {
			p[np++] = i;
			if (i * i != mx) p[np++] = mx / i;
		}
		sort(p, p+np);
		p[np] = MAXN;
		int c1 = lower_bound(x, x+n, p[0]) - x, cc = 1;
		for (int i=0; i<np; ++i) {
			int c2 = lower_bound(x, x+n, p[i+1]) - x;
			if (i == np - 1) cc = (LL)cc * (pow(i+1, c2-c1) - pow(i, c2-c1)) % MOD;
			else cc = (LL)cc * pow(i+1, c2-c1) % MOD;
			c1 = c2;
		}
		tot = (tot + cc) % MOD;
	}
	printf("%d\n", tot<0?tot+MOD:tot);

	return 0;
}

// 3767772	 May 25, 2013 7:36:24 AM	delta_4d	 C - Little Elephant and LCM	 GNU C++	Accepted	656 ms	760 KB
