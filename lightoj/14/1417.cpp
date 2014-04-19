#include <cstdio>
#include <vector>
#include <cstring>
#include <algorithm>
using namespace std;

const int MAXN = 50000 + 86;
const int INF = 0x3f3f3f3f;

vector <int> e[MAXN];
int timestamp, num, tail;
int id[MAXN], dfn[MAXN], low[MAXN], st[MAXN];
bool instack[MAXN];

void dfs(int x) {
	instack[x] = true, st[tail++] = x;
	dfn[x] = low[x] = timestamp++;
	for (int i=(int)e[x].size()-1; i>=0; --i) {
		int y = e[x][i];
		if (instack[y]) low[x] = min(low[x], dfn[y]);
		if (dfn[y] == -1) {
			dfs(y);
			low[x] = min(low[x], low[y]);
		}
	}
	if (dfn[x] == low[x]) {
		id[x] = num, instack[x] = false;
		for (int i=st[--tail]; i!=x; instack[i]=false,id[i]=num,i=st[--tail]);
		++num;
	}
}

void tarjan(int n) {
	timestamp = 0, num = 0, tail = 0;
	memset(dfn, -1, sizeof(dfn));
	memset(instack, false, sizeof(instack));
	for (int i=0; i<n; ++i) if (dfn[i] == -1) dfs(i);
}

int mn[MAXN], tot[MAXN], cnt[MAXN];
vector <int> f[MAXN];
bool v[MAXN];
int vi[MAXN], vn;

void D(int x) {
	vi[x] = vn, cnt[x] = tot[x];
	for (int i=0,y; i<(int)f[x].size(); ++i) {
		y = f[x][i];
		if (vi[y] == -1) D(y);
		else if (vi[y] != vn) cnt[x] += cnt[y];
	}
}

int gao() {
	int mx = 0, idx = INF;
	memset(vi, -1, sizeof(vi));
	memset(cnt, 0, sizeof(cnt));
	vn = 0;
	for (int i=0; i<num; ++i) if (vi[i] == -1) {
		D(i);
		++vn;
		if (cnt[i] > mx) mx = cnt[i], idx = mn[i];
		else if (cnt[i] == mx) idx = min(idx, mn[i]);
	}
	return idx + 1;
}

int main() {
	int tc, cn = 0, n;
	for (scanf("%d", &tc); tc--; ) {
		scanf("%d", &n);
		for (int i=0; i<n; ++i) e[i].clear();
		for (int i=0,a,b; i<n; ++i) {
			scanf("%d%d", &a, &b), --a, --b;
			e[a].push_back(b);
		}
		tarjan(n);
		for (int i=0; i<num; ++i) f[i].clear();
		memset(mn, 0x3f, sizeof(mn));
		memset(tot, 0, sizeof(tot));
		for (int i=0; i<n; ++i) mn[id[i]] = min(mn[id[i]], i), ++tot[id[i]];
		for (int i=0; i<n; ++i) {
			int a = id[i];
			for (int j=0; j<(int)e[i].size(); ++j) {
				int b = id[e[i][j]];
				if (a == b) continue;
				f[a].push_back(b);
			}
		}
		printf("Case %d: %d\n", ++cn, gao());
	}
	return 0;
}

// 320383	2014-02-04 21:24:51	 1417 - Forwarding Emails	 C++	 0.200	 12044	Accepted
