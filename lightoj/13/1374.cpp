#include <cstdio>
#include <cstring>
using namespace std;

int c[10000 + 86];

int main() {
	int tc, cn = 0, n;
	for (scanf("%d", &tc); tc--; ) {
		scanf("%d", &n);
		memset(c, 0, sizeof(c));
		for (int i=0,x; i<n; ++i) {
			scanf("%d", &x);
			++c[x], ++c[n-1-x];
		}
		bool ok = true;
		for (int i=0; ok&&i<n; ++i) ok &= c[i] == 2;
		printf("Case %d: %s\n", ++cn, ok?"yes":"no");
	}
	return 0;
}

// 276344	2013-10-21 14:23:48	 1374 - Confusion in the Problemset	 C++	 0.112	 1128	Accepted
