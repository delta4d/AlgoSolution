#include <cstdio>
#include <algorithm>
using namespace std;

struct node {
	int x, d;
	void init(int _x) {
		x = _x, d = 1;
		for (int i=2; i*i<=_x; ++i) if (_x % i == 0) {
			int t = 0;
			for (; _x%i==0; _x/=i,++t);
			d *= t + 1;
		}
		if (_x != 1) d <<= 1;
	}
	bool operator<(const node &a) const {
		if (d != a.d) return d < a.d;
		return x > a.x;
	}
} f[1024];

int main() {
	for (int i=1; i<1024; ++i) f[i].init(i);
	sort(f+1, f+1001);
	int tc, cn = 0, n;
	for (scanf("%d", &tc); tc--; ) {
		scanf("%d", &n);
		printf("Case %d: %d\n", ++cn, f[n].x);
	}
	return 0;
}

// 249500	2013-08-09 10:19:10	 1109 - False Ordering	 C++	 0.000	 1096	Accepted
