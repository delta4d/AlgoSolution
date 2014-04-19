#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

const int MAXN = 100000 + 86;

int L[MAXN], f[MAXN];
int q[MAXN], h, t;

template <class T> inline T fastin() {
	register char c = 0;
	register T a = 0;
	while (c < '0' || c > '9') c = getchar();
	while ('0' <= c && c <= '9') a = a * 10 + c - '0', c = getchar();
	return a;
}

int gao(int N, int K) {
	if (N <= 2) return -1;
	K <<= 1;
	sort(L+1, L+N);
	memset(f, -1, sizeof(f));
	q[0] = 0, f[0] = 0, L[0] = -K;
	h = 0, t = 1;
	for (int k=1; k<=N; ++k) {
		for (; t>h&&q[h]+1<k&&L[k]-L[q[h]+1]>K; ++h);
		if (t <= h) --h;
		if (t > h && k - q[h] >= 3 && q[h] + 1 < k && L[k] - L[q[h]+1] <= K) {
			f[k] = f[q[h]] + 1;
			q[t++] = k;
		}
	}
	return f[N];
}

int main() {
	int tc, cn = 0, N, K;
	for (tc=fastin<int>(); tc--; ) {
		N = fastin<int>(), K = fastin<int>();
		for (int i=1; i<=N; ++i) L[i] = fastin<int>();
		printf("Case %d: %d\n", ++cn, gao(N, K));
	}
	return 0;
}

// 296243	2013-12-06 21:48:33	 1084 - Winter	 C++	 0.184	 2260	Accepted
