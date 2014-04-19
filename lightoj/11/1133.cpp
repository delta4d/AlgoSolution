#include <cstdio>
#include <algorithm>
using namespace std;

typedef long long ll;

ll p[333], c;
char op[10];

int main() {
	int tc, cn = 0, n, m;
	for (scanf("%d", &tc); tc--; ) {
		scanf("%d%d", &n, &m);
		for (int i=0; i<n; ++i) scanf("%lld", p+i);
		ll x, y, z, M = 1, D = 1, r = 0;
		while (m--) {
			scanf("%s", op);
			if (op[0] == 'S') {
				scanf("%lld", &x);
				for (int i=0; i<n; ++i) p[i] += x;
			} else if (op[0] == 'M') {
				scanf("%lld", &x); 
				for (int i=0; i<n; ++i) p[i] *= x;
			} else if (op[0] == 'D') {
				scanf("%lld", &x);
				for (int i=0; i<n; ++i) p[i] /= x;
			} else if (op[0] == 'R') {
				for (int i=0; i*2<n; ++i) swap(p[i], p[n-1-i]);	
			} else {
				scanf("%lld%lld", &y, &z);
				swap(p[y], p[z]);
			}
		}
		printf("Case %d:\n", ++cn);
		for (int i=0; i<n; ++i) printf("%lld%s", p[i], i==n-1?"\n":" ");
	}
	return 0;
}

// 252274	2013-08-16 19:44:16	 1133 - Array Simulation	 C++	 0.004	 1088	Accepted
