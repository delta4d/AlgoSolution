#include <bits/stdc++.h>
using namespace std;

using ll = long long;

bool ok;
int p[8][3];
vector <ll> ds;
unordered_map <ll, int> mp;

inline ll sqr(ll const x) { return x * x; }
inline ll dist(int i, int j) { return sqr(p[i][0]-p[j][0]) + sqr(p[i][1]-p[j][1]) + sqr(p[i][2]-p[j][2]); }

bool cube() {
	vector <ll> d(begin(ds), end(ds)), dis, cnt;
	sort(begin(d), end(d));
	d.push_back(LLONG_MAX);
	for (int i=0,n=(int)d.size(),k=1; i+1<n; ++i) {
		if (d[i] != d[i+1]) dis.push_back(d[i]), cnt.push_back(k), k = 1;
		else ++k;
	}
	int sz = (int)dis.size();
	if (sz != 3) return false;
	if (dis[0] == 0 || dis[1] == 0 || dis[2] == 0) return false;
	return dis[1] == 2 * dis[0] && dis[2] == 3 * dis[0] && cnt[0] == 12 && cnt[1] == 12 && cnt[2] == 4;
}

bool gao(int d) {
	if (ok) return ok;
	if (d == 8) {
		if (cube()) return ok = true;
		return false;
	}
	do {
		for (int i=0; i<d; ++i) ds.push_back(dist(i,d)), ++mp[ds.back()];
		if ((int)mp.size() <= 3 && gao(d+1)) return true;
		for (int i=0; i<d; ++i) {
			if (--mp[ds.back()] == 0) mp.erase(ds.back());
			ds.pop_back();
		}
	} while (next_permutation(p[d], p[d]+3));
	return ok;
}

int main() {
	for (int i=0; i<8; ++i) scanf("%d%d%d", p[i], p[i]+1, p[i]+2), sort(p[i], p[i]+3);
	puts(gao(0)?"YES":"NO");
	if (ok) for (int i=0; i<8; ++i) printf("%d %d %d\n", p[i][0], p[i][1], p[i][2]);
	return 0;
}

// 7715078	2014-09-07 23:00:52	delta_4d	B - Restore Cube	GNU C++0x	Accepted	30 ms	200 KB
