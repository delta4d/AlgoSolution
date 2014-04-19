#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

const int N = 200000;

struct BIT {
	int n;
	int v[N+10], c[N+10];

	void init(int _n=N) {
		n = _n;
		memset(c, 0, sizeof(c));
	}

	void add(int p, int val, int off) {
		v[p] = val;
		for (int i=p; i<n; i+=i&-i) c[i] += off;
	}

	int sum(int p) {
		int tot = 0;
		for (int i=p; i>0; i-=i&-i) tot += c[i];
		return tot;
	}
} T;

int main() {
	int tc, cn = 0, n, q;
	char op[2];
	for (scanf("%d", &tc); tc--; ) {
		scanf("%d%d", &n, &q);
		T.init(n+q+10);
		for (int i=0,cc; i<n; ++i) {
			scanf("%d", &cc);
			T.add(i+1, cc, 1);
		}
		printf("Case %d:\n", ++cn);
		for (int i=0,cc; i<q; ++i) {
			scanf("%s%d", op, &cc);
			if (op[0] == 'a') {
				T.add(i+n+1, cc, 1);
			} else {
				int left = 1, right = T.n, mid, k = -1;
				while (left <= right) {
					mid = (left + right) >> 1;
					int sum = T.sum(mid);
					if (sum < cc) left = mid + 1;
					else if (sum >= cc) right = mid - 1, k = mid;
				}
				if (k != -1 && T.sum(k) == cc && T.v[k] != -1) {
					printf("%d\n", T.v[k]);
					T.add(k, -1, -1);
				} else {
					puts("none");
				}
			}
		}
	}
	return 0;
}

// 302229	2013-12-21 21:17:17	 1087 - Diablo	 C++	 0.388	 2648	Accepted
