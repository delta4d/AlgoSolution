#include <queue>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

const int N = 111;
const int INF = 0x3f3f3f3f;

int e[N][N], p[N];
queue <int> q;
bool v[N];

template <class T> inline T fastin() {
	register char c = 0;
	register T a = 0;
	while (c < '0' || c > '9') c = getchar();
	while ('0' <= c && c <= '9') a = a * 10 + c - '0', c = getchar();
	return a;
}

bool bfs(const int n, const int s, const int t) {
	memset(p, -1, sizeof(p));
	memset(v, false, sizeof(v));
	while (!q.empty()) q.pop();
	q.push(s);
	v[s] = true;
	while (!q.empty()) {
		int x = q.front();
		q.pop();
		for (int i=0; i<n; ++i) if (e[x][i] && !v[i]) {
			q.push(i);
			p[i] = x;
			v[i] = true;
			if (i == t) return true;
		}
	}
	return v[t];
}

int gao(const int n, const int s, const int t) {
	int ret = 0;
	while (true) {
		bool find_path = bfs(n, s, t);
		if (!find_path) return ret;
		int mn = INF, cc = t;
		while (cc != -1) {
			int nt = p[cc];
			if (nt != -1) mn = min(mn, e[nt][cc]);
			cc = nt;
		}
		cc = t;
		while (cc != -1) {
			int nt = p[cc];
			if (nt != -1) e[nt][cc] -= mn, e[cc][nt] += mn;
			cc = nt;
		}
		ret += mn;
	}
}

int main() {
	int tc, cn(0), n, c, s, t;
	for (tc=fastin<int>(); tc--; ) {
		n = fastin<int>(), s = fastin<int>() - 1, t = fastin<int>() - 1, c = fastin<int>();
		memset(e, 0, sizeof(e));
		for (int i=0,u,v,w; i<c; ++i) {
			u = fastin<int>() - 1, v = fastin<int>() - 1, w = fastin<int>();
			e[u][v] += w, e[v][u] += w;
		}
		printf("Case %d: %d\n", ++cn, gao(n, s, t));
	}
	return 0;
}

// 288947	2013-11-19 22:21:37	 1153 - Internet Bandwidth	 C++	 0.016	 1296	Accepted
