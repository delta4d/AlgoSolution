#include <map>
#include <cstdio>
#include <vector>
#include <cstring>
#include <algorithm>
using namespace std;

map <long long, int> f1, f2;
int m, n;
int a[32][32];
int out[32], v[32];
vector <int> x[32];

inline void init() {
	f1.clear();
	f2.clear();
	for (int i=0; i<32; ++i) x[i].clear();
}

void dfs(int d, const int src, const int dst, map <long long, int> &f) {
	if (d == dst + 1) {
		long long s(0);
		for (int i=0; i<m; ++i) s = (s << 2) + v[i];
		if (f.count(s)) ++f[s];
		else f[s] = 1;
		return;
	}
	for (int i=0; i<x[d].size(); ++i) {
		out[d] = x[d][i];
		for (int j=0; j<m; ++j) v[j] ^= (a[j][d] * out[d]);
		dfs(d+1, src, dst, f);
		for (int j=0; j<m; ++j) v[j] ^= (a[j][d] * out[d]);
	}
}

long long gao() {
	long long ret(0);
	memset(v, 0, sizeof(v));
	dfs(0, 0, n/2-1, f1);
	dfs(n/2, n/2, n-1, f2);
	if (f1.empty()) {
		if (f2.empty() || !f2.count(0)) return 0;
		if (f2.count(0)) return f2[0];
	}
	if (f2.empty()) {
		if (f1.empty() || !f1.count(0)) return 0;
		if (f1.count(0)) return f1[0];
	}
	for (map<long long, int>::iterator it=f1.begin(); it!=f1.end(); ++it) {
		map<long long, int>::iterator jt = f2.find(it->first);
		if (jt == f2.end()) continue;
		ret += 1LL * (it->second) * (jt->second);
	}
	return ret;
}

int main() {
	int i, j, k;
	int tc;
	
//	freopen("in.txt", "r", stdin);
	scanf("%d", &tc);
	while (tc--) {
		init();
		scanf("%d %d", &m, &n);
		for (i=0; i<m; ++i) for (j=0; j<n; ++j) scanf("%d", a[i]+j);
		for (i=0; i<n; ++i) {
			scanf("%d", &k);
			x[i].resize(k);
			for (j=0; j<k; ++j) scanf("%d", &x[i][j]);
		}
		printf("%I64d\n", gao());
	}
	return 0;
}