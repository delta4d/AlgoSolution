#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

const int N = 1500000;

int x[N];
struct BIT {
	int x[N+10], v[N+10], n;

	BIT(int _n=N+5) {
		n = _n;
		memset(x, 0, n*sizeof(int));
		memset(v, 0, n*sizeof(int));
	}

	void add(int p, int off) {
		v[p] += off;
		for (int i=p; i<=n; i+=i&-i) x[i] += off;
	}

	int sum(int p) {
		int tot = 0;
		for (int i=p; i>0; i-=i&-i) tot += x[i];
		return tot;
	}
} T;

int g(int n) {
	int left = 1, right = N, mid, pos = -1;
	while (left <= right) {
		mid = (left + right) >> 1;
		int cc = T.sum(mid);
		if (cc < n) left = mid + 1;
		else right = mid - 1, pos = mid;
	}
	return pos;
}

void init() {
	for (int i=1; i<N; ++i,++i) T.add(i, 1);
	for (int k=2; k<N; ++k) {
		int off = g(k), p = 0;
		if (off == -1) break;
		for (int i=off; i<N; i+=off) {
			int pos = g(i);
			if (pos != -1) x[p++] = pos;
		}
		for (int i=0; i<p; ++i) T.add(x[i], -1);
	}
	int p = 0;
	for (int i=0; i<T.n; ++i) if (T.v[i]) x[++p] = i;
}

int main() {
	init();
	int tc, cn = 0, n;
	for (scanf("%d", &tc); tc--; ) {
		scanf("%d", &n);
		printf("Case %d: %d\n", ++cn, x[n]);
	}
	return 0;
}

// 302684	2013-12-22 22:03:43	 1097 - Lucky Number	 C++	 1.448	 18664	Accepted
