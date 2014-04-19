#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;

vector <pair<int, int> > e[111];
int x[2];

void gao(int r, int p) {
	if (r == 0 && p != -1) return;
	for (int i=0; i<(int)e[r].size(); ++i) {
		int c = e[r][i].first, w = e[r][i].second;
		if (c == p) continue;
		x[w<0] += w < 0 ? -w : w;
//		printf("== %d -> %d cost: %d\n", r, c, w);
		gao(c, r);
		break;
	}
}

int main() {
	int tc, cn = 0, n;
	for (scanf("%d", &tc); tc--; ) {
		scanf("%d", &n);
		for (int i=0; i<n; ++i) e[i].clear();
		for (int i=0,a,b,c; i<n; ++i) {
			scanf("%d%d%d", &a, &b, &c), --a, --b;
			e[a].push_back(make_pair(b, c));
			e[b].push_back(make_pair(a, -c));
		}
		x[0] = x[1] = 0;
		gao(0, -1);
		printf("Case %d: %d\n", ++cn, min(x[0], x[1]));
	}
	return 0;
}

// 307688	2014-01-05 14:33:12	 1049 - One Way Roads	 C++	 0.004	 1216	Accepted
