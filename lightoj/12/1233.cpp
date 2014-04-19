/**
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

const int N = 100000 + 86;

bool f[N];
int A[101], C[101];
int a[1001];

void to2(int &n) {
	int p = 0;
	for (int i=0; i<n; ++i) {
		int p2 = 1, s = 1;
		for (; s<=C[i]; p2<<=1,s+=p2) a[p++] = p2 * A[i];
		s -= p2, p2 = C[i] - s;
		if (p2) a[p++] = p2 * A[i];
	}
	n = p;
}

int main() {
	int tc, cn = 0, n, m;
	for (scanf("%d", &tc); tc--; ) {
		scanf("%d%d", &n, &m);
		for (int i=0; i<n; ++i) scanf("%d", A+i);
		for (int i=0; i<n; ++i) scanf("%d", C+i);
		to2(n);
		memset(f, false, sizeof(f));
		f[0] = true;
		for (int i=0; i<n; ++i) for (int j=m-a[i]; j>=0; --j) f[j+a[i]] |= f[j];
		int tot = 0;
		for (int i=1; i<=m; ++i) tot += f[i];
		printf("Case %d: %d\n", ++cn, tot);
	} 
	return 0;
}

// 293184	2013-11-30 13:35:41	 1233 - Coin Change (III)	 C++	 0.780	 1188	Accepted
**/

#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

bool f[100000 + 86];
int a[101], c[101], g[100000 + 86];

template <class T> inline T fastin() {
	register char c = 0;
	register T a = 0;
	while (c < '0' || c > '9') c = getchar();
	while ('0' <= c && c <= '9') a = a * 10 + c - '0', c = getchar();
	return a;
}

int main() {
	int tc, cn = 0, n, m, tot;
	for (tc=fastin<int>(); tc--; ) {
		n = fastin<int>(), m = fastin<int>(), tot = 0;
		for (int i=0; i<n; ++i) a[i] = fastin<int>();
		for (int i=0; i<n; ++i) c[i] = fastin<int>();
		memset(f, false, sizeof(f)), f[0] = true;
		for (int i=0; i<n; ++i) {
			memset(g, 0, sizeof(g));
			for (int k=0; k+a[i]<=m; ++k) {
				if (f[k] && !f[k+a[i]] && g[k] < c[i]) {
					f[k+a[i]] = true;
					g[k+a[i]] = g[k] + 1;
					++tot;
				}
			}
		}
		printf("Case %d: %d\n", ++cn, tot);
	}
	return 0;
}

// 293189	2013-11-30 13:48:51	 1233 - Coin Change (III)	 C++	 0.156	 1576	Accepted
