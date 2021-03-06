#include <cmath>
#include <cstdio>
#include <cstring>
#include <iomanip>
#include <iostream>
#include <algorithm>
using namespace std;

#define MP(x, y) make_pair((x), (y))
typedef long long LL;
typedef long double LD;
typedef pair <LD, LD> PDD;

const int MAXN = 1086;
const int MAXT = 1586;
const LL R = 1000000;

struct problem {
	LL ts, tl; 
	LD ss, sl, p;

	problem() {}
	problem(LD _ss, LD _sl, LL _ts, LL _tl, LD _p):\
		ss(_ss), sl(_sl), ts(_ts), tl(_tl), p(_p) {}
	void _read() {
		cin >> ss >> sl >> ts >> tl >> p;
		ss *= R, sl *= R;
	}
} pb[MAXN];

PDD dp[MAXN][MAXT];

inline bool cmp(const problem &a, const problem &b) {
	return a.tl * (1 - b.p) * a.p < b.tl * (1 - a.p) * b.p;
}

void update(PDD &a, PDD b) {
	if (b.first > a.first || a.first == b.first && a.second > b.second) a = b;	
}

int main() {
	int i, j;
	int m, n;

	scanf("%d%d", &n, &m);
	for (i=0; i<n; ++i) pb[i]._read();
	sort(pb, pb+n, cmp);
	for (i=0; i<n; ++i) for (j=0; j<=m; ++j) dp[i][j].first = dp[i][j].second = -1;
	dp[0][0].first = dp[0][0].second = 0;
	for (i=0; i<n; ++i) {
		LL ts = pb[i].ts, tl = pb[i].tl; 
		LD ss = pb[i].ss, sl = pb[i].sl, p = pb[i].p;
		for (j=0; j<=m; ++j) if (dp[i][j].first != -1) {
			LD cs = dp[i][j].first, cp = dp[i][j].second;
			update(dp[i+1][j], dp[i][j]);
			if (j + ts <= m) update(dp[i+1][j+ts], PDD(cs+ss, cp+ts));
			if (j + ts + tl <= m) update(dp[i+1][j+ts+tl], PDD(cs+ss+(1-p)*sl, ts+(j+tl)*(1-p)+p*cp));
		}
	}
	PDD res(0, 0);
	for (i=0; i<=m; ++i) update(res, dp[n][i]);
	cout << setprecision(20) << res.first / R << ' ' << res.second << endl;

	return 0;
}

// 3257380	 Mar 6, 2013 10:43:43 AM	delta_4d	 277D - Google Code Jam	 GNU C++	Accepted	 156 ms	 40600 KB
