#include <set>
#include <cstdio>
#include <algorithm>
using namespace std;

using ll = long long;
using segs = set <pair <int, int>>;
int const N = 18;
int const NN = 1e5 + 10;
int const INF = 0x3f3f3f3f;
segs s[N];
int a[NN];
ll tot;

inline int ith(int x, int i) { return !!(x & 1 << i); }

void gao(segs &s, int pw, int p, int v) {
	if (v) {
		if (s.empty()) {
			tot += pw;
			s.insert(make_pair(p, p));
			return;
		}
		int xi = -10, yi = -10, xp = -10, yp = -10;
		auto it = s.upper_bound(make_pair(p, INF)), pt = end(s);
		if (it != end(s)) xi = it->first, yi = it->second;
		if (it != begin(s)) pt = prev(it);
		if (it != begin(s)) xp = pt->first, yp = pt->second;
		if (xi <= p && p <= yi || xp <= p && p <= yp) return;
		int a = yp - xp + 1, b = yi - xi + 1;
		if (yp + 1 == p) {
			if (p + 1 == xi) {
				tot -= ((ll)a * (a + 1) / 2 + (ll)b * (b + 1) / 2) * pw;
				tot += (ll)(a + b + 1) * (a + b + 2) / 2 * pw;
				s.erase(it), s.erase(pt);
				s.insert(make_pair(xp, yi));
			} else {
				tot += (a + 1) * pw;
				s.erase(pt);
				s.insert(make_pair(xp, p));
			}
		} else if (p + 1 == xi) {
			tot += (b + 1) * pw;
			s.erase(it);
			s.insert(make_pair(p, yi));
		} else {
			tot += pw;
			s.insert(make_pair(p, p));
		}
		return;
	}
	if (s.empty()) return;
	auto it = s.upper_bound(make_pair(p, INF));
	if (it == begin(s)) return;
	auto pt = prev(it);
	if (pt->second < p) return;
	if (pt->first <= p) {
		int x = pt->first, y = pt->second;
		int a = p - x, b = y - p, c = y - x + 1;
		tot -= (ll)c * (c + 1) / 2 * pw;
		tot += ((ll)a * (a + 1) / 2 + (ll)b * (b + 1) / 2) * pw;
		s.erase(pt);
		if (x <= p - 1) s.insert(make_pair(x, p-1));
		if (p + 1 <= y) s.insert(make_pair(p+1, y));
	}
}

void info() {
	for (int i=0; i<3; ++i) {
		printf("%d: ", i);
		for (auto &p: s[i]) printf("[%d, %d]", p.first, p.second);
		puts("");
	}
	puts("============================");
}

ll gao(int p, int v) {
	for (int i=0; i<N; ++i) gao(s[i], 1<<i, p, ith(v, i));
//	info();
	return tot;
}

int main() {
	int n, m;
	scanf("%d%d", &n, &m);
	for (int i=0; i<n; ++i) scanf("%d", a+i);
	for (int k=0; k<N; ++k) {
		for (int i=0,x=-1,y=-1; i<=n; ++i) {
			if (ith(a[i], k)) {
				if (x == -1) x = i;
				y = i;
			} else {
				if (x != -1) s[k].insert(make_pair(x, y)), tot += (ll)(y-x+1)*(y-x+2)/2*(1<<k);
				x = -1, y = -1;
			}
		}
	}
	for (int p,v; m--; ) {
		scanf("%d%d", &p, &v), --p;
		printf("%I64d\n", gao(p, v));
	}
	return 0;
}

// 6562756	 May 6, 2014 5:44:20 PM	delta_4d	 E - Inna and Binary Logic	 GNU C++0x	Accepted	 1279 ms	 13800 KB
