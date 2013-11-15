#include <queue>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

const int MAXN = 2555;

inline int fab(const int x) {
	return x < 0 ? -x : x;
}

struct node {
	int x;
	int y;
	int seed;
	node(int x=0, int y=0, int seed=0):x(x), y(y), seed(seed) {}
	int dis(const node &a) {
		return fab(x - a.x) + fab(y - a.y);
	}
} p[MAXN];

bool cmp(const node &a, const node &b) {
	return a.seed > b.seed;
}

int main() {
	int m, n;
	int i, j, k;
	int tc, r, s, t;
	//freopen("f:\\in.txt", "r", stdin);
	scanf("%d", &tc);
	while (tc--) {
		scanf("%d %d %d", &m, &n, &t);
		k = 1;
		for (i=0; i<m; ++i) {
			for (j=0; j<n; ++j) {
				scanf("%d", &s);
				p[k].x = i, p[k].y = j, p[k].seed = s;
				++k;
			}
		}
		sort(p+1, p+k, cmp);
		p[0].x = 0, p[0].y = p[1].y, p[0].seed = 0;
		r = 0, t -= 2;
		for (i=1; i<k; ++i) {
			if (t <= p[i].dis(p[i-1]) + p[i].x) break;
			r += p[i].seed;
			t -= p[i].dis(p[i-1]) + 1;
		}
		printf("%d\n", r);
	}
	return 0;
}