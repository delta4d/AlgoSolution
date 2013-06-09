#include <map>
#include <cstdio>
#include <algorithm>
using namespace std;

const int INF = 0x3f3f3f3f;
const int MAXN = 100000 + 86;

struct triple {
	int x, ymin, ymax;
	triple(int _x=0, int _ymin=INF, int _ymax=-INF):x(_x), ymin(_ymin), ymax(_ymax) {}
	void init(int _x=0, int _ymin=INF, int _ymax=-INF) { x = _x, ymin = _ymin, ymax = _ymax; }
} p[MAXN];
int sz = -1;
int fmn[MAXN], fmx[MAXN];
int bmn[MAXN], bmx[MAXN];

map <int, pair<int, int> > mp;

void init() {
	fmn[0] = p[0].ymin, fmx[0] = p[0].ymax;
	for (int i=1; i<=sz; ++i) fmn[i] = min(fmn[i-1], p[i].ymin), fmx[i] = max(fmx[i-1], p[i].ymax);
	bmn[sz] = p[sz].ymin, bmx[sz] = p[sz].ymax;
	for (int i=sz-1; i>=0; --i) bmn[i] = min(bmn[i+1], p[i].ymin), bmx[i] = max(bmx[i+1], p[i].ymax);
}

bool ok(double z) {
	z *= 2;
	for (int p1=0,p2=0; p1<=sz; ++p1) {
		for (; p2 <= sz && p[p2].x - p[p1].x <= z; ++p2); --p2;
		int mn = INF, mx = -INF;
		if (p1 > 0) mn = min(mn, fmn[p1-1]), mx = max(mx, fmx[p1-1]);
		if (p2 < sz) mn = min(mn, bmn[p2+1]), mx = max(mx, bmx[p2+1]);
		if (mx - mn <= z) return true;
	}
	return false;
}

int main() {
	int n;

	scanf("%d", &n);
	for (int i=0,tx,ty; i<n; ++i) {
		scanf("%d%d", &tx, &ty);
		int x = tx + ty, y = tx - ty;
		if (mp.count(x)) mp[x].first = min(mp[x].first, y), mp[x].second = max(mp[x].second, y);
		else mp[x] = make_pair(y, y);
	}
	for (map<int, pair<int,int> >::iterator it=mp.begin(); it!=mp.end(); ++it) {
		p[++sz].init(it->first, it->second.first, it->second.second);
	}
	init();
	int tc = 100;
	double left = 0, right = INF, mid;
	for (; tc--; ok(mid)?right=mid:left=mid) mid = (left + right) / 2.0;
	printf("%.16lf\n", mid);

	return 0;
}

// 3849439	 Jun 9, 2013 9:57:18 AM	delta_4d	 D - Sereja and Straight Lines	 GNU C++	Accepted	234 ms	6764 KB
