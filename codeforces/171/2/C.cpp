#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;

const int MAXN = 100086;
const int INF = 0x3f3f3f3f;

struct node {
	int s, t;
	bool cc;
	node() {}
	node(int _s, int _t, bool _cc):s(_s), t(_t), cc(_cc) {}
};

int x[MAXN];
vector <node> seg;

int gao(const int x) {
	int left = 0, right = seg.size() - 1, mid;
	int tc = 32, ret;
	while (tc--) {
		mid = (left + right) >> 1;
		if (seg[mid].s <= x && x <= seg[mid].t) ret = mid;
		if (x <= seg[mid].s) right = mid - 1;
		if (x >= seg[mid].t) left = mid + 1;
	}
	return ret;
}

int main() {
	int m, n;
	int s, t;
	int cc;

	scanf("%d%d", &n, &m);
	if (n <= 3) {
		while (m--) puts("Yes");
		return 0;
	}
	for (int i=0; i<n; ++i) scanf("%d", x+i);
	s = t = 0, cc = x[0] < x[1] ? -1 : (x[0] > x[1] ? 1 : 0);
	for (int i=0; ; ) {
//		for (; i+1<n&&x[i]==x[i+1]; ++i);
		s = i;
		for (t=s; t+1<n&&x[t]<=x[t+1]; ++t); if (s != t) seg.push_back(node(s, i=t, true));
		if (s == t) { for (t=s; t+1<n&&x[t]>=x[t+1]; ++t); if (s != t) seg.push_back(node(s, i=t, false)); }
		if (i == n - 1) break;
	}	
//	for (int i=0; i<seg.size(); ++i) printf("[%d, %d]", seg[i].s, seg[i].t); puts("");
	while (m--) {
		scanf("%d%d", &s, &t);
		--s, --t;
		int a = gao(s), b = gao(t);
		if (a + 1 < seg.size() && x[s] == x[seg[a].t] && x[seg[a].t] == x[seg[a+1].s]) ++a;
		if (b > 0 && x[t] == x[seg[b].s] && x[seg[b].s] == x[seg[b-1].t]) --b;
//		printf("=== %d %d\n", a, b);
		if (b <= a || b - a == 1 && seg[a].cc) puts("Yes");
		else puts("No");
	}	

	return 0;
}

// 3265528	 Mar 8, 2013 3:38:49 PM	delta_4d	 279C - Ladder	 GNU C++	Accepted	 156 ms	 2700 KB
