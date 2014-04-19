#include <cstdio>
#include <vector>
#include <cstring>
#include <algorithm>
using namespace std;

const int MAXN = 20000 + 86;

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

int in[MAXN], out[MAXN];

int main() {
	int tc, cn = 0, n, m;
	for (scanf("%d", &tc); tc--; ) {
		scanf("%d%d", &n, &m);
		for (int i=0; i<n; ++i) e[i].clear();
		for (int a, b; m--; ) {
			scanf("%d%d", &a, &b), --a, --b;
			e[a].push_back(b);
		}
		printf("Case %d: ", ++cn);
		tarjan(n);
		if (num == 1) {
			printf("%d\n", 0);
			continue;
		}
		memset(in, 0, sizeof(in));
		memset(out, 0, sizeof(out));
		for (int i=0; i<n; ++i) for (int j=(int)e[i].size()-1; j>=0; --j) {
			int a = id[i], b = id[e[i][j]];
			if (a != b) ++out[a], ++in[b];
		}
		int c1 = 0, c2 = 0;
		for (int i=0; i<num; ++i) {
			if (in[i] == 0) ++c1;
			if (out[i] == 0) ++c2;
		}
		printf("%d\n", max(c1, c2));
	}
	return 0;
}

// 320358	2014-02-04 20:04:51	 1210 - Efficient Traffic System	 C++	 0.168	 4600	Accepted
