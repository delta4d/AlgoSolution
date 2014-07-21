#include <bits/stdc++.h>
using namespace std;

using ll = long long;
ll const N = 1e6 + 10;
ll const M = 1e9 + 7;

ll F[N], phi[N], p[N], pp;
ll f0[N], f1[N], f2[N];

void init() {
	for (ll i=2; i<N; ++i) {
		if (!phi[i]) p[pp++] = i, phi[i] = i - 1;
		for (ll j=0; j<pp&&p[j]*i<N; ++j) {
			if (i % p[j] == 0) phi[i*p[j]] = phi[i] * p[j];
			else phi[i*p[j]] = phi[i] * (p[j] - 1);
			if (i % p[j] == 0) break;
		}
	}
	for (ll i=1; i<N; ++i) for (ll j=1; i*j<N; ++j) {
		F[i*j] = (F[i*j] + i * phi[j]) % M;
	}
	for (ll i=1; i<N; ++i) {
		F[i] = (F[i] << 1) % M;
		ll off = ((i - 1) * i * (2 * i - 1) / 3) % M;
		off = (off - i * (i - 2)) % M;
		F[i] = (F[i] + off) % M;
		if (F[i] < 0) F[i] += M;
	}
	for (ll i=1; i<N; ++i) {
		f0[i] = (f0[i-1] + F[i]) % M;
		f1[i] = (f1[i-1] + F[i] * i) % M;
		f2[i] = (f2[i-1] + F[i] * (i * i % M)) % M;
	}
}

int main() {
	ios_base :: sync_with_stdio(false);
	init();
	ll tc, m, n;
	for (cin>>tc; tc--; ) {
		cin >> m >> n;
		ll mn = min(m, n);
		++m, ++n;
		ll tot = ((m * n % M) * f0[mn] - (m + n) * f1[mn] + f2[mn]) % M;
		if (tot < 0) tot += M;
		cout << tot << endl;
	}
	return 0;
}

// 7191964	2014-07-21 11:40:11	delta_4d	E - Jzzhu and Squares	GNU C++0x	Accepted	670 ms	47000 KB
