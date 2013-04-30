#include <cstdio>
#include <vector>
#include <cstring>
#include <algorithm>
using namespace std;

const int MAXN = 64;
const int INF = 0x3f3f3f3f;

vector <int> f[MAXN];
vector <int> x[MAXN];
int d[MAXN], sz;
bool v[MAXN], v2[MAXN][2];
int e[MAXN];
vector <pair<int, int> > p;
vector <pair<int, int> > out;
int r[MAXN];

void dfs(int r, const int k) {
	v[r] = true;
	x[k].push_back(r);
	for (int i=0; i<f[r].size(); ++i) if (!v[f[r][i]]) dfs(f[r][i], k);
}

bool gao(const int k) {
	if (x[k].size() == 1) {
		int j = x[k][0];
		if (d[j] == 0) p.push_back(make_pair(j, j));
		return !d[j] || d[j] == 2 && sz == 1;
	}
	int c[2], sc = 0;
	for (int i=0; i<x[k].size(); ++i) if (d[x[k][i]] == 1) c[sc++] = x[k][i]; 
	if (sc != 2 && sz > 1) return false;
	if (c[0] > c[1]) swap(c[0], c[1]);	
	if (sc == 2) p.push_back(make_pair(c[0], c[1]));
	return true;
}

int get_root(int r) {
	return ::r[r] < 0 ? r : ::r[r] = get_root(::r[r]);		
}

bool merge(int x, int y) {
	int rx = get_root(x), ry = get_root(y);
	if (rx == ry) return false;
	if (r[rx] < r[ry]) r[rx] += r[ry], r[ry] = rx;
	else r[ry] += r[rx], r[rx] = ry;
	return true;
}

int getmn(int &k, int &f) {
	int mn = INF;
	for (int i=0; i<p.size(); ++i) {
		if (!v2[i][0] && p[i].first < mn) mn = p[i].first, k = i, f = 0;
		if (!v2[i][1] && p[i].second < mn) mn = p[i].second, k = i, f = 1;
	}
//	e[k] = true, v2[k][f] = true;
	return mn;
}

int main() {
	int n, m;
	int a, b;

	scanf("%d%d", &n, &m);
	while (m--) {
		scanf("%d%d", &a, &b);
		++d[a], ++d[b];
		if (d[a] > 2 || d[b] > 2) return puts("NO"), 0;
		f[a].push_back(b);
		f[b].push_back(a);
	}
	for (int i=1; i<=n; ++i) if (!v[i]) dfs(i, sz++);
	for (int i=0; i<sz; ++i) if (!gao(i)) return puts("NO"), 0;
	memset(r, -1, sizeof(r));
	int k, nk, i, ni, f, nf;
	for (int t=0; t<p.size(); ++t) {
		k = getmn(i, f); 	
		v2[i][f] = true;
		vector <pair<int,int> > cc;
		while (true) {
			nk = getmn(ni, nf);
			if (t == p.size() -1 || merge(i, ni)) break;
			v2[ni][nf] = true;
			cc.push_back(make_pair(ni, nf));
		}
		for (int i=0; i<cc.size(); ++i) v2[cc[i].first][cc[i].second] = false;
		v2[ni][nf] = true;
//		printf("== %d %d\n", k, nk);
		out.push_back(make_pair(k, nk));
	}
	puts("YES");
	printf("%d\n", out.size());
	sort(out.begin(), out.end());
	for (int i=0; i<out.size(); ++i) printf("%d %d\n", out[i].first, out[i].second);

	return 0;
}

// 3654255	 Apr 30, 2013 2:50:20 PM	delta_4d	 E - Interestring graph and Apples	 GNU C++	Accepted	15 ms	76 KB
