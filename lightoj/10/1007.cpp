#include <cstdio>
using namespace std;

typedef unsigned long long ll;
const int MAXN = 5000000 + 86;

bool v[MAXN];
ll phi[MAXN];

void init() {
	for (int i=0; i<MAXN; ++i) phi[i] = i;
	for (int i=2; i<MAXN; ++i) if (!v[i]) {
		--phi[i];
		for (int j=i<<1; j<MAXN; j+=i) {
			v[j] = true;
			phi[j] -= phi[j] / i;
		}
	}
	for (int i=1; i<MAXN; ++i) phi[i] = phi[i] * phi[i] + phi[i-1];
}

int main() {
	init();
	int tc;
	ll a, b;
	scanf("%d", &tc);
	for (int cn=0; cn<tc; ++cn) {
		scanf("%llu%llu", &a, &b);
		printf("Case %d: %llu\n", cn + 1, phi[b]-phi[a-1]);
	}
	return 0;
}

// 249385	2013-08-08 22:35:42	 1007 - Mathematically Hard	 C++	 0.864	 45032	Accepted
