#include <cstdio>
using namespace std;

typedef long long ll;
const ll MOD = 1000000007;

int a[30], b[30]={-1,-1};
ll f[1<<24], d[1<<24];

void add(ll &x, ll y) {
	x += y;
	if (x >= MOD) x -= MOD;
}

int main() {
	int n, m, K;
	scanf("%d", &n);
	for (int i=0; i<n; ++i) scanf("%d", a+i);
	scanf("%d", &K);
	for (int i=0; i<K; ++i) scanf("%d", b+i);
	m = 1 << n;
	for (int i=0; i<m; ++i) {
		int j = __builtin_ctz(i);
		d[i] = d[i^(1<<j)] + a[j];
	}
	f[0] = 1;
	for (int i=1; i<m; ++i) if (d[i] != b[0] && d[i] != b[1]) {
		for (int j=i; j; j&=(j-1)) add(f[i], f[i^(j&-j)]);
	}
	printf("%I64d\n", f[(1<<n)-1]);

	return 0;
}

// 4021289	 Jul 4, 2013 7:22:02 PM	delta_4d	 E - Axis Walking	 GNU C++	Accepted	 2093 ms	 262600 KB
