#include <cstdio>
#include <algorithm>
using namespace std;

const int MAXN = 10000000 + 86;

bool v[MAXN];
int p[MAXN/10], c;

void init() {
	v[0] = v[1] = true;
	for (int i=2; i<MAXN; ++i) if (!v[i]) {
		p[c++] = i;
		for (long long j=(long long)i*i; j<MAXN; j+=i) v[j] = true;
	}
//	printf("%d\n", c);
}

int main() {
	init();
	int tc, n;
	scanf("%d", &tc);
	for (int cn=1; cn<=tc; ++cn) {
		scanf("%d", &n);
		int tot = 0;
		for (int i=0; p[i]+p[i]<=n; ++i) if (!v[n-p[i]]) ++tot;
		printf("Case %d: %d\n", cn, tot);
	}
	return 0;
}

// 249390	2013-08-08 22:43:09	 1259 - Goldbach`s Conjecture	 C++	 0.452	 14760	Accepted
