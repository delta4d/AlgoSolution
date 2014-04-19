#include <set>
#include <queue>
#include <cstdio>
#include <vector>
#include <cstring>
#include <algorithm>
using namespace std;

const int MAXN = 8000 << 1;

vector <int> e[MAXN], f[MAXN];
int timestamp, num, tail;
int id[MAXN], dfn[MAXN], low[MAXN], st[MAXN];
bool instack[MAXN];
int opp[MAXN], color[MAXN], d[MAXN];
queue <int> q;
vector <int> p;
set <pair<int, int> > edge;

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

bool ok(int m) {
	for (int i=0; i<m; ++i) {
		if (id[i] == id[i+m]) return false;
		opp[id[i]] = id[i+m], opp[id[i+m]] = id[i];
	}
	edge.clear();
	memset(d, 0, sizeof(d));
	m <<= 1;
	for (int i=0; i<m; ++i) {
		int a = id[i];
		for (int j=0; j<(int)e[i].size(); ++j) {
			int b = id[e[i][j]];
			if (a == b) continue;
			if (edge.find(make_pair(b, a)) != edge.end()) continue;
			f[b].push_back(a);
			++d[a];
			edge.insert(make_pair(b, a));
		}
	}
	return true;
}

void tsort() {
	memset(color, -1, sizeof(color));
	while (!q.empty()) q.pop();
	for (int i=0; i<num; ++i) if (!d[i]) q.push(i);
	while (!q.empty()) {
		int t = q.front(); q.pop();
		if (color[t] != -1) continue;
		color[t] = 1, color[opp[t]] = 0;
		for (int i=0; i<(int)f[t].size(); ++i) {
			if (--d[f[t][i]] == 0) q.push(f[t][i]);
		}
	}
}

#define N(x) ((x) < 0 ? (-(x)-1+m) : ((x)-1))
#define R(x) ((x) < m ? ((x)+m) : ((x)-m))

int main() {
	int tc, cn = 0, n, m;
	for (scanf("%d", &tc); tc--; ) {
		scanf("%d%d", &n, &m);
		for (int i=0; i<2*m; ++i) e[i].clear(), f[i].clear();
		for (int i=0,a,b; i<n; ++i) {
			scanf("%d%d", &a, &b);
			a = N(a), b = N(b);
			e[R(a)].push_back(b);
			e[R(b)].push_back(a);
		}
		tarjan(m<<1);
		printf("Case %d: ", ++cn);
		if (!ok(m)) { puts("No"); continue; }
		tsort();
		p.clear();
		for (int i=0; i<m; ++i) if (color[id[i]] == 1) p.push_back(i+1);
		sort(p.begin(), p.end());
		puts("Yes");
		printf("%d", (int)p.size());
		for (int i=0; i<(int)p.size(); ++i) printf(" %d", p[i]); puts("");
	}
	return 0;
}

// 320663	2014-02-05 19:19:43	 1251 - Forming the Council	 C++	 0.088	 6400	Accepted
