#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;

const int INF = 0x3f3f3f3f;
vector <pair<int, int> > seg;
vector <int> d;

int main() {
	int n;

	scanf("%d", &n);
	for (int i=0,a,b; i<n; ++i) {
		scanf("%d%d", &a, &b);
		if (a > b) swap(a, b);
		seg.push_back(make_pair(a, b));
	}
	sort(begin(seg), end(seg));
	seg.push_back(make_pair(1, -1));
	int tot = 0, a = -INF, b = INF;
	for (auto &s: seg) {
		int mx = max(a, s.first), mn = min(b, s.second);
		if (mn < mx) d.push_back((a+b)>>1), a = s.first, b = s.second, ++tot;
		else a = mx, b = mn;
	}
	printf("%d\n", tot);
	for (auto &x: d) printf("%d\n", x);

	return 0;
}

// 4026241	 Jul 5, 2013 2:07:10 PM	delta_4d	 D - Segments	 GNU C++0x	Accepted	 15 ms	 0 KB
