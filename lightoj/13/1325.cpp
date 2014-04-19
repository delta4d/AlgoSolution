#include <map>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

typedef long long ll;
const int M = 100000007;
const int N = sqrt(1.0*M);

map <int, int> mp;

int e(int x, int e) {
	int r = 1;
	for (x%=M; e; e>>=1,x=(ll)x*x%M) if (e & 1) r = (ll)r * x % M;
	return r;
}

int gao(int K, int R) {
	mp.clear();
	int x = 1;
	for (int i=1; i<=N; ++i) {
		x = (ll)x * K % M;
		if (!mp.count(x)) mp[x] = i;
	}
	mp[1] = 0;
	int f = e(K, M-N-1), cc = 1;
	for (int i=0; i<N; ++i) {
		int r = (ll)cc * R % M;
		if (mp.count(r)) return i * N + mp[r];
		cc = (ll)f * cc % M; 
	}
	return -1;
}

int main() {
	int tc, cn = 0, K, R;
	for (scanf("%d", &tc); tc--; ) {
		scanf("%d%d", &K, &R);
		printf("Case %d: %d\n", ++cn, gao(K, R));
	}
	return 0;
}

// 305234	2013-12-28 12:03:32	 1325 - Distributing Chocolates	 C++	 0.492	 1612	Accepted
