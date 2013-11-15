#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

const int MAXN = 100001;

int f[MAXN];
bool p[MAXN];

void init() {
	int i, j, k;
	
	memset(p, true, sizeof(p));
	for (i=2; i<MAXN; ++i) {
		if (p[i]) {
			++f[i];
			int ii = i * i;
			for (j=i<<1; j<MAXN; j+=i) {
				p[j] = false;
				if (j % ii == 0) f[j] = -1;
				else if (f[j] != -1) ++f[j];
			}
		}
	}
}

long long relative_prime(long long m, long long n) {
	int i, j, k;
	long long tot;
	
	if (m > n) swap(m, n);
	for (tot=0,i=1; i<=m; ++i) if (f[i] != -1) {
		if (f[i] & 1) tot -= (m / i) * (n / i) - (m / i) * (m / i - 1LL) / 2;
		else tot += (m / i) * (n / i) - (m / i) * (m / i - 1LL) / 2;
	}
	return tot;
}

int main() {
	int i, j, k;
	int a, b, c, d;
	int tc, cn(0);
	long long m, n;
	long long tot;
	
	init();
	//freopen("in.txt", "r", stdin);
	scanf("%d", &tc);
	while (tc--) {
		scanf("%d %d %d %d %d", &a, &b, &c, &d, &k);
		printf("Case %d: ", ++cn);
		if (k == 0) puts("0");
	 	else printf("%I64d\n", relative_prime(b/k, d/k));
	}
	
	return 0;
}