#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

const int N = 100000 + 86;

struct BIT {
	int x[N+10], a[N+10], n;

	void init(int _n=N) {
		n = _n;
		fill(x, x+n, 0);
		fill(a, a+n, 0);
	}

	void add(int p, int k) {
		a[p] += k;
		for (int i=p; i<n; i+=i&-i) x[i] += k;
	}

	int sum(int p) {
		int ret = 0;
		for (int i=p; i>0; i-=i&-i) ret += x[i];
		return ret;
	}
} T;

template <class T> inline T fastin() {
	register char c = 0;
	register T a = 0;
	while (c < '0' || c > '9') c = getchar();
	while ('0' <= c && c <= '9') a = a * 10 + c - '0', c = getchar();
	return a;
}

int main() {
	int tc, cn = 0, n, q, v, op, p;
	for (tc=fastin<int>(); tc--; ) {
		n = fastin<int>(), q = fastin<int>();
		T.init(n+5);
		for (int i=0; i<n; ++i) T.add(i+1, fastin<int>()); 
		printf("Case %d:\n", ++cn);
		while (q--) {
			op = fastin<int>(), p = fastin<int>() + 1;
			if (op == 1) printf("%d\n", T.a[p]), T.add(p, -T.a[p]);
			else if (op == 2) T.add(p, fastin<int>());
			else printf("%d\n", T.sum(fastin<int>()+1)-T.sum(p-1));
		}
	}
	return 0;
}

// 259306	2013-09-03 21:39:10	 1112 - Curious Robin Hood	 C++	 0.168	 1868	Accepted
