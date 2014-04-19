#include <cstdio>
#include <cstring>
using namespace std;

typedef long long ll;
const int N = 520;
const ll M = 1000000007;

bool v[N*10];
ll p[N], f[N][N], e[N][N], c;

void init() {
	for (ll i=2; c<N; ++i) if (!v[i]) {
		p[c] = i, e[c][0] = 1;
		for (ll j=1; j<N; ++j) e[c][j] = e[c][j-1] * p[c] % M; ++c;
		for (ll j=i*i; j<N*10; j+=i) v[j] = true;
	}
	for (int i=1; i<N; ++i) {
		f[1][i] = (e[0][i] - e[0][i-1]) % M;
		if (f[1][i] < 0) f[1][i] += M;
	}
	for (int i=2; i<N; ++i) for (int j=i; j<N; ++j) {
		for (int k=1; k<j; ++k) {
			if (j - k < i - 1) break;
			ll cc = (e[i-1][k] - e[i-1][k-1]) * f[i-1][j-k] % M;
			if (cc < 0) cc += M;
			f[i][j] = (f[i][j] + cc) % M;
		}
	}
}

int main() {
	init();
	ll tc, cn = 0, P, K;
	for (scanf("%lld", &tc); tc--; ) {
		scanf("%lld%lld", &K, &P);
		printf("Case %lld: %lld\n", ++cn, f[P][K]);
	}
	return 0;
}

// 251552	2013-08-14 17:53:04	 1298 - One Theorem, One Year	 C++	 0.256	 5320	Accepted
