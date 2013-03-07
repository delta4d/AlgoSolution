#include <map>
#include <cstdio>
#include <vector>
#include <cstring>
#include <algorithm>
using namespace std;

typedef long long LL;

map <LL, LL> mp[2];
vector <LL> x[41], y[41];

LL gcd(LL x, LL y) {
	if (x < y) swap(x, y);
	LL z;
	while (y) z = x % y, x = y, y = z;
	return x;
}

LL lcm(LL x, LL y) {
	return x / gcd(x, y) * y;
}

void init() {
	LL i, j, k(0);
	x[1].push_back(1);
	y[1].push_back(1);
	mp[0][1] = 1;
	for (i=2; i<=40; ++i) {
		mp[1-k] = mp[k];
		if (mp[1-k].count(i)) ++mp[1-k][i]; else mp[1-k][i] = 1;
		for (map<LL, LL>::iterator it=mp[k].begin(); it!=mp[k].end(); ++it) {
			j = lcm(it->first, i);
			if (mp[1-k].count(j)) mp[1-k][j] += (it -> second);
			else mp[1-k][j] = (it -> second);
		}
		k = 1 - k;
		x[i].resize(mp[k].size());
		y[i].resize(mp[k].size());
		j = 0;
		for (map<LL, LL>::iterator it=mp[k].begin(); it!=mp[k].end(); ++it,++j) {
			x[i][j] = (it->first);
			y[i][j] = (it->second) + (j ? y[i][j-1] : 0);
		}
	}
//	for (i=0; i<x[10].size(); ++i) printf("%I64d %I64d\n", x[10][i], y[10][i]);
}

int main() {
	int i, j, k;
	LL m, n;
	int tc, cn(0);
	int left, right, mid, idx;
	LL tot;

//	freopen("in.txt", "r", stdin);
//	freopen("out.txt", "w", stdout);
	init();
	scanf("%d", &tc);	
	while (tc--) {
		scanf("%I64d %I64d", &n, &m);
		left = 0, right = x[n].size() - 1, idx = -1;
		while (left <= right) {
			mid = (left + right) >> 1;
			if (x[n][mid] < m) idx = mid, left = mid + 1;
			else right = mid - 1;
		}
		tot = idx == -1 ? y[n].back() : y[n].back() - y[n][idx];
		printf("Case #%d: %I64d\n", ++cn, tot);
	}
	return 0;
}