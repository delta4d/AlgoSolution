#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;

inline int lowbit(const int x) { return x & -x; }

struct BIT {
	vector <int> x;

	void init(int sz=0) {
		x.clear();
		x.resize(sz, 0);
	}
	void modify(int p, const int off) {
		for (; p<x.size(); p+=lowbit(p)) x[p] += off;
	}
	int sum(int p) {
		int tot = 0;
		for (; p>0; p-=lowbit(p)) tot += x[p];
		return tot;
	}
} T;

int main() {
	int n, k, a, b, tc;
	char op[16];

	while (1 == scanf("%d", &n)) {
		T.init(n+10);
		for (int i=1; i<=n; ++i) {
			scanf("%d", &k);
			T.modify(i, k);
		}	
		scanf("%d", &tc);
		while (tc--) {
			scanf("%s", op);
			if (op[0] == 'p') {
				scanf("%d%d", &a, &b);	
				T.modify(a, b-T.sum(a)+T.sum(a-1));
			} else {
				scanf("%d", &k);
				int left = 1, right = n, mid;
				while (left <= right) {
					mid = (left + right) >> 1;
					if (k <= T.sum(mid)) right = mid - 1;
					else left = mid + 1;
				}
				printf("%d\n", right + 1);
			}
		}
	}

	return 0;
}
