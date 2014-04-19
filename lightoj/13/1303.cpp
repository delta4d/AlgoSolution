#include <list>
#include <cstdio>
#include <algorithm>
using namespace std;

const int N = 21;
int f[N][N];

inline int next(int k, int m) { return k == m - 1 ? 0 : k + 1; }

void init() {
	for (int n=1; n<N; ++n) for (int m=2; m<N; ++m) {
		list <int> q;
		int v[N], tot = 0, rem = 2 * m * n;
		bool mark[N][N] = {false};
		fill(v, v+N, -1);
		for (int i=0; i<n; ++i) q.push_back(i);
		for (int i=0; ; i=next(i, m)) {
			if (v[i] != -1) {
//				printf("%d out of %d\n", v[i], i);
				q.push_back(v[i]);
				v[i] = -1;
				--rem;
			}
			for (list<int>::iterator it=q.begin(); it!=q.end(); ++it) {
				int c = *it;
				if (!mark[c][i]) {
//					printf("%d get in %d\n", c, i);
					mark[c][i] = true, --rem;
					q.erase(it);
					v[i] = c;
					break;
				}
			}
			++tot;
			if (rem == 0) break;
		}
		f[n][m] = tot * 5;
//		printf("%d %d %d\n", n, m, tot);
	}
}

int main() {
	init();
	int tc, cn = 0, m, n;
	for (scanf("%d", &tc); tc--; ) {
		scanf("%d%d", &n, &m);
		printf("Case %d: %d\n", ++cn, f[n][m]);
	}
	return 0;
}

// 258811	2013-09-02 18:50:20	 1303 - Ferris Wheel	 C++	 0.004	 1208	Accepted
