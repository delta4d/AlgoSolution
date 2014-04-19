#include <queue>
#include <cstdio>
#include <vector>
#include <cstring>
#include <algorithm>
using namespace std;

const int INF = 0x3f3f3f3f;
const int N = 50000 + 86;

queue <int> q;
vector <int> e[N], o;
int d[N], st, ed, n;
bool ok[N];

void read() {
	scanf("%d", &n);
	for (int i=0; i<n; ++i) scanf("%d", d+i), --d[i];
	for (int i=0; i<N; ++i) e[i].clear();
	for (int i=0; i+1<n; ++i) e[d[i]].push_back(d[i+1]), e[d[i+1]].push_back(d[i]);
	st = d[0], ed = d[n-1];
}

void bfs() {
	memset(d, 0xff, sizeof(d));
	while (!q.empty()) q.pop();
	q.push(st), d[st] = 0;
	while (!q.empty()) {
		int t = q.front(); q.pop();
		for (int i=0; i<(int)e[t].size(); ++i) {
			int s = e[t][i];
			if (d[s] != -1) continue;
			d[s] = d[t] + 1;
			q.push(s);
		}
	}
}

void back() {
	memset(ok, false, sizeof(ok));
	while (!q.empty()) q.pop();
	q.push(ed), ok[ed] = true;
	while (!q.empty()) {
		int t = q.front(); q.pop();
		for (int i=0; i<(int)e[t].size(); ++i) {
			int s = e[t][i];
			if (!ok[s] && d[s] + 1 == d[t]) {
				ok[s] = true;
				q.push(s);
			}
		}
	}
}

void path() {
	o.clear();
	o.push_back(st);
	for (int i=1; i<d[ed]; ++i) {
		int p = o[i-1], mn = INF;
		for (int j=0; j<(int)e[p].size(); ++j) {
			int c = e[p][j];
			if (ok[c] && d[c] == i && c < mn) mn = c; 
		}
		o.push_back(mn);
	}
	o.push_back(ed);
}

int main() {
	int tc, cn = 0;
	for (scanf("%d", &tc); tc--; ) {
		read(), bfs(), back(), path();
		printf("Case %d:\n", ++cn);
		for (int m=o.size(),i=0; i<m; ++i) printf("%d%s", o[i]+1, i==m-1?"\n":" ");
	}
	return 0;
}

// 308271	2014-01-06 21:34:12	 1271 - Better Tour	 C++	 0.312	 6080	Accepted
