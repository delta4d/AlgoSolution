#include <cstdio>
#include <vector>
#include <cstring>
#include <algorithm>
using namespace std;

const int N = 30000 + 1;

vector <pair<int, int> > e[N];
int up[N], down[N][2], idx[N];

template <class T> inline T fastin() {
	register char c = 0;
	register T a = 0;
	while (c < '0' || c > '9') c = getchar();
	while ('0' <= c && c <= '9') a = a * 10 + c - '0', c = getchar();
	return a;
}

void _up(int r, int p, int w) {
	if (p == -1) up[r] = 0;
	else up[r] = w + max(up[p], (idx[p] == r ? down[p][1] : down[p][0]));
	for (int i=0; i<(int)e[r].size(); ++i) {
		int c = e[r][i].first, ww = e[r][i].second;
		if (c == p) continue;
		_up(c, r, ww);
	}
}

void _down(int r, int p) {
	down[r][0] = down[r][1] = 0;
	for (int i=0; i<(int)e[r].size(); ++i) {
		int c = e[r][i].first, w = e[r][i].second;
		if (c == p) continue;
		_down(c, r);
		int cc = down[c][0] + w;
		if (cc > down[r][0]) down[r][1] = down[r][0], down[r][0] = cc, idx[r] = c;
		else if (cc > down[r][1]) down[r][1] = cc;
	}
}

int main() {
	int tc, cn = 0, n;
	for (tc=fastin<int>(); tc--; ) {
		n = fastin<int>();
		for (int i=0; i<n; ++i) e[i].clear();
		for (int i=1,u,v,w; i<n; ++i) {
			u = fastin<int>(), v = fastin<int>(), w = fastin<int>();
			e[u].push_back(make_pair(v, w));
			e[v].push_back(make_pair(u, w));
		}
		_down(0, -1);
		_up(0, -1, 0);
//		for (int i=0; i<n; ++i) printf("%d == up: %d, down0 %d %d, down1 %d\n", i, up[i], down[i][0], idx[i], down[i][1]);
		printf("Case %d:\n", ++cn);
		for (int i=0; i<n; ++i) printf("%d\n", max(up[i], down[i][0]));
	}
	return 0;
}

// 305440	2013-12-28 21:51:46	 1257 - Farthest Nodes in a Tree (II)	 C++	 0.324	 6676	Accepted
