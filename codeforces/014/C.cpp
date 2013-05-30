#include <set>
#include <cstdio>
using namespace std;

int x[4], y[4];
int x1[4], y1[4], x2[4], y2[4];

bool ok(int a, int b) {
	for (int i=0; i<4; ++i) {
		if (x1[i] == x[a] && y1[i] == y[a] && x2[i] == x[b] && y2[i] == y[b]) return true;
	}
	return false;
}

int main() {
	set <pair<int, int> > p;

	for (int i=0; i<4; ++i) {
		scanf("%d%d%d%d", x1+i, y1+i, x2+i, y2+i);
		if (x1[i] != x2[i] && y1[i] != y2[i]) return puts("NO"), 0;
		if (x1[i] > x2[i]) swap(x1[i], x2[i]);
		if (y1[i] > y2[i]) swap(y1[i], y2[i]);
		p.insert(make_pair(x1[i], y1[i]));
		p.insert(make_pair(x2[i], y2[i]));
	}
	if (p.size() != 4) return puts("NO"), 0;
	int i = 0;
	for (set<pair<int,int> >::iterator it=p.begin(); it!=p.end(); ++it,++i) {
		x[i] = it->first, y[i] = it->second;
	}
	if (!ok(0, 1)) return puts("NO"), 0;
	if (!ok(0, 2)) return puts("NO"), 0;
	if (!ok(1, 3)) return puts("NO"), 0;
	if (!ok(2, 3)) return puts("NO"), 0;
	puts("YES");

	return 0;
}

// 3792913	 May 30, 2013 7:59:47 AM	delta_4d	 C - Four Segments	 GNU C++	Accepted	15 ms	0 KB
