#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

const int N = 100000 + 86;

char s[N];

struct BIT {
	int x[N+10], n;

	void init(int _n=N) {
		fill(x, x+_n, 0);
		n = _n;
	}
	void add(int p, int off) {
		for (int i=p; i<n; i+=i&-i) x[i] ^= off;
	}
	int sum(int p) {
		int ret = 0;
		for (int i=p; i>0; i-=i&-i) ret ^= x[i];
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
	char op[2];
	int tc, cn = 0, q, l, a, b;
	for (tc=fastin<int>(); tc--; ) {
		scanf("%s", s), l = strlen(s);
		T.init(l+5);
		for (int i=0; i<l; ++i) if (s[i] == '1') {
			T.add(i+1, 1);
			T.add(i+2, 1);
		}
		q = fastin<int>();
		printf("Case %d:\n", ++cn);
		while (q--) {
			scanf("%s", op);
			a = fastin<int>();
			if (op[0] == 'I') {
				b = fastin<int>();
				T.add(a, 1);
				T.add(b+1, 1);
			} else {
				printf("%d\n", T.sum(a));
			}
		}
	}
	return 0;
}

// 259203	2013-09-03 18:27:14	 1080 - Binary Simulation	 C++	 0.196	 1576	Accepted
