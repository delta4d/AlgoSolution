#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

const int MAXN = 1111;

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

int relative_prime(int m, int n) {
	int i, j, k;
	int tot;
	
	if (m > n) swap(m, n);
	for (tot=0,i=1; i<=m; ++i) if (f[i] != -1) {
		if (f[i] & 1) tot -= (m / i) * (n / i);
		else tot += (m / i) * (n / i);
	}
	return tot;
}

int main() {
	int i, j, k;
	int m, n;
	int tc, cn(0);
	
	init();
	scanf("%d", &tc);
	while (tc--) {
		scanf("%d", &n);
		printf("%d %d %d\n", ++cn, n, relative_prime(n, n)+2);
	}
	return 0;
}