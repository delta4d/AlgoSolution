#include <cstdio>
#include <vector>
#include <cstring>
#include <algorithm>
using namespace std;

const int MAXN = 100000 + 86;
const int INF = 0x3f3f3f3f;

vector <int> e[MAXN];
char s[MAXN<<1];
int tot, sz[MAXN], mx[MAXN], cc, mn;
bool v[MAXN];

void _dfs(int r, int p) {
	++tot;
	for (int i=0; i<(int)e[r].size(); ++i) if (e[r][i] != p && !v[e[r][i]]) _dfs(e[r][i], r);
}

void dfs(int r, int p) {
	sz[r] = 1, mx[r] = 0;
	for (int i=0; i<(int)e[r].size(); ++i) {
		int c = e[r][i];
		if (c == p || v[c]) continue;
		dfs(c, r);
		mx[r] = max(mx[r], sz[c]);
		sz[r] += sz[c];
	}
	mx[r] = max(mx[r], tot - sz[r]);
	if (mx[r] < mn) mn = mx[r], cc = r;
}

void gao(int r, int p, int c) {
	tot = 0, cc = -1, mn = INF;
	_dfs(r, p);
	dfs(r, p);
	int ct = cc;
	v[ct] = true, s[ct*2] = c + 'A';
	for (int i=0; i<(int)e[ct].size(); ++i) if (!v[e[ct][i]]) gao(e[ct][i], r, c+1);
}

int main() {
	int n;

	scanf("%d", &n);
	for (int i=1,a,b; i<n; ++i) {
		scanf("%d%d", &a, &b), --a, --b;
		e[a].push_back(b);
		e[b].push_back(a);
	}
	memset(s, ' ', sizeof(s)); s[n<<1] = '\0';
	gao(0, -1, 0);
	puts(s);

	return 0;
}

// 3991923	 Jun 29, 2013 5:50:17 PM	delta_4d	 C - Ciel the Commander	 GNU C++	Accepted	 234 ms	 9800 KB
