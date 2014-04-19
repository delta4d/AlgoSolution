#include <set>
#include <queue>
#include <cstdio>
#include <vector>
#include <cstring>
#include <algorithm>
using namespace std;

const int MAXN = 1000 << 1;

vector <int> e[MAXN], f[MAXN];
int timestamp, num, tail;
int id[MAXN], dfn[MAXN], low[MAXN], st[MAXN];
bool instack[MAXN];
queue <int> q;
set <pair<int, int> > edge;
int color[MAXN], d[MAXN], opp[MAXN];
int a[5][3];
int n, m, k;
bool find_one;
vector <int> p;

template <class T> inline T fastin() {
	register char c = 0;
	register T a = 0;
	while (c < '0' || c > '9') c = getchar();
	while ('0' <= c && c <= '9') a = a * 10 + c - '0', c = getchar();
	return a;
}

void tarjan(int x) {
	instack[x] = true, st[tail++] = x;
	dfn[x] = low[x] = timestamp++;
	for (int i=(int)e[x].size()-1; i>=0; --i) {
		int y = e[x][i];
		if (instack[y]) low[x] = min(low[x], dfn[y]);
		if (dfn[y] == -1) {
			tarjan(y);
			low[x] = min(low[x], low[y]);
		}
	}
	if (dfn[x] == low[x]) {
		id[x] = num, instack[x] = false;
		for (int i=st[--tail]; i!=x; instack[i]=false,id[i]=num,i=st[--tail]);
		++num;
	}
}

void component(int n) {
	timestamp = 0, num = 0, tail = 0;
	memset(dfn, -1, sizeof(dfn));
	memset(instack, false, sizeof(instack));
	for (int i=0; i<n; ++i) if (dfn[i] == -1) tarjan(i);
}

void readin() {
	n = fastin<int>(), m = fastin<int>(), k = fastin<int>();
	for (int i=0,t,x,y; i<m; ++i) {
		t = fastin<int>(), x = fastin<int>() - 1, y = fastin<int>() - 1;
		if (t == 1) {
			e[x+n].push_back(y);
			e[y+n].push_back(x);
		} else if (t == 2) {
			e[x+n].push_back(y+n);
			e[y].push_back(x);
		} else if (t == 3) {
			e[x].push_back(y+n);
			e[y].push_back(x+n);
		} else if (t == 4) {
			e[x+n].push_back(y);
			e[y+n].push_back(x);
			e[x].push_back(y+n);
			e[y].push_back(x+n);
		} else {
			throw "type error!";
		}
	}
	for (int i=0,t; i<k; ++i) {
		scanf("%d%d%d%d", &t, a[i], a[i]+1, a[i]+2);
		--a[i][0], --a[i][1], --a[i][2];
		if (t == 2) a[i][0] += n, a[i][1] += n, a[i][2] += n;
	}
}

bool build_graph() {
	for (int i=0; i<n; ++i) {
		if (id[i] == id[i+n]) return false;
		opp[id[i]] = id[i+n], opp[id[i+n]] = id[i];
	}
	for (int i=0; i<num; ++i) f[i].clear();
	edge.clear();
	memset(d, 0, sizeof(d));
	for (int i=2*n-1; i>=0; --i) {
		int a = id[i];
		for (int j=(int)e[i].size()-1; j>=0; --j) {
			int b = id[e[i][j]];
			if (a == b || edge.find(make_pair(b, a)) != edge.end()) continue;
			++d[a];
			f[b].push_back(a);
			edge.insert(make_pair(b, a));
		}
	}
	return true;
}

bool gao() {
	component(n<<1);
	if (!build_graph()) return false;
	while (!q.empty()) q.pop();
	memset(color, -1, sizeof(color));
	for (int i=0; i<num; ++i) if (!d[i]) q.push(i);
	while (!q.empty()) {
		int t = q.front(); q.pop();
		if (color[t] != -1) continue;
		color[t] = 1, color[opp[t]] = 0;
		for (int i=(int)f[t].size()-1; i>=0; --i) {
			if (--d[f[t][i]] == 0) q.push(f[t][i]);
		}
	}
	p.clear();
	for (int i=0; i<n; ++i) if (color[id[i]] == 1) p.push_back(i+1);
	sort(p.begin(), p.end());
	return true;
}

#define R(x) ((x) < n ? ((x) + n) : ((x) - n))
void dfs(int dep) {
	if (find_one) return;
	if (dep == k) {
		find_one = find_one || gao();
		return;
	}
	for (int i=0; i<3; ++i) {
		int cc = a[dep][i];
		e[R(cc)].push_back(cc);
		dfs(dep+1);
		if (find_one) return;
		e[R(cc)].pop_back();
	}
}

int main() {
	int tc, cn = 0;
	for (tc=fastin<int>(); tc--; ) {
		for (int i=0; i<MAXN; ++i) e[i].clear();
		readin();
		printf("Case %d: ", ++cn);
		if (!gao()) { puts("Impossible."); continue; }
		find_one = false;
		dfs(0);
		if (!find_one) { puts("Impossible."); continue; }
		printf("Possible ");
		printf("%d", (int)p.size());
		for (int i=0; i<(int)p.size(); ++i) printf(" %d", p[i]);
		puts(".");
	}
	return 0;
}

// 320692	2014-02-05 23:01:19	 1407 - Explosion	 C++	 0.248	 1544	Accepted
