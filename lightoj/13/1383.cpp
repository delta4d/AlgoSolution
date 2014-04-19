#include <cmath>
#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;

#define all(x) (x).begin(), (x).end()
typedef pair <int, int> segment;
const int MAXN = 10000 + 86;
const int INF = 0x3f3f3f3f;
int K, N, S, D;
int x[MAXN], y[MAXN];
vector <segment> seg;

template <class T> inline T fastin() {
	register char c = 0;
	register T a = 0;
	T sgn = 1;
	while (c < '0' || c > '9') {
		c = getchar();
		if (c == '-') sgn = -1;
	}
	while ('0' <= c && c <= '9') a = a * 10 + c - '0', c = getchar();
	return sgn * a;
}

bool ok(int y0) {
	seg.clear();
	for (int i=0; i<N; ++i) {
		int d = y[i] - y0;
		double off = sqrt(double(D + d) * double(D - d));
		seg.push_back(make_pair((int)ceil(x[i]-off), (int)floor(x[i]+off)));
	}
	sort(all(seg));
	int cc = 0, l = -INF, r = INF;
	for (int i=0; i<N; ++i) {
		l = max(l, seg[i].first), r = min(r, seg[i].second);
		if (l > r) ++cc, l = seg[i].first, r = seg[i].second;
	}
	return cc + 1 <= S;
}

int main() {
	int tc, cn = 0;
	for (tc=fastin<int>(); tc--; ) {
		K = fastin<int>(), N = fastin<int>(), S = fastin<int>(), D = fastin<int>();
		int left = 0, right = 0, mid, d = 1;
		for (int i=0; i<N; ++i) x[i] = fastin<int>(), y[i] = fastin<int>(), left = max(left, y[i]-=K);
		left -= D;
		while (left <= right) {
			mid = left + (right - left) / 2;
			if (ok(mid)) right = mid - 1, d = mid;
			else left = mid + 1;
		}
		printf("Case %d: ", ++cn);
		if (d > 0) puts("impossible");
		else printf("%d\n", -d);
	}
	return 0;
}

// 260532	2013-09-08 17:31:07	 1383 - Underwater Snipers	 C++	 0.196	 1436	Accepted
