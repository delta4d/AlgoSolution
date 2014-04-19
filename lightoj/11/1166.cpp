#include <cstdio>
using namespace std;

int x[111];

int main() {
	int tc, cn = 0, n;
	for (scanf("%d", &tc); tc--; ) {
		scanf("%d", &n);
		for (int i=1; i<=n; ++i) scanf("%d", x+i);
		int tot = 0;
		for (int i=1; i<=n; ++i) if (x[i]) {
			int c = 0;
			for (int j=i,t; x[j]; t=x[j],x[j]=0,j=t,++c);
			tot += c - 1;
		}
		printf("Case %d: %d\n", ++cn, tot);
	}
	return 0;
}

// 263807	2013-09-18 21:04:02	 1166 - Old Sorting	 C++	 0.004	 1088	Accepted
