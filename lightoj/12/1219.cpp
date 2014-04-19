#include <cmath>
#include <queue>
#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;

const int N = 10000 + 86;

vector <int> e[N], cc;
bool v[N];
int d[N], x[N];

struct node {
	int t;
	node(int _t=0):t(_t) {}
	inline bool operator<(const node &a) const {
		return d[t] > d[a.t];
	}
};

priority_queue <node> q;

template <class T> inline T fastin() {
	register char c = 0;
	register T a = 0;
	while (c < '0' || c > '9') c = getchar();
	while ('0' <= c && c <= '9') a = a * 10 + c - '0', c = getchar();
	return a;
}

int main() {
	int tc, cn = 0, n;
	for (tc=fastin<int>(); tc--; ) {
		int tot = 0;
		n = fastin<int>();
		fill(v, v+n, false);
		fill(d, d+n, 0);
		for (int i=0; i<n; ++i) e[i].clear();
		for (int i=0,a,m; i<n; ++i) {
			a = fastin<int>() - 1, x[i] = fastin<int>(), m = fastin<int>();
			for (int j=0,b; j<m; ++j) {
				b = fastin<int>() - 1;
				e[a].push_back(b), e[b].push_back(a);
				++d[a], ++d[b];
			}
		}
		while (!q.empty()) q.pop();
		for (int i=0; i<n; ++i) q.push(node(i));
		while (!q.empty()) {
			int t = q.top().t;
			q.pop();
			v[t] = true;
			for (int i=0; i<(int)e[t].size(); ++i) {
				int c = e[t][i];
				if (v[c]) continue;
				x[c] -= 1 - x[t], tot += abs(1 - x[t]), x[t] = 1, --d[c];
				break;
			}
		}
		printf("Case %d: %d\n", ++cn, tot);
	}
	return 0;
}

// 279419	2013-10-27 20:49:29	 1219 - Mafia	 C++	 0.008	 1968	Accepted
