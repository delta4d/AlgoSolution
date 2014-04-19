#include <cstdio>
#include <vector>
#include <cstring>
#include <algorithm>
using namespace std;

const int MAXN = 1e3;

#define ID(v) (lower_bound(p.begin(), p.end(), (v))-p.begin())

vector <int> p, e[MAXN];
int a[MAXN*10], b[MAXN*10], pn;
int timestamp, num, tail;
int id[MAXN], dfn[MAXN], low[MAXN], st[MAXN];
bool instack[MAXN];
int in[MAXN], out[MAXN];

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

int main() {
	int tc, cn = 0, n;
	for (scanf("%d", &tc); tc--; ) {
		p.clear(), pn = 0;
		scanf("%d", &n);
		for (int i=0,m,x,y; i<n; ++i) {
			for (scanf("%d", &m); m--; ) {
				scanf("%d%d", &x, &y);
				p.push_back(x), p.push_back(y);
				a[pn] = x, b[pn] = y, ++pn;
			}
		}
		printf("Case %d: ", ++cn);
		if (pn == 0) { puts("YES"); continue; }
		sort(p.begin(), p.end());
		p.erase(unique(p.begin(), p.end()), p.end());
		if (p[0] != 0) { puts("NO"); continue; }
		n = (int)p.size();
		for (int i=0; i<MAXN; ++i) e[i].clear();
		for (int i=0; i<pn; ++i) e[ID(a[i])].push_back(ID(b[i]));
		tarjan(n);
		if (num == 1) { puts("YES"); continue; }
		memset(in, 0, sizeof(in));
		memset(out, 0, sizeof(out));
		for (int i=0; i<n; ++i) for (int j=0; j<(int)e[i].size(); ++j) {
			int x = id[i], y = id[e[i][j]];
			if (x != y) ++in[y], ++out[x];
		}
		int c[3] = {0};
		for (int i=0; i<num; ++i) {
			if (in[i] == 0 && out[i] == 1) ++c[0];
			else if (in[i] == 1 && out[i] == 1) ++c[1];
			else if (in[i] == 1 && out[i] == 0) ++c[2];
		}
		if (c[0] != 1 || c[2] != 1 || c[0] + c[1] + c[2] != num) { puts("NO"); continue; }
		if (in[id[0]] != 0 || out[id[0]] != 1) { puts("NO"); continue; }
		puts("YES");
	}
	return 0;
}

// 320618	2014-02-05 15:12:05	 1168 - Wishing Snake	 C++	 0.128	 1476	Accepted
