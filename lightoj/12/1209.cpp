#include <cstdio>
#include <vector>
#include <cstring>
#include <algorithm>
using namespace std;

const int MAXN = 500;

vector <int> e[MAXN];
bool v[MAXN];
int mx[MAXN], my[MAXN];
char s1[80], s2[80];
vector <pair<int, int> > m, f;

bool dfs(int x) {
	for (int i=(int)e[x].size()-1; i>=0; --i) {
		int y = e[x][i];
		if (v[y]) continue;
		v[y] = true;
		if (my[y] == -1 || dfs(my[y])) {
			mx[x] = y, my[y] = x;
			return true;
		}
	}
	return false;
}

int Hungarian(int n) {
	int ret = 0;
	memset(mx, -1, sizeof(mx));
	memset(my, -1, sizeof(my));
	for (int i=0; i<n; ++i) {
		memset(v, false, sizeof(v));
		ret += dfs(i);
	}
	return ret;
}

int main() {
	int tc, cn = 0, v;
	for (scanf("%d", &tc); tc--; ) {
		m.clear(), f.clear();
		for (int i=0; i<MAXN; ++i) e[i].clear();
		scanf("%*d%*d%d", &v);
		for (int i=0,a,b; i<v; ++i) {
			scanf("%s%s", s1, s2);
			sscanf(s1+1, "%d", &a);
			sscanf(s2+1, "%d", &b);
			if (s1[0] == 'M') m.push_back(make_pair(a, b));
			else f.push_back(make_pair(a, b));
		}
		int cm = (int)m.size(), cf = (int)f.size();
		for (int i=0; i<cm; ++i) for (int j=0; j<cf; ++j) {
			if (m[i].first == f[j].second || m[i].second == f[j].first) {
				e[i].push_back(j);
			}
		}
		printf("Case %d: %d\n", ++cn, cm+cf-Hungarian(cm));
	}
	return 0;
}

// 321591	2014-02-08 15:49:28	 1209 - Strange Voting	 C++	 0.016	 1496	Accepted
