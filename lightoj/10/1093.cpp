#include <cstdio>
#include <algorithm>
using namespace std;

const int N = 100000 + 86;

int mx[N], mn[N];
int tagmx[N], tagmn[N];

template <class T> inline T fastin() {
	register char c = 0;
	register T a = 0;
	while (c < '0' || c > '9') c = getchar();
	while ('0' <= c && c <= '9') a = a * 10 + c - '0', c = getchar();
	return a;
}

int main() {
	int tc, cn = 0, n, d;
	for (tc=fastin<int>(); tc--; ) {
		n = fastin<int>(), d = fastin<int>();
		int hmx = 0, tmx = 0, hmn = 0, tmn = 0;
		int cmx = 0;
		for (int tag=0; tag<n; ++tag) {
			int cc = fastin<int>();
			for (; tmx>hmx&&mx[tmx-1]<=cc; --tmx);
			mx[tmx] = cc, tagmx[tmx++] = tag;
			for (; tagmx[hmx]+d<=tag; ++hmx);
			for (; tmn>hmn&&mn[tmn-1]>=cc; --tmn);
			mn[tmn] = cc, tagmn[tmn++] = tag;
			for (; tagmn[hmn]+d<=tag; ++hmn);
			cmx = max(cmx, mx[hmx]-mn[hmn]);
		}
		printf("Case %d: %d\n", ++cn, cmx);
	}
	return 0;
}

// 293525	2013-11-30 22:07:07	 1093 - Ghajini	 C++	 0.100	 2652	Accepted
