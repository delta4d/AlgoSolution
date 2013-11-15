#include <cmath>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

const double eps = 1e-6;
const double INF = 9999999999999.9;
const int MAXN = 5000;

double a[MAXN], b[MAXN];

struct segment {
	double s, t;
	void sset(double _s, double _t) {
		s = _s, t = _t;
	}
	void intersect(segment a) {
		s = max(s, a.s);
		t = min(t, a.t);
	}
	bool empty() {
		return s >= t;
	}
};

void deal(double k, double a, segment &ref) {
	if (fabs(k) < eps) {
		if (a <= 0) ref.sset(-INF, INF);
		else ref.sset(INF, -INF);
	} else if (k > 0) {
		ref.sset(a/k, INF);
	} else {
		ref.sset(-INF, a/k);
	}
}

int main() {
	int i, j, k;
	int m, n;
	int tc;
	int cnt;
	segment tt, temp;
	//freopen("f:\\in.txt", "r", stdin);
	scanf("%d", &tc);
	while (tc--) {
		scanf("%d", &n);
		for (i=0; i<n; ++i) scanf("%lf %lf", a+i, b+i);
		cnt = 0;
		for (i=0; i<n; ++i) {
			tt.sset(-INF, INF);
			for (j=0; j<n; ++j) {
				if (j == i) continue;
				deal(a[i]-a[j], b[j]-b[i], temp);
				tt.intersect(temp);
			}
			if (!tt.empty()) ++cnt;
		}
		printf("%d\n", cnt);
	}
	return 0;
}