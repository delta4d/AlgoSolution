#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

const int MAXN = 21111;
bool prime[MAXN];

void gen_prime() {
	int i, j, k;
	memset(prime, true, sizeof(prime));
	for (i=2; i<MAXN; ++i) {
		if (prime[i]) {
			//prime[i] = true;
			for (j=i+i; j<MAXN; j+=i) prime[j] = false;
		}
	}
	prime[0] = prime[1] = false;
	//for (i=0; i<=100; ++i) if (prime[i]) printf("%d ", i); puts("");
}

inline int abs(const int x) {
	return x >= 0 ? x : -x;
}

inline int gcd(int a, int b) {
	int t;
	if (a < b) swap(a, b);
	while (b != 0) {
		t = a % b;
		a = b;
		b = t;
	}
	return a;
}

void gao(int &a, int &b) {
	int t(gcd(a, b));
	if (t == 0) return;
	a /= t, b /= t;
}

int main() {
	int i, j, k;
	int m, n;
	int tc;
	int xl, xr, yl, yr;
	int x, y;
	int cnt, tot;
	int a, b;

	gen_prime();
	scanf("%d", &tc);
	while (tc--) {
		scanf("%d %d %d %d", &xl, &xr, &yl, &yr);
		cnt = 0;
		for (a=xl; a<=xr; ++a) {
			for (b=yl; b<=yr; ++b) {
				x = abs(a), y = abs(b);
				k = x * x + y * y;
				if (x == 0) {
					cnt += prime[y] && y % 4 == 3;
	//				printf("%d %d\n", x, y);
				} else if (y == 0) {
					cnt += prime[x] && x % 4 == 3;
	//				printf("%d %d\n", x, y);
				} else {
					cnt += prime[k] && k % 4 != 3;
	//				printf("%d %d\n", x, y);
				}	
			}
		}
		tot = (xr - xl + 1) * (yr - yl + 1);
		gao(cnt, tot);
		printf("%d/%d\n", cnt, tot);
	}

	return 0;
}
